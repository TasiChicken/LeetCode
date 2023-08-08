@echo off
call getProgress.bat
set /a "PROGRESS+=1"

echo %PROGRESS%
echo %cd%

cd ..
copy 0.cpp %PROGRESS%.cpp

pause