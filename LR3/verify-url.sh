#!/bin/bash  
  
input="./url.txt"
regular_expression='^(https?:\/\/)?'\
'(www\.)?'\
'('\
'[a-zA-Z][a-zA-Z0-9]{2,}((-|_|.)[a-zA-Z0-9]+)*'\
'(\.[a-zA-Z]{2,11})'\
')'\
'(\/)?'\
'(\/([a-zA-Z0-9]+(\/[a-zA-Z0-9]+)*\/?)?\.[a-zA-Z0-9]{1,10})?$'

# protocol [optinal]
# www [optional]
# 
# hostname
# hostname
# 
# path


while read -r line
do
  [[ $line =~ $regular_expression ]] && echo "$line" " --- OK" || echo "$line" "--- NO"
done < "$input"
