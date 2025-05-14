#!/bin/bash


#i=1; printf -v i "%02d" $i ; echo $i

add_line_numbers()
{
   input_file="$1"
   #output_file="$2"
   temp_file=$(mktemp)

#echo "one is $1"
#echo "two is $2"
#echo "three is $3"

#echo "temp file is: $temp_file"

   i=1
   while read -r line; do
      printf -v i "%02d" $i
      echo "$i: $line"
      ((i++))
   done <  "$1" > "$temp_file"

   #This has to be done in separate loops for some reason.
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
   #output_file="$2"
   #echo "one is $1"
   #echo "two is $2"

   temp_file=$(mktemp)

   while read -r line; do
      #Delete everything before the colon, and the colon
      echo "${line#*:}" | xargs  #xargs removes extra whitespace after delete
   done < "$1" > "$temp_file"

   while read -r line; do
      echo "$line"
   done < "$temp_file" > "$1"

   echo "Line numbers removed and saved to $1"

}


selection="$1"
input_file="$2"
#output_files="$3"

#echo "one is $1"
#echo "two is $2"
#echo "three is $3"


case $selection in
   "add")
      add_line_numbers "$2"
      ;;
   "remove")
      remove_line_numbers "$2"
      ;;
   *)
      echo "Invalid option.  Use 'add' or 'remove'."
      exit 1
      ;;
esac
