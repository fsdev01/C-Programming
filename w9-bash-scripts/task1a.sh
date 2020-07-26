#! /bin/bash

#Task 1A: Count the number of files in a directory
echo "Number of Arguments: $#"
# Case 1: Supplied Zero Arguments - Print out # of files in the current directory
if [ $# -eq 0 ]; then
	count=$(ls | wc -l)
	echo "Number of files in current directory is $count"

# Case 2: Supplied 1 Argument - Check whether the directory name matches the argument
elif [ $# -eq 1 ]; then
    if [ -d $1 ];then
        count=$(ls $1| wc -l)
        echo "The directory $1 exist with $count files"
    else
    	echo "The directory $1 does not exist"
    fi

else
	echo "Invalid Usage. task1a.sh [directoryname]"
fi