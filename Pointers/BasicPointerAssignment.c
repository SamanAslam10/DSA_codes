#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 10;
    int *p = &x;
    int y = *p;
    *p = 20;

    printf("%d,%d,%d" , x , p , y);

}