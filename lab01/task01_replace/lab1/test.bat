@echo off

mkdir OUT
echo "1"
lab1.exe "test\input.txt" "OUT\out1.txt" "ma" "mama"
echo "2"
lab1.exe "test\input.txt" "OUT\out2.txt" "1231234" "TABULATION"
echo "3"
lab1.exe "test\input.txt" "OUT\out3.txt" "123" "ASDASASDABSJDGABSJDGBASBDJBASDHBKAHSBDHBASDBAKHSDBHASBHDKASBHDBHJASBHDASBHDABJHSDBHAASDABSJDGABSJDGBASBDJBASDHBKAHSBDHBASDBAKHSDBHASBHDKASBHDBHJASBHDASBHDABJHSDBHAASDABSJDGABSJDGBASBDJBASDHBKAHSBDHBASDBAKHSDBHASBHDKASBHDBHJASBHDASBHDABJHSDBHAASDABSJDGABSJDGBASBDJBASDHBKAHSBDHBASDBAKHSDBHASBHDKASBHDBHJASBHDASBHDABJHSDBHADASDAHGDAGVSDGHSADASGHDGHASDGHASSDASASGHDGHASDGHASSDASDASDASDASDHASHGDAGVS"
echo "4"
lab1.exe "test\input.txt" "OUT\out4.txt" "peace" ""
echo "5"
lab1.exe "test\input.txt" "OUT\out5.txt" "" "CAPS LOCK"
echo "6"
lab1.exe "test\empty.txt" "OUT\out6.txt" "123" "321"
echo "7"
lab1.exe "test\3gb.txt" "OUT\out7.txt" "����" "�����"
echo "8"
lab1.exe "test\input" "OUT\out8.txt" "123" "211"
echo "9"
lab1.exe "test\input.txt" "OUT\out9" "123" "321"
pause