rem @echo off
SET program="%1"
if %program% == "" goto err

echo 1
task2.exe "16" "10" "FF"
if ERRORLEVEL 1 goto testFailed

echo 2
task2.exe "36" "10" "ZZ"
if ERRORLEVEL 1 goto testFailed

echo 3
task2.exe "2" "10" "DDDDDDDDDDDDDDDDDDDDDDDDDDDDD"
if ERRORLEVEL 1 goto testFailed

echo 4
task2.exe "37" "10" "FF"
if ERRORLEVEL 1 goto testFailed

echo 5
task2.exe "1" "10" "00"
if ERRORLEVEL 1 goto testFailed

echo OK
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>