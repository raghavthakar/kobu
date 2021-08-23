from turtle import *
import time
import csv

with open('robot1_hilbert.csv','w',newline='') as robot1_csv_file:
    robot1_writer=csv.writer(robot1_csv_file)

def hilbert(level, angle, step):

    # Input Parameters are numeric
    # Return Value: None
    if level == 0:
        forward(step)
        print(position()[0],position()[1])

        with open('robot1_hilbert.csv','a',newline='') as robot1_csv_file:
            robot1_writer=csv.writer(robot1_csv_file)
            robot1_writer.writerow([position()[0],position()[1]])
        
    else:
        right(angle)
        hilbert(level-1, -angle, step)

        forward(step)
        left(angle)
        hilbert(level-1, angle, step)

        forward(step)
        hilbert(level-1, angle, step)

        left(angle)
        forward(step)
        hilbert(level-1, -angle, step)
        right(angle)



penup()
goto(-100,100)
pendown()
right(-45)
size=200
level=4
    # For positioning turtle
hilbert(4,90,size/(2**level-1))
