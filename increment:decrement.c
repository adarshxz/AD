#include<stdio.h>
int main()
{
    int a = 10, b, b1;
    b = ++a;
    b1 = a++;
    b--;
    --b1;
    b-=b1;
    printf("%D", b);

    return 0;
}