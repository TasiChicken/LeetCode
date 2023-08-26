@echo off

call getProgress.bat
setlocal enabledelayedexpansion

for /l %%i in (1, 1, 5) do (
    set /a "PROGRESS+=1"
    set "url=!url!!PROGRESS!+"
)

set "url=!url:~0,-1!"
start https://leetcode.com/problemset/all/?search=!url!&page=1

endlocal
call newFile.bat