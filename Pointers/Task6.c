#include <stdio.h>

void f(int n)
{
    if(n==0) return;

    f(n-1);
    printf("%d ", n);
}

int main()
{ 
    int n = 4;
    f(n);
}