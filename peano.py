from turtle import *

def peano(level, length):
    if level == 0:
        forward(length)
    else:
        angle = 90

        peano(level-1, length/3)

        right(angle)
        peano(level-1, length/3)

        for _ in range(2):
            for _ in range(3):
                left(angle)
                peano(level-1, length/3)

            angle = -angle

        left(angle)
        peano(level-1, length/3)

# Starting position and angle to fill our window
penup()
goto(-220, 220)
pendown()
right(45)

peano(2, 600)

exitonclick()

