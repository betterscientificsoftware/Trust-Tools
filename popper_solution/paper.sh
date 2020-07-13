#!/bin/sh
#Compiles Latex files and produces a pdf.
echo "Executing paper.sh"


#Compile SOTF Latex files and generate pdf
pdflatex SOTF
bibtex SOTF
pdflatex SOTF
pdflatex SOTF

