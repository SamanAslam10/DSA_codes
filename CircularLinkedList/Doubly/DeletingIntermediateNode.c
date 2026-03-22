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

    temp = head;

    for(int i = 1; i < n ; i ++)
    {
        ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr -> data = arr[i];
        ptr -> next = head;
        ptr -> prev = temp;

        temp -> next = ptr;
        temp = ptr;
    }
    return temp;
}
void Display(struct Node *tail)
{
    struct Node *ptr = tail;
    do
    {
        printf("%d,%s" , ptr -> data , " ");
        ptr = ptr -> next;
    }
    while(ptr != tail);
}
struct Node* DeletionIntermediateNode(struct Node* tail , int position)
{
    struct Node *ptr,*temp;
    ptr = tail;
    while(position > 1)
    {
        ptr = ptr -> next;
        position --;
    }
    temp = ptr;
    ptr -> next = ptr -> next -> next;
    ptr -> next -> next -> prev = ptr;

    free(temp);
    temp = NULL;

    return tail;
}
int main()
{
    int arr[] = {1,2,3,4,5,6};
    int n = 6;

    struct Node* tail = Create(arr,n);
    tail = DeletionIntermediateNode(tail , 3);
    Display(tail);
    return 0;
}
