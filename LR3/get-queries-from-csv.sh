input_file_name='data-for-queries.csv'
output_file_name='output-query.txt'

table_name=$(head -n 1 $input_file_name)
cols_names=$(head -2 $input_file_name | tail -1 | sed 's/ //g')

values=()

response="INSERT INTO $table_name($cols_names) VALUES "
temp_row=""

while read -r whole_line 
do
	temp_row="$(echo "${whole_line}" | sed 's/ //g')"
	# echo $temp_row
 	response+="($temp_row), " 
done < <(tail -n +3 $input_file_name)



# :offset:length
echo "${response:0:-2}" > $output_file_name

# sed ==> stream editor for finding, replacing...
