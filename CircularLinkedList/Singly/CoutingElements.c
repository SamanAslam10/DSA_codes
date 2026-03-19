#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};
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
int CountElements(struct Node *tail)
{
    struct Node *ptr = tail;
    int count = 0;

    do
    {
        count ++;
        ptr = ptr ->next;
    }while(ptr != tail);

    return count;
}
int main()
{
    int n = 5;
    int array[] = {1,2,3,4,5};

    struct Node *Tail = Create(array , n);
    int count = CountElements(Tail);
    printf( "%s%d","Total elements : " , count);
}