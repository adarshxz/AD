#include<stdio.h>
void main()
{
    int a = 35, b = 15, c = 25, d, e;
    d = a > c > b;
    e = c-b > a <= d;
    printf("The value of d is %d\n", d);
    printf("The value of e is %d\n", e);
return 0;
}
