#make clean
#make
echo $1 $2
./ptest aptest.conf $1 $2
./ptest ptest.conf $1 $2
