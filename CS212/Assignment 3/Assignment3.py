#
# CS212 - Assignment 3
# Todd Carter
# cart7982@vandals.uidaho.edu
# 2-7-2024
#

import random
import string


#Uses slicing to reverse a string
def reverse_string(inp):
    reversed_string = inp[::-1]
    return reversed_string

#Uses replace() function to swap spaces for nothing
def remove_spaces(inp):
    no_spaces = inp.replace(" ","")
    return no_spaces

#Uses remove_spaces() and slicing to return a boolean value
def palindrome(inp):
    if remove_spaces(inp[::-1]) == inp:
        return True
    else:
        return False

#Uses string and random libraries to build randomized password string
def passwordize(num):
    all_symbols = string.ascii_letters + string.digits + string.punctuation
    password = ""
    for i in range(num):
        password = password + random.choice(all_symbols)
    return password

#Counts number of vowels of input string, returns total
def vowel_check(inp):
    vowels = ["a","e","i","o","u","A","E","I","O","U"]
    counter = 0
    for i in inp:
        if i in vowels:
            counter += 1
    return counter



#
#
# Main begins here
#

#String to be tested.
test = "Jargon jargon jargon jargon jargon"
print(test)

#Calling functions for reversing, removing spaces, and counting vowels
print("\nThe reversed string is: ", reverse_string(test))
print("Removing spaces: ", remove_spaces(test))
print("Vowel count of "+str(test)+" is: ", vowel_check(test), "\n")

#Using a list to test various strings for being palindromes
pali_test = [remove_spaces(test),"racecar","bullhorn","Timbuktu","rotavator","necromancer"]
for test in pali_test:
    print("Is "+str(test)+" a palindrome?: ", palindrome(test))

print("")

#Printing out a short scale of random passwords
for i in range(4,8):
    password = passwordize(i)
    print("Producing "+str(i)+" digit password: ", password)


