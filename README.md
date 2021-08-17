# kobu
Multibot exploration using Peano's curve

### Test Waypoint Navigation
Make sure to build and source the workspace. Then, run:
`roslaunch kobu_description gazebo.launch`

This should spawn a robot in an emppty world. Next, run the server for making
the robot navigate to a waypoint using:
`rosrun kobu_control move_distance_server`

Waypoints have been hardcoded into `move_distance_client` which can be
run to visualise the same.
