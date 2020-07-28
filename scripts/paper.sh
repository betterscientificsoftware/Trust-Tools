#!/bin/sh
#Compiles Latex files and produces a pdf.

echo "Executing paper.sh"

#Create table output for docker-table in Tex file
python table.py correct.txt ./madness/build/output_no_advantage.txt ./madness/build/output_2_advantage.txt ./madness/build/output_4_advantage.txt docker_table.tex 12

#Create table output for popper-table in Tex file
python table.py correct.txt ./madness/build/output_no_advantage.txt ./madness/build/output_2_advantage.txt ./madness/build/output_4_advantage.txt popper_table.tex 16

#Compile SOTF Latex files and generate pdf
pdflatex SOTF
bibtex SOTF
pdflatex SOTF
pdflatex SOTF
