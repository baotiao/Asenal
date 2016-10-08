#!/bin/sh

rm -rf *_res;
for ((i = 0; i < 100; i=( $i + 1) ))
do
  ./m1  >> ./res_m1$i;
done


# cat m1_res | awk -F ',' 'BEGIN { sum = 0; n = 0; }; {sum += $4; n++;}; END {printf("%d \n", sum / n);}' > m1t

