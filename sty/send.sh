#!/bin/sh

files=`ls mm_*_sd*`

rm ./sd_res

for file in $files
do
  echo $file `cat $file`  >> ./sd_res
done
