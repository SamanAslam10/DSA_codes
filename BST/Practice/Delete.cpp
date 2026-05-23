#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* lchild;
    Node* rchild;

    Node(int value)
    {
        data = value;
        lchild = NULL;
        rchild = NULL;
    }
};

Node* Insert(Node* root, int data)
{
    Node* newNode = new Node(data);
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    if(root == NULL)
    {
        return newNode;
    }
    if(root->data > data)
    {
        root->lchild = Insert(root->lchild,data);
    }
    else if(root->data < data)
    {
        root->rchild = Insert(root->rchild,data);
    }

    return root;
}
int Height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int lheight = Height(root->lchild);
    int rheight = Height(root->rchild);
    return max(lheight,rheight);
}
Node* Inpredecessor(Node* root)
{
    while(root && root->lchild != NULL)
    {
        root = root->lchild;
    }
    return root;
}
Node* InSuccessor(Node* root)
{
    while(root && root->rchild != NULL)
    {
        root = root->rchild;
    }
    return root;
}
Node* Delete(Node* root,int key)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->lchild == NULL && root->rchild == NULL)
    {
        free(root);
        return NULL;
    }
    if(root->data > key)
    {
        root->lchild = Delete(root->lchild , key);
    }
    else if(root->data < key)
    {
        root->rchild = Delete(root->rchild, key);
    }
    else
    {
        Node* ptr;
        if(Height(root->lchild) > Height(root->rchild))
        {
            ptr = Inpredecessor(root->lchild);
            root->data = ptr->data;
            root->lchild = Delete(root->lchild,ptr->data);
        }
        else
        {
            ptr = InSuccessor(root->rchild);
            root->data = ptr->data;
            root->rchild = Delete(root->rchild, ptr->data);
        }
    }
    return root;
}
void Inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    Inorder(root->lchild);
    cout<<root->data<<" ";
    Inorder(root->rchild);
}
int main()
{
    Node* root = new Node(45);

    Insert(root,25);
    Insert(root,65);
    Insert(root,15);
    Insert(root,35);
    Insert(root,55);
    Insert(root,75);

    Inorder(root);
    cout<<endl;
    Delete(root,15);

    Inorder(root);
    cout<<endl;
    Delete(root,65);

    Inorder(root);
    return 0;
}