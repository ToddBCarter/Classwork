#!/bin/bash


#
#This is the script to back up a file
#into the hidden directory, .backup,
#in the current directory.
#
# Usage:
#      
#   $./backup_A2.sh
#


#Check for the .backup directory.
#Just In Case.
#Also save the dir name for later use.
backupJIC=".backup"
mkdir -p "$backupJIC"

#This is to grab the current directory.
backItUp="."

#Grab a timestamp to create unique backup names.
timestamp=$(date "+%Y%m%d%H%M%S")

#The code will:
#   Step through each file in the directory.
#   Acquire the base name of the file path.
#   Check if the path is a file or a directory.
#   Append the timestamp by changing the file path.
#   Create a copy with the new filename in .backup.
for BIU in "$backItUp"/*; do
   if [ -e "${BIU}" ]; then

      base_BIU=$(basename "$BIU")

      if [ -f "${BIU}" ]; then

         #This takes the .backup directory, the base 
         #name of the file, and the timestamp to create 
         #a new file name.
         backupName="$backupJIC/${base_BIU}_$timestamp"

         #The file is then copied into .backup.
         cp "$BIU" "$backupName"

      elif [ -d "${BIU}" ]; then

         backupName="$backupJIC/${base_BIU}_$timestamp"

         cp -r "$BIU" "$backupName"

      fi
   else
      echo "Nothing found!"
   fi
done

