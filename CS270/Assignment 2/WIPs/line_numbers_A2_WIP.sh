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
   temp_file=$(mktemp)

   #This is the counter for the line number
   current_line_count=1
   
   #Find the total number of lines in the file.
   file_line_count=$(wc -l < "$1")
   
   #Find the number of digits in the number of lines of the file.
   file_line_count_digits=${#file_line_count}
   
   #Maximum upper limit of line numbers.
   #No way found for this to be dynamically applied.
   bashishdumb=9

   #The number of zeroes to be padded onto each line number.
   leading_zero_count=$((bashisdumb - file_line_count_digits))

     
   #This while loop uses redirection to simply write out
   #an advancing line number onto each line.
   while read -r line; do

      #Start by padding out line number with zeroes.
      printf -v line_count_padded "%09d" $current_line_count

      #Then truncate the length of each line number while appending it to the line.
      echo "${line_count_padded:leading_zero_count}: $line"

      ((current_line_count++))

   done <  "$1" > "$temp_file"


   #Since files can't redirect to themselves,
   #the temp file is then read back into the original file
   #in a separate loop.

   while read -r line; do      
      echo "$line"
   done < "$temp_file" > "$1"


   echo "Line numbers added and saved to $1"
}



remove_line_numbers()
{
   temp_file=$(mktemp)

   while read -r line; do
      #Delete everything before the colon, and the colon
      #xargs removes extra whitespace after delete
      echo "${line#*:}" | xargs  
   done < "$1" > "$temp_file"

   while read -r line; do
      echo "$line"
   done < "$temp_file" > "$1"

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
