#!/usr/bin/env bash

# file count: counts files inside a given directory. A directory is also a file yes?
# Nathan Nguyen



# WHAT does he mean by "it should print messages (in square brackets) about directories not being found???"


x=0

if [ $# = 0 ]
then
    dir="$PWD/*"  #could use $(ls | wc -l)

elif [ $# = 1 ]
then
    if [ -d "$1" ]
    then
        dir="$1/*"  #could use $(ls $1 | wc -l) as ls returns new line for every enrty
    else
        echo "$1 is not a directory. Quitting."
        exit 1
    fi

else
    echo "Usage: $PWD/fc.sh [directory]. Quitting." #note square brackets means 0 or 1 occurances so 1 argument or none
    exit 2
fi

for i in $dir #do not use $(ls "$dir")
do
   x=$((x+1)) #do not need $x inside the double parents
done

echo "final ans: $x"

exit 0
