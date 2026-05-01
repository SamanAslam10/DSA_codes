#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    vector<Node*> childern;

    Node(int value)
    {
        data = value;
    }
};

void PrintTree(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";

    for(Node* child : root->childern)
    {
        PrintTree(child);
    }
}
int main()
{

    Node* root = new Node(10);

    Node* child1 = new Node(20);
    Node* child2 = new Node(30);

    root->childern.push_back(child1);
    root->childern.push_back(child2);


    PrintTree(root);
    return 0;
}