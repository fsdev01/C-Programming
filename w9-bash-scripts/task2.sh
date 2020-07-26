#!/bin/bash
# LAB VERSION
# "Directory as an argument"

#Your script should go through each .c and .h file in its target directory and 
# look for lines that contain the strings TODO:, FIXME:, or both. 
# You should output the filename and line number, but not the line itself. Your script should recurse into subdirectories.
# At the end, you should output the string "Your to-do list has NN items on it." where NN is the total number of TODOs and FIXMEs found.
#USE: find, grep, manipulate 

if [ $# -eq 0 ];then  # Zero Argument - Operate on the Current Directory
    total=0

#for file in $( find `pwd` -name "*.[ch]" ); do # OLD ONE - show absolute path
#for file in $( find `pwd` -name "*.[ch]" ); do # OLD ONE - show relative path ./...

#STEP 1: Identify .c and .h files using find
#Step 2: Look inside text using GREP for "TODO:" or "FIXME:"


    for file in $( find . -name "*.[ch]" ); do
        # Count Number of Instances of TODO or FIXME in a given text file
        tempCount=$(grep -E "TODO|FIXME" $file -c)
        # Update total Counter of all instances of TODO and FIXEME
        total=$(( total + tempCount))
        #Search for the instances

        #Print filename and linenumber   #Output first => field1:field2:field 3 => : -f 1-2
        # Example: ./test/dataType.h:5  field1: path of the fileName  field2: linenumber
        # ALTERNATIVE: grep -E -H -n "TODO:|FIXME" $file | cut -d : -f 1-2
        grep -n -H "TODO" $file |cut -d : -f 1-2
        grep -n -H "FIXME" $file | cut -d : -f 1-2
    done
    echo "Your to-do list has $total items on it"

elif [ $# -eq 1 ]; then # One Argument - ARGUMENT is a DIRECTORY PATH
    #Check whether the directory exists using the -d operator.
    # Test with either "."  or ".." or "~/temp/lab10/"
    if [ -d $1 ];then
        #echo "The Directory Exists"
        status=1
    else
        echo "The directory '$1' DOES NOT EXIST"
        status=0
    fi

    # If the directory exists, then search for FIXME and TODO
    total=0
    if [ $status -eq 1 ]; then
        
        for file in $( find $1 -name "*.[ch]" ); do
            #echo $file
            tempCount=$(grep -E "TODO|FIXME" $file -c) # Count Number of TODO or FIXME in a given file
            total=$(( tempCount + total )) # Update Subtotal
            grep -H -n 'TODO' $file | cut -d : -f 1-2
            grep -H -n 'FIXME' $file | cut -d : -f 1-2
        done
        echo Your to-do list has $total items on it
    fi

else
    echo "Invalid Usage"
fi
