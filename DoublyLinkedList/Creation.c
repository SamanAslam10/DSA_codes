#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;   
};

int main()
{
    struct Node *Head = (struct Node*)malloc(sizeof(struct Node));
    Head -> data = 10;
    Head -> prev = NULL;
    Head -> next = NULL;

    struct Node *Current = (struct Node*)malloc(sizeof(struct Node));
    Current -> data = 20;
    Current -> prev = Head;
    Current -> next = NULL;
    Head -> next = Current;
}