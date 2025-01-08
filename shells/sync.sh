#!/bin/bash

# Get the directory where the script is located
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Initialize PROGRESS
PROGRESS=-1

# Assuming getProgress.sh is the equivalent of getProgress.bat
source "$SCRIPT_DIR/getProgress.sh"  # Call the script to set the PROGRESS variable

# Prompt user for commit message
read -p "Commit Message([Finish progress] if empty): " MESSAGE

if [ -z "$MESSAGE" ]; then
    # If no message was provided, set it to finish progress
    "$SCRIPT_DIR/getProgress.sh"  # Assuming you have an equivalent getProgress.sh script
    MESSAGE="finish $PROGRESS"
fi

# Change to the parent directory of the script's location
cd "$SCRIPT_DIR/.."

# Delete all .exe files recursively in the cpps directory
find ./cpps -type f -name "*.exe" -exec rm -f {} \;

# Stage changes and commit
git add .
git commit -m "$MESSAGE"

# Pull and push to the repository
git pull origin main
git push origin main
