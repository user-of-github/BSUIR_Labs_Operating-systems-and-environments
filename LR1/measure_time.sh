#!/bin/bash

if ! [ -f "$1" ]; then
	echo "File $1 does not exist."
	exit 0
fi

start=`date +%N`
bash $1
finish=`date +%N`

measured_time_ns=$((finish-start))

echo Script took $((measured_time_ns/1000000)) milliseconds
