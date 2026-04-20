#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<float> v = {1.1, 2.2, 3.3, 4.4};
    float key = 3.3;

    int low = 0, high = v.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (v[mid] == key) {
            cout << "Found at index: " << mid;
            return 0;
        }
        else if (v[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    cout << "Not found";
}