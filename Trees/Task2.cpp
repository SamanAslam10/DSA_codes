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

void PreOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";

    for(Node* child : root->childern)
    {
        PreOrderTraversal(child);
    }
}

void InOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    if(!root->childern.empty())
    {
        InOrderTraversal(root->childern[0]);
    }

    cout<<root->data<<" ";

    for(int i = 1; i <root->childern.size() ; i ++)
    {
        InOrderTraversal(root->childern[i]);
    }
}
void PostOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    for(Node* child : root->childern)
    {
        PostOrderTraversal(child);
    }

    cout<<root->data<<" ";
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
    c2->childern.push_back(c5);
    c3->childern.push_back(c6);

    cout<<"PreOrder: ";
    PreOrderTraversal(root);
    cout<<endl;

    cout<<"InOrder: ";
    InOrderTraversal(root);
    cout<<endl;

    cout<<"Post Order: ";
    PostOrderTraversal(root);
    cout<<endl;

    return 0;
}