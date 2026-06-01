#include <iostream>

using namespace std;

struct Node
{
    int data;
    int height;
    int balanceFactor;
    Node* lchild;
    Node* rchild;
};Node* root;

int Height(Node* ptr)
{
    if(ptr == NULL)
    {
        return 0;
    }
    int lheight = Height(ptr->lchild);
    int rheight = Height(ptr->rchild);

    return max(lheight,rheight) + 1;
}
int BalanceFactor(Node* ptr)
{
    if(ptr == NULL)
    {
        return 0;
    }
    int lheight = Height(ptr->lchild);
    int rheight = Height(ptr->rchild);

    return lheight - rheight;
}
Node* LLrotation(Node* ptr)
{
    Node* ptrL = ptr->lchild;
    Node* ptrLR = ptrL->rchild;

    ptr->lchild = ptrLR; 
    ptrL->rchild = ptr;

    ptr->height = Height(ptr);
    ptrL->height = Height(ptrL);

    if(root == ptr)
    {
        root = ptrL;
    }

    return ptrL;
}
Node* RRrotation(Node* ptr)
{
    Node* ptrR = ptr->rchild;
    Node* ptrRL = ptrR->lchild;

    ptrR->lchild = ptr;
    ptr->rchild = ptrRL;

    ptr->height = Height(ptr);
    ptrR->height = Height(ptrR);

    if(root == ptr)
    {
        root = ptrR;
    }

    return ptrR;
}
Node* LRrotation(Node* ptr)
{
    Node* ptrL = ptr->lchild;
    Node* ptrLR = ptrL->rchild;

    ptr->lchild = ptrLR->rchild;
    ptrL->rchild = ptrLR->lchild;

    ptrLR->rchild = ptr;
    ptrLR->lchild = ptrL;

    ptr->height = Height(ptr);
    ptrL->height = Height(ptrL);
    ptrLR->height = Height(ptrLR);

    if(root == ptr)
    {
        root = ptrLR;
    }

    return ptrLR;
}
Node* RLrotation(Node* ptr)
{
    Node* ptrR = ptr->rchild;
    Node* ptrRL = ptrR->lchild;

    ptr->rchild = ptrRL->lchild;
    ptrR->lchild = ptrRL->rchild;
    
    ptrRL->lchild = ptr;
    ptrRL->rchild = ptrR;

    ptr->height = Height(ptr);
    ptrRL->height = Height(ptrRL);
    ptrR->height = Height(ptrR);

    if(root == ptr)
    {
        root = ptrRL;
    } 

    return ptrRL;
}

Node* Insert(Node* root , int data)
{
    Node* ptr = new Node();
    ptr->data = data;
    ptr->height = 1;
    ptr->lchild = NULL;
    ptr->rchild = NULL;

    if(root == NULL)
    {
        return ptr;
    }
    else if(root->data > data)
    {
        root->lchild = Insert(root->lchild,data);
    }
    else if(root->data < data)
    {
        root->rchild = Insert(root->rchild,data);
    }
    root->height = Height(root);

    if(BalanceFactor(root) == 2 && BalanceFactor(root->lchild) == 1)
    {
        return LLrotation(root);
    }
    if(BalanceFactor(root) == 2 && BalanceFactor(root->lchild) == -1)
    {
        return LRrotation(root);
    }
    if(BalanceFactor(root) == -2 && BalanceFactor(root->rchild) == -1)
    {
        return RRrotation(root);
    }
    if(BalanceFactor(root) == -2 && BalanceFactor(root->rchild) == 1)
    {
        return RLrotation(root);
    }

    return root;
}
void InOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    InOrder(root->lchild);
    cout<<root->data<<" ";
    InOrder(root->rchild);
}
int main()
{
    root = Insert(root,30);
    root = Insert(root,10);
    root = Insert(root,20);

    InOrder(root);
    return 0;
}