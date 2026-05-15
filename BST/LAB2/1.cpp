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
Node* FindMin(Node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node* Delete(Node* root,int value)
{
    if(root == NULL)
    {
        return root;
    }
    if(root->data < value)
    {
        root->left = Delete(root->left,value);
    }
    else if(root->data > value)
    {
        root->right = Delete(root->right,value);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if(root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = FindMin(root->left);

        root->data = temp->data;
        root->left = Delete(root->left,temp->data);

        return root;
    }
    return root;
}
void InOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" , ";
    InOrder(root->right);
}
int main()
{
    Node* root = NULL;
    root = new Node(50);
    Insert(root,30);
    Insert(root,70);
    Insert(root,20);
    Insert(root,40);
    Insert(root,60);
    Insert(root,80);
    InOrder(root);
    cout<<endl;
    Delete(root,40);
    InOrder(root);
    return 0;
}