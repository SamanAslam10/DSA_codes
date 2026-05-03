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
bool ProperBinaryTree(Node* root)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return true;
    }
    if(root->left != NULL && root->right != NULL)
    {
        return ProperBinaryTree(root->left) &&
        ProperBinaryTree(root->right);
    }
    return false;
}
int main()
{
    Node* root = new Node(1);
    
    Node* c1 = new Node(2);
    Node* c2 = new Node(3);
    Node* c3 = new Node(4);
    Node* c4 = new Node(5);
    Node* c5 = new Node(6);
    Node* c6 = new Node(6);

    root->left = c1;
    root->right = c2;

    c1->left = c3;
    c1->right = c4;

    c2->left = c5;

    cout<<ProperBinaryTree(root);
    return 0;
}