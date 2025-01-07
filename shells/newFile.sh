#!/bin/bash

# Get the directory where the script is located
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Initialize PROGRESS
PROGRESS=-1

# Assuming getProgress.sh is the equivalent of getProgress.bat
source "$SCRIPT_DIR/getProgress.sh"  # Call the script to set the PROGRESS variable

# Change to the `cpps` directory relative to the script's location
cd "$SCRIPT_DIR/../cpps" || exit
PROGRESS=$((PROGRESS + 1))

number=$PROGRESS
fol=$(pwd)

# Loop through values 1000, 100, 10 and calculate folder names
for i in 1000 100 10; do
    value=$(((number + i - 1) / i * i))
    number=$((number + i - value))
    fol="$fol/$value"
done
# Create folder if it doesn't exist
if [ ! -d "$fol" ]; then
    mkdir -p "$fol"
fi

# Copy 0.cpp to the new folder and rename it
cp "$SCRIPT_DIR/../cpps/0.cpp" "$fol/$PROGRESS.cpp"

# Open the new file in Visual Studio Code (ensure VS Code is installed and `code` is available)
code "$fol/$PROGRESS.cpp"

# Uncomment the following lines if you need an infinite loop like in the batch file
# while [ "$AMOUNT" -gt 0 ]; do
#     # Your logic here
# done
