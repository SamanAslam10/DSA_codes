#include <iostream>
#include <queue>

using namespace std;

void GenerateBinaryNumbers(int n)
{
    queue<string> BinaryNumbers;
    BinaryNumbers.push("1");
    for(int i = 0; i < n ; i ++)
    {
        string current = BinaryNumbers.front();
        BinaryNumbers.pop();

        cout<<current<<endl;

        BinaryNumbers.push(current + "0");
        BinaryNumbers.push(current + "1");
    }
}
int main()
{
    int n = 0;
    cout<<"Enter the number of Binary Numbers : ";
    cin>>n;

    GenerateBinaryNumbers(n);

    return 0;
}