#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node* Create(int arr[],int n)
{
    struct Node *ptr , *temp , *head;
    head = (struct Node*)malloc(sizeof(struct Node));
    head -> data = arr[0];
    head -> prev = head;
    head -> next = head;
}
int main()
{
    struct Node *Head =(struct Node*)malloc(sizeof(struct Node));
    Head -> data = 10;
    Head -> next = Head;
    Head -> prev = Head;

    struct Node *Current = (struct Node*)malloc(sizeof(struct Node));
    Current -> data = 20;
    Current -> next = Head;
    Current -> prev = Head;

    Head -> prev = Current;
    Head -> next = Current;
}