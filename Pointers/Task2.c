#include <stdlib.h>
#include <stdio.h>

int main()
{
    int arr[4] = {10,20,30,40};
    int *p = &arr[0];

    //1
    printf("%d",*(p+2));
    printf("%s", " ");

    //2 
    for(int i=0 ; i < 4 ; i ++)
    {
        printf("%d",*(p+i));
        printf("%s", " ");       
    }

    //3 
    printf("%p" , *p);
    printf("%s", " ");
    printf("%p" , *(p+1));
    return 0;
}