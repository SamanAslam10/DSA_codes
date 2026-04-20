#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 4, 6, 8};
    int n = 4, key = 6;

    int low = 0, high = n - 1;
    bool found = false;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            found = true;
            break;
        }
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    if (found) cout << "Exists";
    else cout << "Does not exist";
}