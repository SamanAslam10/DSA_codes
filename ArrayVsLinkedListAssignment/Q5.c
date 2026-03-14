#include <stdio.h>

void reverse(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    int temp;

    while(start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = 5;

    reverse(arr,n);

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}