#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5, key = 10;

    int low = 0, high = n - 1, found = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            found = mid;
            break;
        }
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    cout << "Result: " << found;
}