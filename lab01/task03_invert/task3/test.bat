rem @echo off
SET program="%1"
if %program% == "" goto err

echo 1
%program% "test\1matrix.txt"
if NOT ERRORLEVEL 1 goto testFailed

echo 2
%program% "test\4x4matrix.txt"
if ERRORLEVEL 1 goto testFailed

echo 3
%program% "test\det0.txt"
if NOT ERRORLEVEL 1 goto testFailed

echo 4
%program% "test\floatMatrix.txt"
if ERRORLEVEL 1 goto testFailed

echo 5
%program% "test\matrix.txt"
if ERRORLEVEL 1 goto testFailed

echo OK
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>