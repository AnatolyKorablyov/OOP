rem @echo off
SET program="%1"
if %program% == "" goto err

echo 1
%program% "input1.txt" >> out1.txt
if ERRORLEVEL 1 goto testFailed

echo 2
%program% "input2.txt" >> out2.txt
if ERRORLEVEL 1 goto testFailed


echo 3
%program% "input3.txt" >> out3.txt
if ERRORLEVEL 1 goto testFailed

echo 4
%program% "input4.txt" >> out4.txt
if ERRORLEVEL 1 goto testFailed

echo OK
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>