#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> slidingWindowMax(vector<int> &arr, int k)
{
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++)
    {
        // Remove out of window elements
        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        // Remove smaller elements
        while (!dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }

        // Add current index
        dq.push_back(i);

        // Store result
        if (i >= k - 1)
        {
            result.push_back(arr[dq.front()]);
        }
    }

    return result;
}

int main()
{
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> res = slidingWindowMax(arr, k);

    cout << "Output: ";
    for (int x : res)
        cout << x << " ";

    return 0;
}