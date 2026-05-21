#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ;
    int *arr;

    printf("Enter n : ");
    scanf("%d",&n);

    arr = (int*) malloc(n * sizeof(int));

    if(arr == NULL)
    {
        printf("Allocation of memory failed :(");       
    }
    
    for(int i = 0 ; i < n ; i ++)
    {
        arr[i] = i;
    }

    int doublevalue = 2 * n;
    int *temp;
    temp = realloc(arr,doublevalue * sizeof(int));

    if(temp != NULL)
    {
        arr = temp;
    }
    else
    {
        printf("Reallocation of memory failed :(");
    }

    free(arr);
    arr = NULL;
}