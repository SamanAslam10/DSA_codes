#include <iostream>
using namespace std;

int main() {
    int arr[] = {4,5,6,7,0,1,2};
    int n = 7;

    int low = 0, high = n - 1;

    while (low < high) {
        int mid = (low + high) / 2;

        if (arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }

    cout << "Minimum: " << arr[low];
}