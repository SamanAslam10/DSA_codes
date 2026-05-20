#include <iostream>

using namespace std;

int main()
{
    int n = 5;
    int A[n] = {5,1,4,2,8};

    int end = -1;
    while(end > 0)
    {
        for(int j = 0 ; j < n ; j ++)
        {
            if(A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
        end = 1;
    }

    for(int j = 0 ; j < n ; j ++)
    {
        cout<<A[j]<<" ";
    }
}