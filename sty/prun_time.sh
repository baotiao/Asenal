#!/bin/sh

rm -rf *_res;


for ((j = 70; j < 101; j=( $j + 10) ))
do
  rm -rf ./res_m1*
  for ((i = 0; i < 100; i=( $i + 1) ))
  do
    ./m1 $j 20 70 >> ./res_m1$i;
  done
  ./p res_m1 > ./pic_1_$j;
done

for ((j = 70; j < 101; j=( $j + 10) ))
do
  rm -rf ./res_m21*
  for ((i = 0; i < 100; i=( $i + 1) ))
  do
    ./m21 $j 20 70 >> ./res_m21$i;
  done
  ./p1 res_m21 > ./pic_21_$j;
done

for ((j = 70; j < 101; j=( $j + 10) ))
do
  rm -rf ./res_m22*
  for ((i = 0; i < 100; i=( $i + 1) ))
  do
    ./m22 $j 20 70 >> ./res_m22$i;
  done
  ./p1 res_m22 > ./pic_22_$j;
done

for ((j = 70; j < 101; j=( $j + 10) ))
do
  rm -rf ./res_m31*
  for ((i = 0; i < 100; i=( $i + 1) ))
  do
    ./m31 $j 20 70 >> ./res_m31$i;
  done
  ./p1 res_m31 > ./pic_31_$j;
done

for ((j = 70; j < 101; j=( $j + 10) ))
do
  rm -rf ./res_m32*
  for ((i = 0; i < 100; i=( $i + 1) ))
  do
    ./m32 $j 20 70 >> ./res_m32$i;
  done
  ./p1 res_m32 > ./pic_32_$j;
done
