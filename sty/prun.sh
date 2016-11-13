#!/bin/sh

rm -rf ./mm_res_*
for ((j = 70; j < 91; j=( $j + 10) ))
do
  for ((i = 0; i < 100; i=( $i + 1) ))
  do
    ./mm 100 100 0 $j >> ./mm_res_$j\_$i;
  done
  ./pp ./mm_res_$j\_ > ./pic_$j;
done
