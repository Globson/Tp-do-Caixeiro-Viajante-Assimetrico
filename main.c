#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[]) {
  int a=1,b=2,*c,d;
  c=&a;
  d=*c+b+b;
  *c=d;
printf("Os valores sao: %d %d %d %d",a,b,*c,d);
  return 0;
}
