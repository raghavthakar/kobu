#!/usr/bin/env python
from __future__ import print_function
import sys
import rospy
import csv
from kobu_control.srv import *
from geometry_msgs.msg import Point, Pose

print("line 10")
rospy.init_node('curve_follow')
print("line 11")

namespace=sys.argv[1]
service_name='/'+namespace+'/move_distance'
print("line 15")

def moveTo(point):
    target_point=Point()
    print("line 19")
    target_point.x, target_point.y=float(point[0]), float(point[1])
    print("line 21")
    print(target_point.x, target_point.y)

    print("line 24")
    rospy.wait_for_service(service_name)
    print("line 26")
    print("Done waiting")
    move_distance_client=rospy.ServiceProxy(service_name, MoveDistance)
    print("line 26")
    result=move_distance_client(target_point)

# csv_filename='/home/raghav/kobu/src/kobu_peano/'+namespace+'_path.csv'
csv_filename='/home/gokul/kobu/src/kobu_peano/'+namespace+'_path.csv'
print(csv_filename)
try:
    print('36')
    with open(csv_filename, 'r') as csv_file:
        print('38')
        reader = csv.reader(csv_file, delimiter = ',')
        while(True):
            try:
                point=next(reader)
                moveTo(point)
            except:
                break
except:
    print("escrpt")
