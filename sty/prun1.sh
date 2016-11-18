#!/bin/sh

rm -rf ./mm_rd_*
for ((j = 70; j < 91; j=( $j + 10) ))
do
  for ((k = 0; k < 101; k=( $k + 5) ))
  do
    rm -rf last_r;
    for ((i = 0; i < 100; i=( $i + 1) ))
    do
      ./mm $k 90 50 $j 3 | tail -1 >> ./last_r;
    done
    cat last_r | awk -F '\t' 'BEGIN { sum = 0; n = 0; }; {sum += $2; n++;}; END {printf("%d \n", sum / n);}' >> mm_rd_$j;
  done
done
