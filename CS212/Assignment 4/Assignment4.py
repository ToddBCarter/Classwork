#
# CS212 - Assignment 4
# Todd Carter
# cart7982@vandals.uidaho.edu
# 2-9-2024
#

import turtle
from turtle import *
import random

#
#Function to draw polygons.
#
def poly(t,sides,len):
    for _ in range(sides):
        t.forward(len)
        t.right(360/sides)

#
#Function to draw the start and finish lines.
#
def drawStartFinish(lin, start_x, fin_x):
    t = Turtle()
    t.shape("blank")

    #Draw the finish line first (it is less elaborate than the start line):
    t.color((1,0,0))
    t.teleport(fin_x-10, -(lin/2))
    poly(t,4,10)
    t.forward(10)
    t.left(90)
    t.forward(lin+10)  #+10 to account for size of the squares.
    t.right(90)
    t.backward(10)
    poly(t,4,10)

    #Draw the starting line second:
    t.color((0,1,0))
    t.teleport(start_x, -(lin/2))    
    poly(t,4,10)
    t.forward(10)
    poly(t,4,10)
    t.left(90)
    t.forward(lin+10)
    t.right(90)
    t.backward(10)
    poly(t,4,10)
    t.forward(10)
    poly(t,4,10)

#
#Function to add to list of turtles and then place them at the start line.
#Returns the total number of turtles for use in the game loop.
#
def placeTurtles(turts, lin, start_x):
    num_turts = input("\nEnter the number of racers: \n")
    
    #Loop to create requested number of turtles.
    for _ in range(int(num_turts)):
        temp = Turtle()
        #random RGB
        temp.color(random.random(),random.random(),random.random())
        temp.shape("turtle")
        temp.speed(random.randint(5,10))  #random speed for fun
        temp.penup()
        turts.append(temp)

    #Find the distance between each starting turtle using the length of the
    #start line.
    dist = lin/int(num_turts)

    #This calculates the starting y position based on
    #the length of the start line, with a half interval
    #distance given from either end, then adds dist for each
    #additional turtle.
    for i in range(0, int(num_turts)):
        turts[i].teleport(start_x+35, (-(lin/2)+(dist/2)+(dist*i)))

    return num_turts

#
# Main begins here:
#
lin = 250  #Length of the start and finish line.
start_x = -300  #location of the starting line.
fin_x = 250  #Location of the finish line.
turts = []

#First draw the start and finish lines using a function:
drawStartFinish(lin, start_x, fin_x)

#Then pick and place the turtles:
num_turts = placeTurtles(turts, lin, start_x)

#
# The game loop:
#
guess = input("Guess which racer will win!  Enter a number, starting from 1 at the bottom!\n")
loc = turts[0].pos()  #Capture location of pole position turtle.
while loc[0] < fin_x:  #Loop continues until a turtle is past the finish line
    for i in range(0, int(num_turts)):
        #The index is used to ID the turtles for the win condition.
        turts[i].forward(random.randint(5,20))
        loc = turts[i].pos()
        if loc[0] >= fin_x:
            print("Racer "+str(i+1)+" wins the race!")
            if int(guess) == int(i+1):
                print("You guessed right! Congrats!")
            else:
                print("You guessed wrong.  Too bad!")
            break   
