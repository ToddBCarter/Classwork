#!/bin/bash

#
#The script to remove underscores and to
#change the extension of .JPEG files to 
#be .jpeg instead.
#
# Usage:
#
#   $./rename_file_A2.sh example_name_here.JPEG
#
#   example_name_here.JPEG 
#
#   becomes
#  
#   examplenamehere.jpeg
#


file="$1"

#Use basename to get the file name
fileName=$(basename "$file")

#Checks for .JPEG extension and converts it to .jpeg
if [[ $fileName == *.JPEG ]]; then
   newName="${fileName%.JPEG}.jpeg"
   echo "Suffix changed on: $fileName"
fi

#Remove the underscores
newName="${newName//_/}"

mv "$file" "$newName"
echo "Underscores removed from: $fileName"

