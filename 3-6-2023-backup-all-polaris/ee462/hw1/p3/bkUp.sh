#!/usr/bin/env bash

# Nathan Nguyen 
# back up files by copying them to another temp directory and append the date to the end of the name of the file being copied or "backed up"

backupfile() {
    if [ ! -e "/tmp/$USER/" ]
    then
	mkdir "/tmp/$USER"
    fi
    
    cp "$1" "/tmp/$USER/$(basename "$1")_$(date +"%d%b%y_%H%M").bk" # $1 here is the first argument of this function, not the first argument of script

    if [ $? != 0 ]
    then
	echo "Backup/copy command failed. Quitting."
	exit 1
    fi
}



if [ $# != 1 ]
then
    echo "Incorrect number of arguments."
    exit 4
else
    if [ -d "$1" ]
    then
	echo "usage: ./bkUp.sh <pathToFile>. Quitting."
	exit 3        
    elif [ -e "$1" ]
    then
	backupfile "$1"  #this is how you pass the first argument of the script to the function as parameter
    else
	echo "$0: File $1 does not exist. Quitting."
        exit 5
    fi
fi


exit 0

