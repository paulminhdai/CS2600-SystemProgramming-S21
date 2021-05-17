#!bin/bash

#Get params from command line
src=$1
des=$2

#Check the source file
if ! [ -f "$src" ]; then
    echo "ERROR: $src does not exist."
    exit 0
fi

c=1 #increment if destination exists
origin=$des 
while [ -f "$des" ]; do #check the destination file
    des=$origin
    des=$des.$c
    (( c++ ))
done

mv $src $des #move the file
echo "SUCCESS: Finished to move $src to $des."
