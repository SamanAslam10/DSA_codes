#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void InsertAtCertainPosition(struct Node *Head , int data , int position );
int main()
{
    struct Node *Head = NULL;
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head -> data = 10;
    Head -> next = NULL;

    struct Node *Current = NULL;
    Current = (struct Node*)malloc(sizeof(struct Node));
    Current -> data = 20;
    Current -> next = NULL;

    Head ->next = Current;

    Current = (struct Node*)malloc(sizeof(struct Node));
    Current -> data = 30;
    Current -> next = NULL;

    Head -> next -> next = Current;

    Current = (struct Node*)malloc(sizeof(struct Node));
    Current -> data = 50;
    Current -> next = NULL;

    Head -> next -> next -> next = Current;

    InsertAtCertainPosition(Head , 40 , 4);

    struct Node *ptr = Head;
    while(ptr != NULL)
    {
        printf("%d , %s" , ptr->data , "  " );
        ptr = ptr ->next;
    }
    
    return 0;
}
void InsertAtCertainPosition(struct Node *Head , int data , int position )
{
    struct Node *ptr = NULL;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = NULL;
    
    struct Node *ptr2 = NULL;
    ptr2 = (struct Node*)malloc(sizeof(struct Node));
    ptr2 = Head;
    
    position --;
    while(position != 1)
    {
        ptr2 = ptr2 -> next;
        position--;
    }
    
    ptr->next = ptr2->next;
    ptr2->next = ptr;

}