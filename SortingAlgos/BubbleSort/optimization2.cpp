#include <iostream>

using namespace std;

void BubbleSort(int A[] , int n)
{
    int lastSwappedIndex;
    int end = n - 1;

    while(end > 0)
    {
        lastSwappedIndex = 0;
        for(int i = 0 ; i < end ; i ++)
        {
            if(A[i] > A[i+1])
            {
                int temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                lastSwappedIndex = i;
            }
        }
        end = lastSwappedIndex;
    }
}
void Print(int A[] , int n )
{
    for(int j = 0 ; j < n ; j ++)
    {
        cout<<A[j]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n = 5;
    int A[n] ={5,1,4,2,8};
    
    Print(A,n);
    BubbleSort(A,n);
    Print(A,n);
    return 0;
}