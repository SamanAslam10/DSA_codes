#include <stdio.h>
#include <stdlib.h>
int AddAtEnd(int data , int arr[], int free);
int main()
{
    int arr[10];

    int n, i;
    int free;
    printf("Enter the number of Elemets ");
    scanf("%d", &n);

    for(i = 0 ; i<n ; i++)
    { 
        printf("Enter the of Elemet : ");
        scanf("%d", &arr[i]);
    }
    free = i;
    free = AddAtEnd(65,arr,free);

    for(int a = 0 ; a < free ; a++)
    {
        printf("%d, %s",arr[a] , "  ");
    }
    return 0;
}
int AddAtEnd(int data , int arr[], int free)
{
    arr[free] = data;
    free ++;
    return free;
}