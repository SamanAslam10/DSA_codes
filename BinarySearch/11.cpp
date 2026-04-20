#include <iostream>
using namespace std;

int main() {
    int arr[] = {4,5,6,7,0,1,2};
    int n = 7, key = 0;

    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            cout << "Index: " << mid;
            return 0;
        }

        if (arr[low] <= arr[mid]) {
            if (key >= arr[low] && key < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } else {
            if (key > arr[mid] && key <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    cout << "Not found";
}