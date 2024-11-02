@echo off
setlocal enabledelayedexpansion

:: Loop through Q1 to Q9
for /L %%i in (1,1,9) do (
    ren "Q%%i.txt" "Q0%%i.txt"
)

:: Loop through Q10 to Q13 (no padding needed here)
for /L %%i in (10,1,13) do (
    ren "Q%%i.txt" "Q%%i.txt"
)

endlocal
