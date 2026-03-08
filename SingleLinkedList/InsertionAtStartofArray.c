#include <stdlib.h>
#include <stdio.h>
int AddAtStart(int arr[],int n,int data);
int main()
{
    int n ,i;
    printf("Enter the number of Elemets ");
    scanf("%d", &n);
    int arr[10];
    for(i = 0 ; i<n ; i++)
    { 
        printf("Enter Element : ");
        scanf("%d", &arr[i]);
    }
                     
    n = AddAtStart (arr , n , 24);

    for(int i = 0 ; i < n ; i ++)
    {
        printf("%d,%s" , arr[i], "  ");
    }
    return 0;
}
int AddAtStart(int arr[], int n , int data)
{
   for(int s = n - 1; s >= 0 ; s--)
   {
        arr[s+1] = arr[s];
   }
   arr[0] = data;
   return n + 1; 
}