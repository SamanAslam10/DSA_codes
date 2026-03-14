#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void search(struct Node* head,int key)
{
    int pos = 1;
    int comparisons = 0;

    struct Node* temp = head;

    while(temp != NULL)
    {
        comparisons++;

        if(temp->data == key)
        {
            printf("Found at position %d\n",pos);
            printf("Comparisons: %d\n",comparisons);
            return;
        }

        temp = temp->next;
        pos++;
    }

    printf("Element not found\n");
}

int main()
{
    struct Node *head = NULL;

    struct Node *n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n4 = (struct Node*)malloc(sizeof(struct Node));

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;
    n4->data = 40;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    head = n1;

    int key;
    printf("Enter value to search: ");
    scanf("%d",&key);

    search(head,key);

    return 0;
}