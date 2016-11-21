#!/bin/sh

rm -rf ./mm_res_*
for ((j = 70; j < 91; j=( $j + 10) ))
do
  rm -rf last_sd;
  for ((i = 0; i < 100; i=( $i + 1) ))
  do
    ./mm 100 100 0 $j 1 > ./run_tmp;
    cat ./run_tmp | grep -v 'sd' > ./mm_res_$j\_$i;
    cat ./run_tmp | grep 'sd' >> ./last_sd;
  done
  ./pp ./mm_res_$j\_ > ./pic_sf_$j;
  cat last_sd | awk -F '\t' 'BEGIN { sum = 0; n = 0; }; {sum += $2; n++;}; END {printf("%d \n", sum / n);}' > mm_sf_sd_$j
done
