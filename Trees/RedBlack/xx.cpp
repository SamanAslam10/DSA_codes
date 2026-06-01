#include <iostream>

using namespace std;

struct Node
{
    int data;
    char color;
    Node* left;
    Node* right;
    Node* parent;
};
Node* root = NULL;

Node* Create(int data)
{
    Node* ptr = new Node();
    ptr->data = data;
    ptr->color = 'R';
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->parent = NULL;

    return ptr;
}
void LeftRotate(Node*& root , Node* ptr)
{
    Node* ptrR = ptr->right;

    if(ptrR == NULL)
    {
        return;
    }
    ptr->right = ptrR->left;

    if(ptrR->left != NULL)
    {
        ptrR->left->parent = ptr;
    }

    ptrR->parent = ptr->parent;

    if(ptr->parent == NULL)
    {
        root = ptrR;
    }
    else if(ptr->parent->left == ptr)
    {
        ptr->parent->left = ptrR;
    }
    else
    {
        ptr->parent->right = ptrR;
    }

    ptrR->left = ptr;
    ptr->parent = ptrR;
}
void RightRotate(Node*& root , Node* ptr)
{
    Node* ptrL = ptr->left;

    if(ptrL == NULL)
    {
        return;
    }
    ptr->left = ptrL->right;

    if(ptrL->right != NULL)
    {
        ptrL->right->parent = ptr; 
    }

    if(ptr->parent == NULL)
    {
        root = ptrL;
    }
    else if(ptr->parent->left == ptr)
    {
        ptr->parent->left = ptrL;
    }
    else
    {
        ptr->parent->right = ptrL;
    }

    ptrL->right = ptr;
    ptr->parent = ptrL;
}
void fixVoilations(Node*& root , Node* ptr)
{
    Node* parent = NULL;
    Node* grandParent = NULL;

    while(ptr != root && ptr->parent != NULL && ptr->parent->color == 'R')
    {
        parent = ptr->parent;
        grandParent = parent->parent;

        if(parent == grandParent->left)
        {
            Node* uncle = grandParent->right;

            if(uncle != NULL && uncle->color == 'R')
            {
                uncle->color = 'B';
                parent->color = 'B';
                grandParent->color = 'R'; 

                ptr = grandParent;
            }
            else
            {
                if(ptr == parent->right)
                {
                    LeftRotate(root,parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                
                RightRotate(root, grandParent);

                swap(parent->color , grandParent->color);
                ptr = parent;
            }
        }
        else
        {
            Node* uncle = grandParent->left;

            if(uncle != NULL && uncle->color == 'R')
            {
                uncle->color = 'B';
                parent->color = 'B';
                grandParent->color = 'R'; 

                ptr = grandParent;
            }
            else
            {
                if(ptr == parent->left)
                {
                    RightRotate(root,parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                
                LeftRotate(root, grandParent);

                swap(parent->color , grandParent->color);
                ptr = parent;
            }
        }
    }

    root->color = 'B';
}
void insert(int data)
{
    Node* ptr = Create(data);

    Node* parent = NULL;
    Node* current = root;

    while(current != NULL)
    {
        parent = current;

        if(current->data > ptr->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    ptr->parent = parent;

    if(parent == NULL)
    {
        root = ptr;
        ptr->color = 'B';
        return;
    }

    else if(ptr->data > parent->data)
    {
        parent->right = ptr;
    }
    else
    {
        parent->left = ptr;
    }

    fixVoilations(root,ptr);
}

void Inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    Inorder(root->left);
    cout<<root->data<<" ( "<<root->color<<" )   ";
    Inorder(root->right);
}
int main()
{
    insert(10);
    insert(20);
    insert(30);

    Inorder(root);
    return 0;
}