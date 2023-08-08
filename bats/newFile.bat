@echo off
call getProgress.bat
set /a "PROGRESS+=1"

copy 0.cpp %PROGRESS%.cpp