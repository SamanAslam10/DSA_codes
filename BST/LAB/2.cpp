#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* Insert(Node* root, int value)
{
    if(root == NULL)
    {
        return new Node(value);
    }
    if(value > root->data)
    {
        root->right = Insert(root->right , value);
    }
    else if(value < root->data)
    {
        root->left = Insert(root->left , value);
    }
    return root;
}

bool Search(Node* root , int value)
{

    if(root == NULL)
    {
        return false;
    }
    if(root->data == value)
    {
        return true;
    }
    if(root->data > value)
    {
        Search(root->left,value);
    }
    else if(root->data < value)
    {
        Search(root->right,value);
    }
    return false;
}
int main()
{
    Node* root = NULL;
    root = new Node(45);
    Insert(root,25);
    Insert(root,65);
    Insert(root,15);
    Insert(root,35);
    Insert(root,55);
    Insert(root,75);

    int value;
    cout<<"Enter the value u want to search: ";
    cin>>value;

    bool Searchresult = Search(root,value);
    if(Searchresult == true)
    {
        cout<<"found";
    }
    else
    {
        cout<<"not found";
    }
    return 0;
}