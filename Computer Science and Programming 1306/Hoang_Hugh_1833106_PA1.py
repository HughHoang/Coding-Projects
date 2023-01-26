"""
A module to draw cool shapes with the Turtle module.

"""
import turtle

"""
TASK 1: Geometric drawing
"""

# This section creates a window with a turtle in it
window = turtle.Screen()            # Create window
window.bgcolor("black")             # Set the color of the window
window.title("Turtle Graphics")          # Set the title of the window
myShape = turtle.Turtle()               # Create turtle
myShape.pencolor("white")               # Set pen color
myShape.speed(2)                  # Set speed to 2/10 so you can see what your turtle is doing in real time

# Create a star
for i in range(5):                 # Loop repeats 5 times to reflect 5 sides of star
    myShape.forward(50)             # Distance the turtle will move
    myShape.right(144)              # Degrees the turtle will rotate before next movement

# Create a square
myShape.penup()                   # Stop drawing
myShape.setpos(200, 200)            # Move the turtle
myShape.pendown()                     # Resume drawing
for i in range(4):                 # Loop repeats 4 times to reflect 4 sides of square
   #***************************************#
    myShape.forward(50)
    myShape.right(90)
    #***************************************#
    pass

# Create a a column of circles
myShape.penup()                   # Stop drawing
myShape.setpos(-200, -200)           # Move the turtle
myShape.left(90)                  # Rotate the turtle to face upwards (making a column, not a row)
myShape.pendown()                     # Resume drawing
for i in range(8):
   #***************************************#
    myShape.circle(20)
    myShape.penup()
    myShape.forward(45)
    myShape.pendown()
    #***************************************#
    pass

myShape.clear()

"""
TASK 2: Circle
"""

#***************************************#
myShape.penup()
myShape.forward(45)
myShape.pendown()
for i in range(360):
    myShape.forward (1)
    myShape.right(1)
#***************************************#

myShape.clear()  # Resets the window.

"""
TASK 3: Shrinking lines
"""

#***************************************#
line=500
verticaldistance=line/4
horizontaldistance=200
pensize=10
myShape.right(180)
for i in range(10):
    myShape.pensize(pensize)
    myShape.forward(line)
    myShape.left(180)
    myShape.forward(line)
    myShape.right(90)
    myShape.penup()
    myShape.forward(horizontaldistance)
    myShape.right(90)
    myShape.forward(verticaldistance)
    myShape.pendown()
    pensize=pensize/2
    line=line/2
    verticaldistance=line/4
    horizontaldistance=horizontaldistance/2

#***************************************#

myShape.clear()  # Resets the window.

"""
TASK 4: Equilateral triangles
"""

#***************************************#

myShape.left(90)
for i in range(4):
    myShape.forward(i * 50)
    for j in range(2):
        myShape.left(120)
        myShape.forward(i * 100)
    myShape.left(120)
    myShape.forward(i * 50)
    myShape.right(90)
    myShape.penup()
    myShape.forward(i+25)
    myShape.pendown()
    myShape.left(90)

#***************************************#
window.exitonclick()
turtle.done()  # Program is finished.

