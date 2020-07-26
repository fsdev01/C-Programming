#! /bin/bash

#TASK 1B:
#echo $# #print out number of arguments
#CASE 1: Zero Arguments  print out # of files in the current directory
regularFiles=0
namedPipes=0
blockDevices=0
charDevices=0
symlinks=0
directs=0
other=0

#Count of each different type of file is in the directory: 
# named pipes, block devices, character devices, directories, symbolic links, and regular files.


if [ $# -eq 0 ];then
    count=$(ls | wc -l)
    echo "Number of files in current directory is: $count"
    for thefile in $(ls ); do
        if [ -f $thefile ]; then 
            regularFiles=$(( regularFiles + 1))
        elif [ -p $thefile ]; then
            namedPipes=$(( namedPipes + 1 ))
        elif [ -c $thefile  ]; then 
            charDevices=$(( charDevices + 1 ))
        elif [ -b $thefile ]; then
            blockDevices=$(( blockDevices + 1))
        elif [ -d $thefile ]; then
            directs=$(( directs + 1))
        else  #symlinks
            symlinks=$(( symlinks +1 ))
        fi
    done
    echo "The number of regular files: $regularFiles"
    echo "The number of named pipes: $namedPipes"
    echo "The number of block devices: $blockDevices"
    echo "The number of character devices: $charDevices"
    echo "The number of symbolic links: $symlinks"
    echo "The number of directories: $directs"
    
#CASE 2: 1 Argument - check whether the directory exists in current file.
elif [ $# -eq 1 ]; then # One Argument
    if [ -d $1 ];then
        count=$(ls $1| wc -l)
        echo "The directory $1 exist with $count files"
        #Method 1:Change directories to count #of each different type of files. cd $1
        # Note: only the directory OF CURRENT BASH WILL CHANGE IF USE "SOURCE COMMAND"
        cd $1
        #Method 2 DOES NOT WORK- treated as symlinks: change "ls" command to "ls dirName"
            for thefile in $(ls); do
                echo "the file: $thefile"
                if [ -f $thefile ]; then 
                    regularFiles=$(( regularFiles + 1))
                elif [ -p $thefile ]; then
                    namedPipes=$(( namedPipes + 1 ))
                elif [ -c $thefile  ]; then 
                    charDevices=$(( charDevices + 1 ))
                elif [ -b $thefile ]; then
                    blockDevices=$(( blockDevices + 1))
                elif [ -d $thefile ]; then
                    directs=$(( directs + 1))
                elif [ -h $thefile ]; then #symlinks
                    symlinks=$(( symlinks +1 ))
                else
                    other=$(( other + 1))
                fi
            done
        echo "The number of regular files: $regularFiles"
        echo "The number of named pipes: $namedPipes"
        echo "The number of block devices: $blockDevices"
        echo "The number of character devices: $charDevices"
        echo "The number of symbolic lniks: $symlinks"
        echo "The number of directories: $directs"
        echo "THe number of other: $other"
        #Change back to parent directory. IF USER USES "SOURCE" COMMAND
        cd ..
    else
        echo "ERROR:The directory '$1' does not EXIST"
    fi
    
#CASE 3: 2 ARGUMENTS or MORE INVALID.
else
    echo "Invalid Usage"
fi

