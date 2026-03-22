#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node* Create(int arr[],int n)
{
    struct Node *head,*tail,*ptr;
    head = (struct Node*)malloc(sizeof(struct Node));
    head-> data = arr[0];
    head-> next = head;

    tail = head;

    for(int i = 1; i <n ; i ++)
    {
        ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr -> data = arr[i];
        ptr -> next = head;
        tail -> next = ptr;
        tail = ptr;
    }
    return tail;
}
void Display(struct Node *tail)
{
    struct Node *ptr = tail;
    do
    {
        printf("%d,%s" , ptr->next-> data ," ");
        ptr = ptr -> next;
    }while(ptr!= tail);
}
int SearchELement(struct Node *tail,int element)
{
    struct Node *temp = tail;

    do
    {
        if(temp -> data == element)
        {
            return 1;
        }
        temp = temp -> next;
    }while(temp!=tail);
    return 0;
}
int main()
{
    int array[] = {10,20,30,40,50};
    int n = 5;

    struct Node *tail = Create(array , n);
    
    int exist = SearchELement(tail,20);

    if(exist == 1)
    {
        printf("%s" , "Yes! the element exists.");
    }
    else
    {
        printf("%s", "No! the element doesn't exist.");
    }

    return 0;
}