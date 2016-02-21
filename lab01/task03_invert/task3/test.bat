rem @echo off
SET program="%1"
if %program% == "" goto err

echo 1
task3.exe "test\1matrix.txt"
if ERRORLEVEL 1 goto testFailed

echo 2
task3.exe "test\4x4matrix.txt"
if ERRORLEVEL 1 goto testFailed

echo 3
task3.exe "test\det0.txt"
if ERRORLEVEL 1 goto testFailed

echo 4
task3.exe "test\floatMatrix.txt"
if ERRORLEVEL 1 goto testFailed

echo 5
task3.exe "test\matrix.txt"
if ERRORLEVEL 1 goto testFailed

echo OK
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>