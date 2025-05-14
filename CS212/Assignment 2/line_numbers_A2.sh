#!/bin/bash

#
#This is the script to add and remove line numbers
#from a text file passed from the command line.
#
#
# Usage:
# 
#   $./line_numbers_A2.sh add <yourfilehere.txt>
#
#   $./line_numbers_A2.sh remove <yourfilehere.txt>
#
#
#The program will add more numbers for each use.
#
#Removal of line numbers is reliant on the delimiter ':'
#


add_line_numbers()
{
   input_file="$1"
   temp_file=$(mktemp)

   #This is the counter for the line number
   count=1
   while read -r line; do
      echo "$count: $line"
      ((i++))
   done <  "$1" > "$temp_file"

   #This has to be done in separate loops.
   #Target file has its contents deleted and file becomes
   #inaccessible if file is redirected to itself.
   while read -r line; do
      echo "$line"
   done < "$temp_file" > "$1"

   echo "Line numbers added and saved to $1"

}



remove_line_numbers()
{
   input_file="$1"
   temp_file=$(mktemp)

   while read -r line; do
      #Delete everything before the colon, and the colon
	  #xargs removes extra whitespace after delete
      echo "${line#*:}" | xargs  
   done < "$input_file" > "$temp_file"

   while read -r line; do
      echo "$line"
   done < "$temp_file" > "$input_file"

   echo "Line numbers removed and saved to $1"

}


selection="$1"

case $selection in
   "add")
      add_line_numbers "$2"
      ;;
   "remove")
      remove_line_numbers "$2"
      ;;
   *)
      echo "Invalid.  Use 'add' or 'remove' as an argument before the file."
      exit 1
      ;;
esac
