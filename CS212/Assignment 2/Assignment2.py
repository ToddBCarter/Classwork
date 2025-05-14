##
## CS 212 - Assignment 2
## Todd Carter
## 1-30-2023
##
## This is a short program for finding the value
## of pi with an arbitrary amount of precision in
## two different ways.
##
## The first is the Archimedes method.
## The second is the Leibnitz method.
## For fun, a third is done using the Ramanujan-Sato method.
## 


import math

#
# Using the Archimedes formula:
#
#   pi = circumference / diameter = circumference / (2 * radius)
#
# Also somewhat cheating with the math library to find radians.
# Circumference is found as the sum of the sides of a polygon
# inscribed in a circle.

def archimethod(sides):
    radius = 1
    #beta = 360/sides
    #alpha = math.radians(beta/2)
    #half_s = radius*math.sin(alpha)
    #single_side = 2 * half_s
    #
    #As an exercise, the preceding code was put into a single line:
    circ = sides * 2 * radius * math.sin(math.radians((360/sides)/2))
    return (circ/(2*radius))


#
# Using the Leibnitz-based formula:
#
#   pi/4 = 1/1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 ... +/- 1/(2n+1)
#

def leibtastic(n):
    pi = 0
    neg = 1
    for i in range(0, n):
        iteration = 1 / ((2*i)+1)
        pi = pi + (iteration * neg)
        neg = -neg
    return (pi * 4)


#
# Just for fun, a third using the Ramanujan-Sato series formula:
#
#   Please look it up, Ramanujan was crazy.
#
# The algorithm breaks the series into two parts for... convenience.
#
# This method gives by far the most accurate result
# with the least iterations.

def ramanujan_Sato(k):
    pi = 0
    pre = (2*math.sqrt(2))/(99 ** 2)
    for i in range(0,k):
        itera = (math.factorial(4*i))/((math.factorial(i)) ** 4)
        pi = pi + (itera * (((26390 * i) + 1103)/(396 ** (4*i))))
    return (1/(pre * pi))
    

print("The Archimedes method with 10000 iterations: ", archimethod(10000))
print("The Leibnitz method with 10000 iterations: ", leibtastic(10000))
print("\nSome testing to show the accuracy of Ramanujan's method: ")

print("The Ramanujan-Sato method with 20 iterations: ", ramanujan_Sato(20))
print("The Ramanujan-Sato method with 5 iterations: ", ramanujan_Sato(5))
print("The Ramanujan-Sato method with 3 iterations: ", ramanujan_Sato(3))
print("The Ramanujan-Sato method with 2 iterations: ", ramanujan_Sato(2))






    
