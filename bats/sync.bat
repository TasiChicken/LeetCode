@echo off
del "..\*.EXE"


set /p MESSAGE="Commit Message: "

if "%MESSAGE%" NEQ "" goto GITSYUC

call getProgress.bat
set MESSAGE=finish %PROGRESS%
cd bats

:GITSYUC

cd ..
git add .
git commit -m "%MESSAGE%"

git pull origin main
git push origin main