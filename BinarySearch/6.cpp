#include <iostream>
using namespace std;

int main() {
    string arr[] = {"apple", "banana", "cherry", "date"};
    int n = 4;
    string key = "cherry";

    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            cout << "Found at index: " << mid;
            return 0;
        }
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    cout << "Not found";
}