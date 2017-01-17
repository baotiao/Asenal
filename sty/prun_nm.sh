#!/bin/sh

rm -rf ./mm_res_*
for ((j = 70; j < 91; j=( $j + 10) ))
do
  rm -rf last_sd;
  for ((i = 0; i < 100; i=( $i + 1) ))
  do
    ./nm 100 100 0 $j 1 > ./run_tmp;
    cat ./run_tmp | grep -v 'sd' > ./mm_res_$j\_$i;
  done
  ./ppnm ./mm_res_$j\_ > ./pic_$j;
done
