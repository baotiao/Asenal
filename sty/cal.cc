#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
  double a = atof(argv[1]);
  a = exp(a);
  printf("%lf\n", a);
  return 0;
}
