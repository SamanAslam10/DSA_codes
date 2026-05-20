#include <iostream>

using namespace std;

int main()
{
    int n = 5;
    int A[n] = {5,1,4,2,8};

    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j <= n-2 ; j ++)
        {
            if(A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                break;
            }
        }
    }

    for(int i = 0 ; i < n ; i ++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}