#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,2,2,3};
    int n = 5, key = 2;

    int low = 0, high = n - 1, res = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            res = mid;
            high = mid - 1;
        }
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    cout << "First occurrence: " << res;
}