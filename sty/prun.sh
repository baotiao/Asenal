#!/bin/sh


# for ((j = 0; j < 101; j=( $j + 10) ))
# do
#   rm -rf *_res;
#   for ((i = 0; i < 100; i=( $i + 1) ))
#   do
#     ./m1 $j | tail -1 >> m1_res;
#   done
#   cat m1_res | awk -F ',' 'BEGIN { sum = 0; n = 0; }; {sum += $4; n++;}; END {printf("%d \n", sum / n);}' >> model1_r_$j
# done

rm -rf *_res;
for ((j = 0; j < 101; j=( $j + 5) ))
do
  rm -rf model21_r;
  for ((i = 0; i < 100; i=( $i + 1) ))
  do
    ./m21 $j | tail -1 >> m21_res;
  done
  cat m21_res | awk -F ',' 'BEGIN { sum = 0; n = 0; }; {sum += $2; n++;}; END {printf("%d \n", sum / n);}' >> model21_r;
done

for ((j = 0; j < 101; j=( $j + 5) ))
do
  rm -rf model22_r;
  for ((i = 0; i < 100; i=( $i + 1) ))
  do
    ./m22 $j | tail -1 >> m22_res;
  done
  cat m22_res | awk -F ',' 'BEGIN { sum = 0; n = 0; }; {sum += $2; n++;}; END {printf("%d \n", sum / n);}' >> model22_r;
done

for ((j = 0; j < 101; j=( $j + 5) ))
do
  rm -rf model31_r;
  for ((i = 0; i < 100; i=( $i + 1) ))
  do
    ./m31 $j | tail -1 >> m31_res;
  done
  cat m31_res | awk -F ',' 'BEGIN { sum = 0; n = 0; }; {sum += $2; n++;}; END {printf("%d \n", sum / n);}' >> model31_r;
done

for ((j = 0; j < 101; j=( $j + 5) ))
do
  rm -rf model32_r;
  for ((i = 0; i < 100; i=( $i + 1) ))
  do
    ./m32 $j | tail -1 >> m32_res;
  done
  cat m32_res | awk -F ',' 'BEGIN { sum = 0; n = 0; }; {sum += $2; n++;}; END {printf("%d \n", sum / n);}' >> model32_r;
done

# for ((i = 0; i < 100; i=( $i + 1) ))
# do
#   ./m21 | tail -1 >> m21_res;
# done

# cat m21_res | awk -F ',' 'BEGIN { sum = 0; n = 0; }; {sum += $2; n++;}; END {printf("%d \n", sum / n);}' > m21t

# for ((i = 0; i < 100; i=( $i + 1) ))
# do
#   ./m22 | tail -1 >> m22_res;
# done

# cat m22_res | awk -F ',' 'BEGIN { sum = 0; n = 0; }; {sum += $2; n++;}; END {printf("%d \n", sum / n);}' > m22t
# for ((i = 0; i < 100; i=( $i + 1) ))
# do
#   ./m31 | tail -1 >> m31_res;
# done

# cat m31_res | awk -F ',' 'BEGIN { sum = 0; n = 0; }; {sum += $2; n++;}; END {printf("%d \n", sum / n);}' > m31t
# for ((i = 0; i < 100; i=( $i + 1) ))
# do
#   ./m32 | tail -1 >> m32_res;
# done

# cat m32_res | awk -F ',' 'BEGIN { sum = 0; n = 0; }; {sum += $2; n++;}; END {printf("%d \n", sum / n);}' > m32t
