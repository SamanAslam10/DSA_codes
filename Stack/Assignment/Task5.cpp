#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    stack<int> s;

    cout << "Enter a decimal number: ";
    cin >> n;

    if (n == 0) 
    { 
        cout << "Binary: 0";
        return 0;
    }

    while (n > 0) 
    {
        int remainder = n % 2;
        s.push(remainder);
        n = n / 2;
    }

    cout << "Binary: ";
    while (!s.empty()) 
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}