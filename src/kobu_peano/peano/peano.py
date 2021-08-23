from turtle import *
import time
import csv

DIVIDE_SCALE=20

# Clear the CSV file
with open('robot1_path.csv', 'w', newline='') as robot1_csv_file:
    robot1_writer = csv.writer(robot1_csv_file)

def peano_1(level, length):
    if level == 0:
        forward(length)
        # Display the position
        print(position()[0], position()[1])
        # Append position to CSV file
        with open('robot1_path.csv', 'a', newline='') as robot1_csv_file:
            robot1_writer = csv.writer(robot1_csv_file)
            robot1_writer.writerow([position()[0]/DIVIDE_SCALE, position()[1]/DIVIDE_SCALE])

    else:
        angle = -90
        peano_1(level-1, length/3)
        right(angle)
        peano_1(level-1, length/3)
        for _ in range(2):
            for _ in range(3):
                left(angle)
                peano_1(level-1, length/3)
            angle = -angle
        left(angle)
        peano_1(level-1, length/3)

# Starting position and angle to fill our window
penup()
goto(0, 0)
pendown()
right(-45)
peano_1(2, 300)

# Clear the CSV file
with open('robot2_path.csv', 'w', newline='') as robot2_csv_file:
    robot2_writer = csv.writer(robot2_csv_file)

def peano_2(level, length):
    if level == 0:
        forward(length)
        # Display the position
        print(position()[0], position()[1])
        # Append position to CSV file
        with open('robot2_path.csv', 'a', newline='') as robot2_csv_file:
            robot2_writer = csv.writer(robot2_csv_file)
            robot2_writer.writerow([position()[0]/DIVIDE_SCALE, position()[1]/DIVIDE_SCALE])

    else:
        angle = -90
        peano_2(level-1, length/3)
        right(angle)
        peano_2(level-1, length/3)
        for _ in range(2):
            for _ in range(3):
                left(angle)
                peano_2(level-1, length/3)
            angle = -angle
        left(angle)
        peano_2(level-1, length/3)

# Starting position and angle to fill our window
penup()
goto(0, 0)
pendown()
right(-90)
peano_2(2, 300)






















# Clear the CSV file
with open('robot3_path.csv', 'w', newline='') as robot3_csv_file:
    robot3_writer = csv.writer(robot3_csv_file)

def peano_3(level, length):
    if level == 0:
        forward(length)
        # Display the position
        print(position()[0], position()[1])
        # Append position to CSV file
        with open('robot3_path.csv', 'a', newline='') as robot3_csv_file:
            robot3_writer = csv.writer(robot3_csv_file)
            robot3_writer.writerow([position()[0]/DIVIDE_SCALE, position()[1]/DIVIDE_SCALE])

    else:
        angle = -90
        peano_3(level-1, length/3)
        right(angle)
        peano_3(level-1, length/3)
        for _ in range(2):
            for _ in range(3):
                left(angle)
                peano_3(level-1, length/3)
            angle = -angle
        left(angle)
        peano_3(level-1, length/3)

# Starting position and angle to fill our window
penup()
goto(0, 0)
pendown()
right(-90)
peano_3(2, 300)

# Clear the CSV file
with open('robot4_path.csv', 'w', newline='') as robot4_csv_file:
    robot4_writer = csv.writer(robot4_csv_file)

def peano_4(level, length):
    if level == 0:
        forward(length)
        # Display the position
        print(position()[0], position()[1])
        # Append position to CSV file
        with open('robot4_path.csv', 'a', newline='') as robot4_csv_file:
            robot4_writer = csv.writer(robot4_csv_file)
            robot4_writer.writerow([position()[0]/DIVIDE_SCALE, position()[1]/DIVIDE_SCALE])

    else:
        angle = -90
        peano_4(level-1, length/3)
        right(angle)
        peano_4(level-1, length/3)
        for _ in range(2):
            for _ in range(3):
                left(angle)
                peano_4(level-1, length/3)
            angle = -angle
        left(angle)
        peano_4(level-1, length/3)

# Starting position and angle to fill our window
penup()
goto(0, 0)
pendown()
right(-90)
peano_4(2, 300)
