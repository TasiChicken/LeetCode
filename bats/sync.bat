@echo off

set /p MESSAGE="Commit Message([Finish progress] if empty): "

if "%MESSAGE%" NEQ "" goto GITSYUC

call getProgress.bat
set MESSAGE=finish %PROGRESS%

:GITSYUC
cd ..

for /r "%cd%\cpps" %%f in (*.exe) do del "%%f"

git add .
git commit -m "%MESSAGE%"

git pull origin main
git push origin main