#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int detectCycle(struct Node* head)
{
    struct Node* slow=head;
    struct Node* fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
            return 1;
    }

    return 0;
}

int main()
{
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

    struct Node* head = n1;

    printf("Cycle present? %s\n", detectCycle(head) ? "Yes" : "No");

    n4->next = n2;

    printf("Cycle present after creating loop? %s\n", detectCycle(head) ? "Yes" : "No");

    return 0;
}