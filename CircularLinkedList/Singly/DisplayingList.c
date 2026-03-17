#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node* Create(int arr[] , int n);
void Display(struct Node *head);
void RecursionDisplay(struct Node *p,struct Node *head);
int main()
{
    int n = 5;
    int array[] = {1,2,3,4,5};

    struct Node *Head = Create(array , n);
    Display(Head);
    struct Node *p = Head;
    RecursionDisplay( p , Head);
}
struct Node* Create(int arr[] , int n)
{
    struct Node *ptr , *last;
    struct Node *Head = (struct Node*)malloc(sizeof(struct Node));
    Head -> data = arr[0];
    Head -> next = Head;
    last = Head;

    for(int i = 1; i < n ; i ++)
    {
        ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr -> data = arr[i];
        ptr -> next = last ->next;
        last -> next = ptr;
        last = ptr;
    }

    return Head;
}
void Display(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d,%s" , ptr -> data , " ");
        ptr = ptr -> next;
    }
    while(ptr != head);
}
void RecursionDisplay(struct Node *p , struct Node *head)
{
    static int flag = 0;
    if(p != head || flag == 0 )
    {
        flag = 1;
        printf("%d,%s" , p->data , " ");
        RecursionDisplay(p->next , head);
    }
    flag = 0;
}