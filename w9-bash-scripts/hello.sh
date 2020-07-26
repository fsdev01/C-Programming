#!/bin/bash
name="John"
echo "Hello! $name"

nfiles=$(ls| wc -l)
echo $nfiles

nfiles2=`ls| wc -l`
echo $nfiles2

x=2
y=2
myvar=$((x+1))
echo $myvar

num=$(($x + $y))
echo $num

tar zxcf $TARFILE || echo "Error: Couldn't extract archive"

FILE="MysteryFile"


# if else 
if [ -d $FILE ]; then
	echo $FILE is a directory
elif [ -f $FILE ]
	then
		echo $FILE is an ordinary FILE
else 
	echo "I don't know what $FILE is"
fi


# while loop
i=0
while [ $i -lt 10 ]; do
	echo $i
	((i++))
done

echo ""

#until loop - terminates when condition becomes true
i=0
until [ $i -eq 10 ]; do
	echo $i
	((i++))
done

#foreach loop
for file in $(ls); do
	echo "I can see $file"
done;

echo $0 # Name of Shell Script
echo $1 # first command line parameter

echo "Number of CMD Line Parameters $#"
#loop through each cmd line parameter
for param in $@; do
	echo "Parameter: $param"
done

# Capture user input using "read"
# note -ne equivalent to -n -e
echo -ne "Do you want to list all files in parent directory? (y/n)\t"
read choice
if [ $choice == 'y' ]; then
	ls -al ..
else
	echo "Ok. Goodbye"
fi
