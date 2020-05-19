#!/user/bin/env python
#Creates table in Latex format. 
#6 parameters:
# (1) Results (txt file) (Correct March Madness Ranking)
# (2) Results (txt file) #1
# (3) Results (txt file) #2
# (4) Results (txt file) #3
# (5) Path location of latex table with results 
# (6) Number of teams to display.

import sys
def main():
	correct_data_path = sys.argv[1]
	file_1 = sys.argv[2]
	file_2 = sys.argv[3]
	file_3 = sys.argv[4]
	output_file = sys.argv[5]
	num_displayed_teams = int(sys.argv[6])

	correct = []
	file_1_array = []
	file_2_array = []
	file_3_array = []

	with open(correct_data_path, 'r') as correct_data:
		for line in correct_data:
			correct.append(line.partition(" ")[2].strip())

	with open(file_1, 'r') as file_1:
		for line in file_1:
			file_1_array.append(line.partition(" ")[2].strip())

	with open(file_2, 'r') as file_2:
		for line in file_2:
			file_2_array.append(line.partition(" ")[2].strip())

	with open(file_3, 'r') as file_3:
		for line in file_3:
			file_3_array.append(line.partition(" ")[2].strip())

	
	with open(output_file, 'w') as output:
		output.write('\\begin{tabular}{ |p{2cm}||p{2cm}|p{2cm}|p{2cm}|  }\n')
		output.write('\\hline\n')
		output.write('\\multicolumn{4}{|c|}{Docker Simulated Results} \\\\\n')
		output.write('\\hline\n')
		output.write(' 2019 Results &  Home-Field Advantage 0 & Home-Field Advantage 2& Home-Field Advantage 4\\\\\n')
		output.write('\\hline\n')
		for x in range(num_displayed_teams):
			output.write('{} & {} & {} & {}\\\\\n'.format(correct[x], file_1_array[x], file_2_array[x], file_3_array[x] ))
			output.write('\\hline\n')
		output.write('\\end{tabular}\n')


	
	

main()
