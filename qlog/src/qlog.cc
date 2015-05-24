#include "qlog.h"

qf_confdata* g_confdata;

int main()
{
    int ret;

    g_confdata = init_conf(1024);
    read_conf("./conf/qlog.conf", g_confdata);
    int age = 0;
    ret = get_confint(g_confdata, "age", &age);
    pint(age);
    char name[WORD_SIZE];
    ret = get_confstr(g_confdata, "name", name);
    if (ret != 0) {
        log_err("get_conf name error");
        return 1;
    }
    free(g_confdata);

    return 0;
}
