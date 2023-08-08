@echo off
cd ..
setlocal enabledelayedexpansion

set "max_number=0"

for %%f in (*.cpp) do (
    set "filename=%%~nf"
    set "number=!filename!"
    set "number=!number:.cpp=!"
    
    if !number! gtr !max_number! (
        set "max_number=!number!"
    )
)

endlocal & set "PROGRESS=%max_number%"

exit /b