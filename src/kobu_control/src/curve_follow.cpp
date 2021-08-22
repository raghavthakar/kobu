#include "ros/ros.h"
#include "kobu_control/MoveDistance.h"
#include <fstream>

int main(int argc, char **argv)
{
  geometry_msgs::Point target_point;

  std::string move_distance_service_name;
  move_distance_service_name.append("/");
  move_distance_service_name.append(argv[1]);
  move_distance_service_name.append("/move_distance");

  //File handling variables
  std::string csv_filename;
  // csv_filename.append("~/kobu/src/kobu_peano/");
  csv_filename.append(argv[1]);
  csv_filename.append("_path.csv");

  std::fstream csv_file;
  csv_file.open("~/kobu/src/kobu_control/src/robot1_path.csv", std::ios::in);

  // Read the Data from the file as String Vector
  std::vector<std::string> row;
  std::string line, word, temp;

  // Initialising rosnode
  ros::init(argc, argv, "move_distance_client");
  ros::NodeHandle n;

  ros::ServiceClient client = n.serviceClient
                    <kobu_control::MoveDistance>(move_distance_service_name);

  //Instantiate the service class
  kobu_control::MoveDistance srv;

  ROS_INFO("Before loop");
  while(true)
  {
      ROS_INFO("INSIDE");
      //clear the csv row
      row.clear();
      ROS_INFO("CLEARED");

      target_point.x=std::stod(row[0]);
      target_point.y=std::stod(row[1]);

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
      ROS_INFO("bruh");
  }
  ROS_INFO("bruh2");
  srv.request.target = target_point;

  //Call the actual service. returns true if succeeded
  // if (client.call(srv))
  // {
  //   ROS_INFO("Called the service, and done");
  // }
  // else
  // {
  //   ROS_ERROR("Failed to call service move_distance");
  //   return 1;
  // }

  return 0;
}
