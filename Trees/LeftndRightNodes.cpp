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

int CountLeftNodes(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int count = 0;
    if(!root->childern.empty())
    {
        count += 1;
    }

    for(Node* child : root->childern)
    {
        count += CountLeftNodes(child);
    }
    
    return count;
}
int CountRightNodes(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int count = 0;
    if(!root->childern.empty())
    {
        count += 1;
    }

    for(Node* child : root->childern)
    {
        count += CountRightNodes(child);
    }
    
    return count;
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

    cout<<"Number of Left Nodes: "<<CountLeftNodes(root)<<endl;
    cout<<"Number of Right Nodes: "<<CountRightNodes(root);
    return 0;
}