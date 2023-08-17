@echo off
set PROGRESS=-1
call getProgress.bat

set /p AMOUNT="New Files Amount : "

:LOOP

if "%AMOUNT%" == "0" EXIT

set /a PROGRESS+=1
set /a AMOUNT-=1
copy 0.cpp %PROGRESS%.cpp

goto LOOP