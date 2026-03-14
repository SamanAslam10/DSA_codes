#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node* AddAtEnd(struct Node *Head,int data);
struct Node* AddAtBegining(struct Node *Head,int data);
struct Node* ReverseList(struct Node *Head);
int main()
{
    struct Node *Head = AddAtBegining(Head , 25);
    Head = AddAtEnd(Head , 35);
    Head = AddAtEnd(Head , 45);

    Head = ReverseList(Head);
    struct Node *temp = Head;
    while(temp != NULL)
    {
        printf("%d,%s" , temp -> data , "  ");
        temp = temp -> next;
    }

    return 0;
}
struct Node* AddAtBegining(struct Node *Head,int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = NULL;
    ptr -> prev = NULL;

    Head = ptr;
    return Head;
}
struct Node* AddAtEnd(struct Node *Head,int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = NULL;
    ptr -> prev = NULL;

    struct Node *temp = Head;
    while(temp->next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = ptr;
    ptr -> prev = temp;

    return Head;
}
struct Node* ReverseList(struct Node *Head)
{
    struct Node *p1 = Head;
    struct Node *p2 = p1->next;

    p1 -> next = NULL;
    p1 -> prev = p2;
    while(p2 != NULL)
    {
        p2 -> prev = p2 ->next;
        p2 -> next = p1;

        p1 = p2;
        p2 = p2 -> prev;

    }
    Head = p1;
    return Head;
}