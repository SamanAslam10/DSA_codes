#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(array)/sizeof(array[0]);
    size = size - 1;
    for(int i = 0 ; i < size ; i ++)
    {
        printf("%d, %s" , array[i] , "  ");
    }

    return 0;
}