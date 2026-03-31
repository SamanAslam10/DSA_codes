#include <iostream>
#include <queue>

using namespace std;

void GenerateBinary(int n)
{
    queue<string> Binary;
    Binary.push("1");

    for(int i = 0; i < n ; i ++)
    {
        string current = Binary.front();
        Binary.pop();

        cout<<current<<endl;

        Binary.push(current + "0");
        Binary.push(current + "1");
    }
}
int main()
{
    GenerateBinary(100);
    return 0;
}