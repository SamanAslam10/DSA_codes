#include <stdio.h>

int main()
{
    int s = 4;
    int *ptr = &s;    

    printf("%d" , s);
    printf("%s" , " ");
    printf("%p" , &s);
    printf("%s" , " ");
    printf("%d" , *ptr);
    printf("%s" , " ");
    printf("%p" , ptr);

    return 0;
}