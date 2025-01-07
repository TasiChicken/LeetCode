#!/bin/bash

# Get the script's directory
script_dir=$(dirname "$(realpath "$0")")

# Set the original directory
oriCd=$(pwd)

# Change to the script directory's parent folder (..\cpps equivalent)
cd "$script_dir/../cpps"

# Initialize max_number
max_number=0

# Loop through directories
while true; do
    max_number_in_dir=0
    for subFols in */; do
        if [ -d "$subFols" ]; then
            # Remove trailing slash and compare
            subFols=${subFols%/}
            if [[ "$subFols" != *"."* ]] && [ "$subFols" -gt "$max_number_in_dir" ]; then
                max_number_in_dir=$subFols
            fi
        fi
    done

    if [[ $max_number_in_dir -ne 0 ]]; then
        cd "$max_number_in_dir"
    else
        break
    fi
done

# Check the .cpp files for the highest numbered one
for file in *.cpp; do
    num=$(basename "$file" .cpp)
    if [[ $num -gt $max_number ]]; then
        max_number=$num
    fi
done

# Return to the original directory
cd "$oriCd"

# Export max_number as PROGRESS
export PROGRESS=$max_number