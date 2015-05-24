#include<stdio.h>
class Date {
    int y,m,d;
public:
    int h;
    Date(int yy = 1989, int mm = 10, int dd = 12); //这里要注意构造函数前面不要加类型.
    void add_year();
    int get_y() const; //加上const 表示这个函数不可以改变类里面参数的变量的值,无论是Public还是private都不可以.
};
Date::Date(int yy, int mm, int dd)
{
    y = yy;
    m = mm;
    d = dd;
}
void Date::add_year() // 这里如果加上参数int y, 就不会改变类里面y的值了.
{
    h++;
    y++;
}
int Date::get_y() const // 当设置成了const以后,如果这里面对类的值改变了.就会报错.
{
    //y++;
    return y;
}
int main()
{
    Date d(1988,5,31);
    d.h = 10;
    d.add_year();
    printf("%d \n", d.get_y());
    printf("%d \n", d.h);
    Date d1 = d;
    d1.add_year();
    printf("%d \n", d1.get_y());
    return 0;
}
