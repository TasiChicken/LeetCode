@echo off
del "..\*.EXE"
call getProgress.bat

git add .
git commit -m "finish %PROGRESS%"

git pull origin main
git push origin main
