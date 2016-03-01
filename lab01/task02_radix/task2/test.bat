rem @echo off
SET program="%1"
if %program% == "" goto err

echo 1
%program% "16" "10" "FF"
if ERRORLEVEL 1 goto testFailed

echo 2
%program% "36" "10" "ZZ"
if ERRORLEVEL 1 goto testFailed

echo 3
%program% "16" "10" "DDDDDDDDDDDDDDDDDDDDDDDDDDDDD"
if ERRORLEVEL 1 goto testFailed

echo 4
%program% "37" "10" "FF"
if NOT ERRORLEVEL 1 goto testFailed

echo 5
%program% "1" "10" "0"
if NOT ERRORLEVEL 1 goto testFailed

echo 6
%program% "2" "10" " "
if NOT ERRORLEVEL 1 goto testFailed

echo OK
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>