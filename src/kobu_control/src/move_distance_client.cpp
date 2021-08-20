#include "ros/ros.h"
#include "kobu_control/MoveDistance.h"

int main(int argc, char **argv)
{
  geometry_msgs::Point target_point;
  target_point.x=-10;
  target_point.y=3;

  std::string move_distance_service_name;
  move_distance_service_name.append("/");
  move_distance_service_name.append(argv[1]);
  move_distance_service_name.append("/move_distance");

  ros::init(argc, argv, "move_distance_client");
  ros::NodeHandle n;

  ros::ServiceClient client = n.serviceClient
                    <kobu_control::MoveDistance>(move_distance_service_name);

  //Instantiate the service class
  kobu_control::MoveDistance srv;

  //Inout the request value
  srv.request.target = target_point;

  //Call the actual service. returns true if succeeded
  if (client.call(srv))
  {
    ROS_INFO("Called the service, and done");
  }
  else
  {
    ROS_ERROR("Failed to call service move_distance");
    return 1;
  }

  target_point.x=10;
  target_point.y=3;

  //Inout the request value
  srv.request.target = target_point;

  //Call the actual service. returns true if succeeded
  if (client.call(srv))
  {
    ROS_INFO("Called the service, and done");
  }
  else
  {
    ROS_ERROR("Failed to call service move_distance");
    return 1;
  }

  target_point.x=6;
  target_point.y=6;

  //Inout the request value
  srv.request.target = target_point;

  //Call the actual service. returns true if succeeded
  if (client.call(srv))
  {
    ROS_INFO("Called the service, and done");
  }
  else
  {
    ROS_ERROR("Failed to call service move_distance");
    return 1;
  }

  return 0;
}
