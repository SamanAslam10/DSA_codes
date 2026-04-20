#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = 5, key = 9;

    int low = 0, high = n - 1, steps = 0;

    while (low <= high) {
        steps++;
        int mid = (low + high) / 2;

        if (arr[mid] == key) break;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    cout << "Steps: " << steps;
}