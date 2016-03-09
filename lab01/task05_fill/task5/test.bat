rem @echo off
SET program="%1"
if %program% == "" goto err

mkdir OUT
echo 1
%program% "test\input.txt" "OUT\out1.txt"
if ERRORLEVEL 1 goto testFailed

echo 2
%program% "test\0inEmpty.txt" "OUT\out2.txt"
if ERRORLEVEL 1 goto testFailed
fc.exe "OUT\out2.txt" "standart\test2.txt"
if ERRORLEVEL 1 goto testFailed

echo 3
%program% "test\2x0inLine.txt" "OUT\out3.txt"
if ERRORLEVEL 1 goto testFailed
fc.exe "OUT\out3.txt" "standart\2x0.txt"
if ERRORLEVEL 1 goto testFailed

echo OK
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>