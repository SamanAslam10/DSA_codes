#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    struct Node *Head = (struct Node*)malloc(sizeof(struct Node));
    Head -> data = 10;
    Head -> next = Head;
    
}