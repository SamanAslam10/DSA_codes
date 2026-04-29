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
    Node *root = new Node(1);

    Node* c1 = new Node(2);
    Node* c2 = new Node(3);
    Node* c3 = new Node(4);

    root ->childern.push_back(c1);
    root ->childern.push_back(c2);
    root ->childern.push_back(c3);

    Node* c5 = new Node(5);
    Node* c6 = new Node(6);
    c1->childern.push_back(c5);
    c3->childern.push_back(c6);

    cout<<"Printing Nodes: ";
    PrintTree(root);

    return 0;
}