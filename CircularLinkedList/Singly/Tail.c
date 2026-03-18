#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void Display(struct Node *head);
struct Node* Create(int arr[] , int n);
int main()
{
    int arr[] = {1,2,3,4,5};
    int n = 5;
    struct Node *tail = Create(arr , 5);

    Display(tail);
}
struct Node* Create(int arr[] , int n)
{
    
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head -> data = arr[0];
    head -> next = head;

    struct Node *tail,*temp;
    tail = head;
    for(int i = 1; i < n ; i ++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp -> data = arr[i];
        temp -> next = head;
        tail -> next = temp;
        tail = temp;
    }
    return tail;
}
void Display(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d,%s" , ptr-> data , " ");
        ptr = ptr -> next;
    }
    while(ptr != head);
}