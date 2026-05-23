#include <iostream>

using namespace std;

struct Node
{
    int data;
    int height;
    Node* left;
    Node* right;
};Node* root;

int Height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int lHeight = Height(root->left);
    int rHeight = Height(root->right);

    return max(lHeight,rHeight) + 1;
}

int BalanceFactor(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int lHeight = Height(root->left);
    int rHeight = Height(root->right);

    return lHeight - rHeight;
}
Node* LLRotation(Node* ptr)
{
    Node* ptrLchild = ptr->left;
    Node* ptrLRchild = ptrLchild->right;

    ptrLchild->right = ptr;
    ptr->left = ptrLRchild;

    ptr->height = Height(ptr);
    ptrLchild->height = Height(ptr);
    
    if(ptr == root)
    {
        root = ptrLchild;
    }

    return root;
}
Node* RRRotation(Node* ptr)
{
    Node* ptrR = ptr->right;
    Node* ptrRL = ptrR->left;

    ptrR->left = ptr;
    ptr->right = ptrRL;

    ptr->height = Height(ptr);
    ptrR->height = Height(ptrR);

    if(ptr == root)
    {
        root = ptrR;
    }

    return root;
}
Node* RLRotation(Node* ptr)
{
    Node* ptrR = ptr->right;
    Node* ptrRL = ptrR->left;

    ptr->right = ptrRL->left;
    ptrR->left = ptrRL->right;

    ptrRL->left = ptr;
    ptrRL->right = ptrR;

    ptr->height = Height(ptr);
    ptrR->height = Height(ptrR);
    ptrRL->height = Height(ptrRL);

    if(root == ptrRL)
    {
        root = ptrRL;
    }
    return ptrRL;
}
Node* LRRotation(Node* ptr)
{
    Node* ptrL = ptr->left;
    Node* ptrLR = ptrL->right;

    ptrL->right = ptrLR->left;
    ptr->left = ptrLR->right;

    ptrLR->left = ptrL;
    ptrLR->right = ptr;

    ptr->height = Height(ptr);
    ptrL->height = Height(ptrL);
    ptrLR->height = Height(ptrLR);

    if(root == ptrLR)
    {
        root = ptrLR;
    }
    return ptrLR;
}

Node* Insert(Node* root , int data)
{
    Node* ptr = new Node();
    ptr->data = data;
    ptr->height = 1;
    ptr->left = NULL;
    ptr->right = NULL;

    if(root == NULL)
    {
        return ptr;
    }
    else if(root->data > data)
    {
        root->left = Insert(root->left , data);
    }
    else if(root->data < data)
    {
        root->right = Insert(root->right , data);
    }
    root->height = Height(root);

    if(BalanceFactor(root) == 2 && BalanceFactor(root->left) == 1)
    {
        return LLRotation(root);
    }
    else if(BalanceFactor(root) == -2 && BalanceFactor(root->right) == -1)
    {
        return RRRotation(root);
    }
    else if(BalanceFactor(root) == 2 && BalanceFactor(root->left) == -1)
    {
        return LRRotation(root);
    }
    else if(BalanceFactor(root) == -2 && BalanceFactor(root->right) == 1)
    {
        return RLRotation(root);
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
    cout<<root->data<<" ";
    InOrder(root->right);
}
int main()
{
    root = Insert(root,30);
    root = Insert(root,10);
    root = Insert(root,20);

    InOrder(root);
    return 0;
}