#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
}; 

int main()
{
    struct Node *Head = NULL;
    Head = (struct Node *)malloc(sizeof(struct Node));

    Head -> data = 100;
    Head -> link = NULL;

    printf("%d", Head->data);
}