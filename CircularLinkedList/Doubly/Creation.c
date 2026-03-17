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
}