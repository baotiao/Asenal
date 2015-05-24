ls -1 include/comlog/*.h | awk '{printf "sed \047s/u_int64/unsigned long long/g\047 %s >%s.sed;mv %s.sed %s\n", $1, $1, $1, $1;}' | sh
ls -1 src/comlog/*.cpp src/comlog/*/*.cpp | awk '{printf "sed \047s/u_int64/unsigned long long/g\047 %s >%s.sed;mv %s.sed %s\n", $1, $1, $1, $1;}' | sh
ls -1 include/comlog/*.h | awk '{printf "sed \047s/#ifndef\\sunsigned\\slong\\slong/\\/\\/#ifndef u_int64/g\047 %s >%s.sed;mv %s.sed %s\n", $1, $1, $1, $1;}' | sh
ls -1 include/comlog/*.h | awk '{printf "sed \047s/#define\\sunsigned\\slong\\slong\\sunsigned\\slong\\slong/\\/\\/#define u_int64 unsigned long long/g\047 %s >%s.sed;mv %s.sed %s\n", $1, $1, $1, $1;}' | sh

