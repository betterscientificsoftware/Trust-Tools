#!/bin/sh
echo "Executing run.sh"

#Get path of directory containing scripts
full_path=$(realpath $0)
dir_path=$(dirname $full_path)

#Execute experiment and paper generating scripts.
$dir_path/madness.sh
$dir_path/paper.sh
