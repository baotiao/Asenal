#!/bin/sh

rm -rf *_res;


for ((j = 70; j < 71; j=( $j + 10) ))
do
  rm -rf ./res_m21*
  for ((i = 0; i < 100; i=( $i + 1) ))
  do
    ./m21 $j  >> ./res_m21$i;
  done
  ./p1 res_m21 > ./pic_21_$j;
done

for ((j = 70; j < 71; j=( $j + 10) ))
do
  rm -rf ./res_m22*
  for ((i = 0; i < 100; i=( $i + 1) ))
  do
    ./m22 $j  >> ./res_m22$i;
  done
  ./p1 res_m22 > ./pic_22_$j;
done

