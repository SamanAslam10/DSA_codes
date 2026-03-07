#include <stdio.h>
#include <stdlib.h>
// without traversal
struct Node
{
    int data;
    struct Node *link;
};
struct Node* InsertAtEnd(struct Node *ptr , int data);
int main()
{
    struct Node *Head = NULL;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head -> data = 10;
    Head -> link = NULL;
    
    struct Node *ptr = Head;
    ptr = InsertAtEnd(ptr , 20);
    ptr = InsertAtEnd(ptr , 30);
    ptr = InsertAtEnd(ptr , 40);

    ptr = Head;
}
struct Node* InsertAtEnd(struct Node *ptr , int data)
{
    struct Node *temp = NULL;
    temp = (struct Node*)malloc(sizeof(struct Node));

    temp -> data = data;
    temp -> link = NULL;

    ptr -> link = temp;
    return temp;    
}