#include <iostream>

using namespace std;

void InsertionSort(int A[] , int n)
{
    for(int i = 1; i < n ; i ++)
    {
        int j = i - 1;
        int x = A[i];

        while( j> -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j --; 
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