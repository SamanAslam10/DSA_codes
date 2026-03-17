#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
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