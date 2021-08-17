
#include "ros/ros.h"
#include "kobu_control/MoveDistance.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"
#include "tf/transform_datatypes.h"
#include "tf/LinearMath/Matrix3x3.h"
#include "std_msgs/Float64.h"
#include <string>
#include <cmath>

// linear velocity of the robot
#define BASE_LINEAR_VEL 0.15

const double KP=0.5;
const double DT=0.15;

class Mover
{
  ros::NodeHandle node_handle;
  std::string odom_topic="/kobu/odom";
  nav_msgs::OdometryConstPtr current_odom;
  ros::ServiceServer move_server;
  ros::Publisher twist_publisher;
  geometry_msgs::Twist twist_message;

  std::vector<double> getOrientation()
  {
    double roll, pitch, yaw;
    std::vector<double> angles;

    //Get the current odom data of the robot
    current_odom=ros::topic::waitForMessage<nav_msgs::Odometry>(odom_topic);

    // the incoming geometry_msgs::Quaternion is transformed to a tf::Quaterion
    tf::Quaternion quat;
    tf::quaternionMsgToTF(current_odom->pose.pose.orientation, quat);

    // the tf::Quaternion has a method to acess roll pitch and yaw
    tf::Matrix3x3(quat).getRPY(roll, pitch, yaw);

    angles.push_back(roll);
    angles.push_back(pitch);
    angles.push_back(yaw);

    return angles;
  }

  double getCurrentYaw()
  {
    double roll, pitch, yaw;

    //Get the current odom data of the robot
    current_odom=ros::topic::waitForMessage<nav_msgs::Odometry>(odom_topic);

    // the incoming geometry_msgs::Quaternion is transformed to a tf::Quaterion
    tf::Quaternion quat;
    tf::quaternionMsgToTF(current_odom->pose.pose.orientation, quat);

    // the tf::Quaternion has a method to acess roll pitch and yaw
    tf::Matrix3x3(quat).getRPY(roll, pitch, yaw);

    return yaw;
  }

  double distanceFrom(double target_x, double target_y)
  {
    return sqrt(pow(target_y-current_odom->pose.pose.position.y, 2)
              +pow(target_x-current_odom->pose.pose.position.x, 2));
  }

  double getAngleToTarget(double target_y, double current_y,
                          double target_x, double current_x)
  {
    //Find the angle to rotate to face target
    double angle_to_target = atan((target_y-current_y)/
                                  (target_x-current_x));

    if(target_x-current_x<=0)
      if(target_y-current_y>=0)
        angle_to_target+=3.14;
      else
        angle_to_target-=3.14;

    if(angle_to_target>3.14)
        angle_to_target-=3.14;
    else if(angle_to_target<-3.14)
        angle_to_target+=3.14;

    ROS_INFO("Returning");
    return angle_to_target;
  }

public:
  Mover()
  {
    move_server = node_handle.advertiseService("move_distance",
                                    &Mover::move, this);

    twist_publisher = node_handle.advertise
                      <geometry_msgs::Twist>("/kobu/cmd_vel", 10);


    //linear velocity will always be this
    twist_message.linear.x=BASE_LINEAR_VEL;
  }

  bool move(kobu_control::MoveDistance::Request &request,
            kobu_control::MoveDistance::Response &response)
  {
    ROS_INFO("Beofre calling");

    //Get the current odom data of the robot
    current_odom=ros::topic::waitForMessage<nav_msgs::Odometry>(odom_topic);

    double angle_to_target=getAngleToTarget(request.target.y, current_odom->
                                  pose.pose.position.y, request.target.x,
                                  current_odom->pose.pose.position.x);

    ROS_INFO("TARGET X: %f Y: %f", request.target.x, request.target.y);

    //linear velocity will always be this
    twist_message.linear.x=BASE_LINEAR_VEL;

    //Move the robot forwards till we reach the target
    while(fabs(distanceFrom(request.target.x, request.target.y))>0.1)
    {
        //Get the current odom data of the robot
        current_odom=ros::topic::waitForMessage<nav_msgs::Odometry>(odom_topic);

        double yaw_error= getAngleToTarget(request.target.y, current_odom->
                                      pose.pose.position.y, request.target.x,
                                      current_odom->pose.pose.position.x) - getCurrentYaw();

        // For angular controller
        double p_effort=yaw_error*KP;

        // Set the angular yaw
        twist_message.angular.z=p_effort;

        twist_publisher.publish(twist_message);
        ROS_INFO("DISTANCE TO TARGET: %f", distanceFrom(request.target.x, request.target.y));
        ROS_INFO("YAW ERROR: %f", yaw_error);
        ROS_INFO("P EFFORT: %f", p_effort);
    }

    //Stop the robot
    twist_message.angular.z=0;
    twist_message.linear.x=0;
    twist_publisher.publish(twist_message);

    return true;
  }
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "move_distance_server");
  Mover mover;
  ros::spin();
  return 0;
}
