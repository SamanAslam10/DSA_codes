#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void countValues(struct Node* head)
{
    int even=0, odd=0, pos=0, neg=0, zero=0;

    struct Node* temp=head;

    while(temp!=NULL)
    {
        if(temp->data==0)
            zero++;

        if(temp->data>0)
            pos++;

        if(temp->data<0)
            neg++;

        if(temp->data%2==0)
            even++;
        else
            odd++;

        temp=temp->next;
    }

    printf("Even: %d\n",even);
    printf("Odd: %d\n",odd);
    printf("Positive: %d\n",pos);
    printf("Negative: %d\n",neg);
    printf("Zero: %d\n",zero);
}

int main()
{
    struct Node *head = NULL;

    struct Node *n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n4 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n5 = (struct Node*)malloc(sizeof(struct Node));

    n1->data = 5;
    n2->data = -2;
    n3->data = 0;
    n4->data = 7;
    n5->data = 4;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    head = n1;

    countValues(head);

    return 0;
}