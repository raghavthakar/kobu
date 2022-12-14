# Kobu

[![Build Status][travis-image]][travis-url]


Multibot extraterrestrial exploration using Peano's curve
![](header.png)

## Read the paper

## Watch it in Action
https://www.youtube.com/watch?v=NxmvM7g0AX4

## Prerequisites
- ROS (Tested on Melodic Morenia)
- Linux (Tested on Ubuntu 18.04)

## Installation

Linux:

```
cd /your_workspace/src/
git clone https://github.com/raghavthakar/kobu.git
cd ..
catkin_make
```

## Usage example
Before running the following, make sure to source the workspace
To run a single exploring robot:
```
roslaunch kobu_description gazebo.launch
```
This should spawn the robot, and then run:
```
rosrun kobu_control move_distance_server
```

To run the multi-robot system:
```
roslaunch kobu_description kobu_multibot.launch
```

To visualise the curve, 
Navigate to `src/kobu_peano/peano` or `src/kobu_peano/hilbert` and run `python3 peano.py` or `python3 hilbert.py`.


## Contributing

1. Fork it (<https://github.com/yourname/yourproject/fork>)
2. Create your feature branch (`git checkout -b feature/fooBar`)
3. Commit your changes (`git commit -am 'Add some fooBar'`)
4. Push to the branch (`git push origin feature/fooBar`)
5. Create a new Pull Request

<!-- Markdown link & img dfn's -->
[npm-image]: https://img.shields.io/npm/v/datadog-metrics.svg?style=flat-square
[npm-url]: https://npmjs.org/package/datadog-metrics
[npm-downloads]: https://img.shields.io/npm/dm/datadog-metrics.svg?style=flat-square
[travis-image]: https://img.shields.io/travis/dbader/node-datadog-metrics/master.svg?style=flat-square
[travis-url]: https://travis-ci.org/dbader/node-datadog-metrics
[wiki]: https://github.com/yourname/yourproject/wiki



