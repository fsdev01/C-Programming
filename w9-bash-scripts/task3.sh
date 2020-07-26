#!/bin/bash

echo Welcome to RetroComputings menu-driven EasyShell!

run=1
while [ $run -eq 1 ];do
    echo Enter a command:
    #Read input from keyboard
    read command fileName
    # CASE 1: Help Command
    if [ $command == 'h' ]; then 
        echo -e "\nh: print this help message"
        echo 'e filename: edit filename with vi'
        echo 't filename: touch this filename'
        echo "q: quit to bash shell"
        echo "l: list C source files (e.g. all .c and .h)"
        echo "f pattern: find files whose names contain pattern"
    #CASE 2: Quit Command
    elif [ $command == 'q' ]; then
        #run=0
        exit
    #CASE 3: Touch Command
    elif [ $command == 't' ]; then
        # Update the modification/access time of the given file
        #Check whether the file exists
        if [ -e $fileName ]; then
            #echo File Exists
            touch $fileName  # Touches the File
            ls -l $fileName  # Shows the details of the update
        else
            echo "The File '$fileName' does not exist"
        fi
    #CASE 4: Vi Command
    elif [ $command == 'vi' ]; then
        if [ -e $fileName ]; then          #Check Whether the file exists 
            vi $fileName
        else
            echo "The File '$fileName' Does not Exist"
        fi
    # Case 5: List all source files with .c and .h extension
    elif [ $command == 'l' ]; then
        find `pwd` -name "*.[ch]"  # Note automatically, recursive
    # Case 6: List all files with the pattern as the filename
    elif [ $command == 'f' ]; then
        find `pwd` -name "$fileName"
    
    else
        echo "Try Again: Invaid command"
    fi
done