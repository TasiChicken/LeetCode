@echo off

call getProgress.bat

set /a "PROGRESS+=1"
start https://leetcode.com/problemset/all/?search=%PROGRESS%&page=1

call newFile.bat