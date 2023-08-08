@echo off
git add .

call getProgress.bat
git commit -m "finish %PROGRESS%"

git pull origin main
git push origin main

git status

pause