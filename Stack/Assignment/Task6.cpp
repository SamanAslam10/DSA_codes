#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    stack<char> s;

    cout << "Enter a string: ";
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    bool isPalindrome = true;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != s.top()) {
            isPalindrome = false;
            break;
        }
        s.pop();
    }

    if (isPalindrome)
        cout << str << " is palindrome";
    else
        cout << str << " is not palindrome";

    return 0;
}