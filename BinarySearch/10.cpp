#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,2,2,3};
    int n = 5, key = 2;

    int first = -1, last = -1;

    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    if (first == -1) cout << "Count: 0";
    else cout << "Count: " << last - first + 1;
}