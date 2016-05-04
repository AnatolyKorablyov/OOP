rem echo off
SET program="%1"

mkdir OUT
echo sort for dot
%program% "input\input1.txt" "OUT\output1.txt"
IF ERRORLEVEL 1 GOTO testFailed
fc /b OUT\output1.txt standard/dot.txt
IF ERRORLEVEL 1 GOTO testFailed

echo sort for lineSegment
%program% "input\input2.txt" "OUT\output2.txt"
IF ERRORLEVEL 1 GOTO testFailed
fc /b OUT\output2.txt standard/lines.txt
if ERRORLEVEL 1 goto testFailed

echo sort for rectangle
%program% "input\input3.txt" "OUT\output3.txt"
IF ERRORLEVEL 1 GOTO testFailed
fc /b OUT\output3.txt standard/rectangle.txt
if ERRORLEVEL 1 goto testFailed

echo sort for triangle
%program% "input\input4.txt" "OUT\output4.txt"
IF ERRORLEVEL 1 GOTO testFailed
fc /b OUT\output4.txt standard/triangle.txt
IF ERRORLEVEL 1 GOTO testFailed

echo sort for circle 
%program% "input\input5.txt" "OUT\output5.txt"
IF ERRORLEVEL 1 GOTO testFailed
fc /b OUT\output5.txt standard/circle.txt
IF ERRORLEVEL 1 GOTO testFailed

echo sort for all shapes
%program% "input\input6.txt" "OUT\output6.txt"
IF ERRORLEVEL 1 GOTO testFailed
fc /b OUT\output6.txt standard/allShapes.txt
IF ERRORLEVEL 1 GOTO testFailed

echo sort shapes girl
%program% "input\a_girl.txt" "OUT\output7.txt"
IF ERRORLEVEL 1 GOTO testFailed
fc /b OUT\output7.txt standard/a_girl.txt
IF ERRORLEVEL 1 GOTO testFailed

echo OK
pause 
exit /B

:testFailed
ECHO Testing failed
pause
exit /B

:err
echo Usage: test.bat <Path to %program%>

pause
Status API Training Shop Blog About
© 2016 GitHub, Inc. Terms Privacy Security Contact