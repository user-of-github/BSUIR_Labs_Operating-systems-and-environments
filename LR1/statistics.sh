#!/bin/bash

echo Current username: $USER

current_date=$(date '+%Y-%m-%S')
echo Current  date: $current_date

current_time=$(date '+ %H:%M')
echo Current time: $current_time

echo Current directory: $PWD

# wc => 'word count' (length)
processes_count=$(ps aux | wc -l) 
echo Processes count: $processes_count

echo System was working for: $(uptime -p)
