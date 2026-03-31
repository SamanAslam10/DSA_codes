#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

void NonRepeatingCharInStream(string stream)
{
    queue<char> characters;
    unordered_map<char,int> frequency;

    for (char c : stream)
    {   
        frequency[c] += 1;
        characters.push(c);
        
        while(!characters.empty() && frequency[c] > 1)
        {
            characters.pop();
        }
        if(characters.empty())
        {
            cout<<"-1";
        }
        else
        {
            cout<<characters.front()<<" ";
        }
    }
}
int main()
{
    string stream;
    cout<<"Enter the stream of characters : ";
    cin>>stream;

    NonRepeatingCharInStream(stream);
    return 0;
}