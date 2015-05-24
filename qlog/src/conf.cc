#include "conf.h"

qf_confdata* init_conf(int conf_len)
{
    qf_confdata* confdata;
    confdata = (qf_confdata* )malloc(sizeof(qf_confdata));

    confdata->size = conf_len;

    qf_check(confdata != NULL, "confdata is errlr");
    if (conf_len < CONF_LEN) {
        confdata->size = CONF_LEN;
    }
    confdata->item = (qf_confitem* )calloc(sizeof(qf_confitem), confdata->size);
    if (confdata->item == NULL) {
        log_err("calloc confdata error");
    }
    return confdata;
}

int read_conf(const char* path, qf_confdata* confdata) 
{
    qf_check(confdata != NULL, "confdata is errlr");
    struct stat info;
    FILE* pf;

    int val = stat(path, &info);
    pstr(path);

    if (val < 0) {
        log_err("stat error");
    }
    if (S_ISREG(info.st_mode)) {
        qf_debug("regular file");
    }
    pint(info.st_uid);

    pf = fopen(path, "r");
    if (pf == NULL) {
        log_err("open file error");
    }

    // read conf items
    int item_num = 0;
    char line[WORD_SIZE];
    char ch = 0;
    int line_len = 0;
    char c_name[WORD_SIZE];
    char c_value[WORD_SIZE];
    int sep_sign = 0;
    int name_len = 0;
    int value_len = 0;

    while (fgets(line, WORD_SIZE, pf) != NULL) {
        name_len = 0;
        value_len = 0;
        sep_sign = 0;
        pstr(line);
        line_len = strlen(line);
        pint(line_len);
        for (int i = 0; i < line_len; i++) {
            ch = line[i];
            switch (ch) {
                case '#': {
                    if (i == 0) {
                        continue;
                    }
                }
                case ':': {
                    sep_sign = 1;
                }
                case SPACE: {
                    continue;
                }
                case '\r': {
                    continue;
                }
                case '\n': {
                    continue;
                }
                default: {
                    if (sep_sign == 0) {
                        c_name[name_len++] = line[i];
                    } else {
                        c_value[value_len++] = line[i];
                    }
                }
            }
        }
        c_name[name_len] = '\0';
        c_value[value_len] = '\0';
        
        pstr(c_name);
        qf_check(confdata != NULL, "confdata NULL");
        qf_check(confdata->item != NULL, "confdata item NULL");
        pstr(c_value);
        snprintf(confdata->item[item_num].name, sizeof(confdata->item[item_num].name), "%s", c_name);
        snprintf(confdata->item[item_num].value, sizeof(confdata->item[item_num].value), "%s", c_value);
        item_num++;
        pint(strlen(c_name));
        pint(strlen(c_value));
    }
    confdata->num = item_num;
    return 0;
}

void dump_conf(qf_confdata *confdata)
{
    for (int i = 0; i < confdata->num; i++) {
        printf("line %d %s %s\n", i + 1, confdata->item[i].name, confdata->item[i].value);
    }
}

int get_confint(qf_confdata *confdata, const char* name, int* value)
{
    int ret;
    pint(confdata->num);
    for (int i = 0; i < confdata->num; i++) {
        pstr(confdata->item[i].name);
        pstr(name);
        if (strcmp(confdata->item[i].name, name) == 0) {
            sentinel("come in the equal");
            pstr(confdata->item[i].value);
            sscanf(confdata->item[i].value, "%d", &ret);
            *value = ret;
            pint(ret);
            return 0;
        }
    }
    pint(ret);
    return 1;
}

int get_confstr(qf_confdata *confdata, const char* name, char* value)
{
    for (int i = 0; i < confdata->num; i++) {
        if (strcmp(confdata->item[i].name, name) == 0) {
            strcpy(value, confdata->item[i].value);
            return 0;
        }
    }
    return 1;
}

int free_conf(qf_confdata *confdata) 
{
    if (confdata == NULL) {
        return 1;
    }

    if (confdata->item) {
        free(confdata->item);
    }

    free(confdata->item);
    return 0;
}
