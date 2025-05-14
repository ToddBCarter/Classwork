#
# This is a simple program to create several different shapes from turtles
# It uses a single turtle to create a smiley face in different colors which
# then recursively shrink down.
#
# It then uses a pair of turtles to create an inscribed border..
#
# Todd Carter
# cart7982@vandals.uidaho.edu
# CS 212
# Assignment 1
# 1-23-2024
#

import turtle
from turtle import *
import math
import random

random.seed()

#
# This is a custom function to create a circle by drawing
# a polygon with a large number of sides using radians to find
# the side lengths.  Values to produce a "good" circle are used.
#
# Python Turtle does have a built-in circle command, but this was practice.
#
def makeCircle(turtle, radius):
    #This gives the angle needed to turn
    theta = 360/15
    #Each arc length is the distance covered by the turtle per forward move
    arc_len = 2*radius*math.sin(math.radians(theta/2))
    #The turn angle for the next arc is then theta/2
    turtle.left(theta/2)
    #Move the turtle the linear distance of the arc
    turtle.forward(arc_len)
    #Loop to complete the entire circle.
    for i in range(0, 30):
        turtle.left(theta/2)
        turtle.forward(arc_len)
    turtle.setheading(0)  #Reset the heading at the end for easier reuse of turtle.


#
# A function to draw a smiley face using a single turtle.
# This function uses the function makeCircle from above.
#
def makeSmiley(turtle, radius):
    loc = turtle.pos()  #Using the local coords to print smileys
    makeCircle(turtle, radius/5)  #First eye
    turtle.penup()
    turtle.goto(loc[0]+radius*2, loc[1])  #Move to location
    turtle.pendown()
    makeCircle(turtle, radius/5)  #2nd eye
    turtle.penup()
    turtle.goto(loc[0]-radius, loc[1]-radius)  #Arbitrary place to start mouth
    turtle.pendown()

    #This uses math to create a half-circle that serves as the mouth
    theta = 360/60
    arc_len = 2*radius*math.sin(math.radians(theta/2))
    turtle.left(-90)  
    turtle.forward(arc_len)
    for i in range(0, 60):
        turtle.left(theta/2)
        turtle.forward(arc_len)
    turtle.setheading(0)  #This resets the heading so more smileys can be made


#
# A function to randomly apply a color from a short list to a turtle.
#
def makeItColorful(turtle):
    colorOptions = ["red", "green", "yellow", "blue", "purple", "pink", "orange"]
    turtle.color(colorOptions[random.randrange(0,6)])


#
#This is a recursive function to create a layering of
#smileys of randomly chosen colors.
#
def fadeAway(turtle, radius):
    makeItColorful(turtle)  #Give the smileys a color
    makeSmiley(turtle, radius)  #Build the first smiley.
    loc = turtle.pos()
    if radius > 2:  #Stop once the smileys are far too small
        radius = radius/1.5  #These adjust settings for new smileys.
        turtle.penup()
        turtle.goto(loc[0]-radius-10, loc[1]-radius-5)
        turtle.pendown()
        fadeAway(turtle, radius)  #Recursive call to create more.
    else:
        pass


#
# This function draws a simple square inscribed with another square,
# using a pair of turtles in conjunction.
def drawBordered(turtle1, turtle2, len):
    turtle1.color("black")
    turtle2.color("black")
    for i in range(0, 4):
        turtle1.forward(len)
        turtle1.right(90)
    loc = turtle1.pos()    
    turtle2.penup()
    turtle2.goto(loc[0]+5,loc[1]-5)
    turtle2.pendown()
    for i in range(0, 4):
        turtle2.forward(len-10)
        turtle2.right(90)
    



#
# Main code block begins here.
#

t1 = Turtle()
t2 = Turtle()

#Reposition the turtle for easier viewing:
t1.penup()
t1.goto(-120,120)
t1.pendown()

#Draw smiley cascade:
fadeAway(t1, 50)

#Reposition turtle again for easier viewing:
t1.penup()
loc = t1.pos()
t1.goto(-250, 250)
t1.pendown()

#Draw the bordered square.
drawBordered(t1,t2,500)









