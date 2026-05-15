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
bool IdenticalBST(Node* r1 , Node* r2)
{
    if(r1 == NULL || r2 == NULL)
    {
        return false;
    }
    if(r1->data == r2->data )
    {
        return true;
    }
    return IdenticalBST(r1->left,r2->left) && IdenticalBST(r2->left,r2->right); 
}
int main()
{
    Node* root = NULL;
    root = new Node(45);
    Insert(root,25);
    Insert(root,65);
    Insert(root,15);

    Node* root2 = NULL;
    root2 = new Node(45);
    Insert(root2,25);
    Insert(root2,65);
    Insert(root2,15);

    if(IdenticalBST(root,root2))
    {
        cout<<"Identical";
    }
    else
    {
        cout<<"Not Identical";
    }
    return 0;
}