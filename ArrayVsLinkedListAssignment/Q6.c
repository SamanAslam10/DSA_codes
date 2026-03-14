#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertBeginning(int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->next = head;

    head = newNode;
}

void insertEnd(int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertAfter(int key,int val)
{
    struct Node* temp = head;

    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp != NULL)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->data = val;
        newNode->next = temp->next;

        temp->next = newNode;
    }
}

void deleteBeginning()
{
    if(head == NULL) return;

    struct Node* temp = head;
    head = head->next;

    free(temp);
}

void deleteEnd()
{
    if(head == NULL) return;

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;

    while(temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void deleteValue(int key)
{
    struct Node* temp = head;
    struct Node* prev = NULL;

    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return;

    if(prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
}

void display()
{
    struct Node* temp = head;

    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int countNodes()
{
    int count = 0;

    struct Node* temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

int main()
{
    insertBeginning(10);
    insertEnd(20);
    insertBeginning(5);

    display();

    insertAfter(10,15);
    display();

    deleteValue(20);
    display();

    printf("Total nodes: %d",countNodes());

    return 0;
}