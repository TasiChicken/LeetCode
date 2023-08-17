@echo off
setlocal enabledelayedexpansion

set "oriCd=%cd%"
cd ..\cpps

:LOOP
set "max_number=0"
for /d %%d in (%cd%\*) do (
    set "subFols=%%~nxd"
    if !subFols! gtr !max_number! set "max_number=!subFols!"
)
if !max_number! NEQ 0 (
    cd %max_number%
    goto LOOP
)

for %%f in (*.cpp) do if %%~nf gtr !max_number! set "max_number=%%~nf"

cd %oriCd%
endlocal & set "PROGRESS=%max_number%"
exit /b