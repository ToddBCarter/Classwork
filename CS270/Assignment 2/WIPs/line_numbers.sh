#!/bin/bash



add_line_numbers()
{
   input_file="$1"
   temp_file=$(mktemp)

   #This is the counter for the line number
   i=1
   while read -r line; do
      #This ensures a double-digit line number.
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
