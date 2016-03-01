rem @echo off
SET program="%1"
if %program% == "" goto err

mkdir OUT
echo "1"
%program% "test\input.txt" "OUT\out1.txt" "ma" "mama"
if ERRORLEVEL 1 goto testFailed

echo "2"
%program% "test\input.txt" "OUT\out2.txt" "1231234" "TABULATION"
if ERRORLEVEL 1 goto testFailed

echo "3"
%program% "test\input.txt" "OUT\out3.txt" "123" "ASDASASDABSJDGABSJDGBASBDJBASDHBKAHSBDHBASDBAKHSDBHASBHDKASBHDBHJASBHDASBHDABJHSDBHAASDABSJDGABSJDGBASBDJBASDHBKAHSBDHBASDBAKHSDBHASBHDKASBHDBHJASBHDASBHDABJHSDBHAASDABSJDGABSJDGBASBDJBASDHBKAHSBDHBASDBAKHSDBHASBHDKASBHDBHJASBHDASBHDABJHSDBHAASDABSJDGABSJDGBASBDJBASDHBKAHSBDHBASDBAKHSDBHASBHDKASBHDBHJASBHDASBHDABJHSDBHADASDAHGDAGVSDGHSADASGHDGHASDGHASSDASASGHDGHASDGHASSDASDASDASDASDHASHGDAGVS"
if ERRORLEVEL 1 goto testFailed

echo "4"
%program% "test\input.txt" "OUT\out4.txt" "peace" ""
if ERRORLEVEL 1 goto testFailed

echo "5"
%program% "test\input.txt" "OUT\out5.txt" "" "CAPS LOCK"
if ERRORLEVEL 1 goto testFailed

echo "6"
%program% "test\empty.txt" "OUT\out6.txt" "123" "321"
if NOT ERRORLEVEL 1 goto testFailed

echo "7"
%program% "test\3gb.txt" "OUT\out7.txt" "пере" "после"
if NOT ERRORLEVEL 1 goto testFailed

echo "8"
%program% "test\input" "OUT\out8.txt" "123" "211"
if NOT ERRORLEVEL 1 goto testFailed

echo "9"
%program% "test\input.txt" "OUT\out9" "123" "321"
if ERRORLEVEL 1 goto testFailed

echo OK
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>