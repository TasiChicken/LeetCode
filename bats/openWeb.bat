@echo off

::set 20 or 50 or 100
set ProblemsPerPag=20

call getProgress.bat
set /a "Page=(%PROGRESS%+%ProblemsPerPag%)/%ProblemsPerPag%"
start https://leetcode.com/problemset/all/?page=%Page%

call newFile.bat