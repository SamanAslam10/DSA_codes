#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key) return mid;
    else if (arr[mid] < key) return binarySearch(arr, mid + 1, high, key);
    else return binarySearch(arr, low, mid - 1, key);
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = 5, key = 6;

    cout << "Index: " << binarySearch(arr, 0, n - 1, key);
}