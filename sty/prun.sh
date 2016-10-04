#!/bin/sh

rm -rf *_res;
for ((i = 0; i < 100; i=( $i + 1) ))
do
  ./m1 | tail -1 >> m1_res;
done

cat m1_res | awk -F ',' 'BEGIN { sum = 0; n = 0; }; {sum += $4; n++;}; END {printf("%d \n", sum / n);}' > m1t

for ((i = 0; i < 100; i=( $i + 1) ))
do
  ./m21 | tail -1 >> m21_res;
done

cat m21_res | awk -F ',' 'BEGIN { sum = 0; n = 0; }; {sum += $2; n++;}; END {printf("%d \n", sum / n);}' > m21t

for ((i = 0; i < 100; i=( $i + 1) ))
do
  ./m22 | tail -1 >> m22_res;
done

cat m22_res | awk -F ',' 'BEGIN { sum = 0; n = 0; }; {sum += $2; n++;}; END {printf("%d \n", sum / n);}' > m22t
for ((i = 0; i < 100; i=( $i + 1) ))
do
  ./m31 | tail -1 >> m31_res;
done

cat m31_res | awk -F ',' 'BEGIN { sum = 0; n = 0; }; {sum += $2; n++;}; END {printf("%d \n", sum / n);}' > m31t
for ((i = 0; i < 100; i=( $i + 1) ))
do
  ./m32 | tail -1 >> m32_res;
done

cat m32_res | awk -F ',' 'BEGIN { sum = 0; n = 0; }; {sum += $2; n++;}; END {printf("%d \n", sum / n);}' > m32t
