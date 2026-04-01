#include <iostream>
#include <queue>

using namespace std;

void SlidingWindowMaximum(int i ,int arr[] , int k)
{
    queue<int> q;

    for(i; i < k ; i ++ )
    {
        q.push(arr[i]);
    }
    int max =0;
        max = q.front();
        q.pop();
        for(int i = 0; i < k ; i ++ )
        {
            if(max < q.front() )
            {
                max = q.front();
            }
            q.pop();
        }
    cout<<max<<" ";
    SlidingWindowMaximum(i+1,arr , k+1);
}
int main()
{
    int k,n = 0;

    cout<<"Enter the no. of elements you want to enter: ";
    cin>>n;

    int arrInput[n];

    for(int i = 0 ; i < n ; i ++)
    {
        cout<<"Enter value : ";
        cin>>arrInput[i];
    }
    cout<<"Enter the value of k : ";
    cin>>k;

    SlidingWindowMaximum(0,arrInput , k);

    return 0;
}