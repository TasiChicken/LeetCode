@echo off

set PROGRESS=-1
call getProgress.bat

set /p AMOUNT="New Files Amount : "

cd ..\cpps
setlocal enabledelayedexpansion

:LOOP
if "%AMOUNT%" == "0" EXIT

set /a PROGRESS+=1
set /a AMOUNT-=1

set "number=%PROGRESS%"
set "fol=%cd%"
for %%i in (1000 100 10) do (
    set /a "value=(!number!+%%i-1)/%%i*%%i"
    set /a "number=!number!+%%i-!value!"

    set "fol=!fol!\!value!"
)
if not exist "!fol!" mkdir "!fol!"
copy 0.cpp "!fol!\%PROGRESS%.cpp"

goto LOOP

endlocal