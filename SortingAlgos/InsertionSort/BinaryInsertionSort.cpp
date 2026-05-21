#include <iostream>

using namespace std;

int BinarySearch(int A[] , int key , int low , int high)
{
    while(low <= high )
    {
        int mid = (low + high)/2;

        if(A[mid] == key)
        {
            return mid +1;
        }
        else if(A[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    
    return low;
}
void InsertionSort(int A[] , int n)
{
    for(int i = 1 ; i < n ; i ++)
    {
        int j = i -1;
        int x = A[i];

        int pos = BinarySearch(A,x,0,j);

        while(j >= pos)
        {
            if(A[j] > x)
            {
                A[j+1] = A[j];
                j --;
            }
        }
        A[j+1] = x;
    }
}
void Print(int A[], int n)
{
    for(int i = 0; i < n ; i ++)
    {
        cout<<A[i]<<" ";
    }cout<<endl;
}
int main()
{
    int n = 5;
    int A[n] = {8,4,1,9,3};

    Print(A,n);
    InsertionSort(A,n);
    Print(A,n);
    return 0;
}