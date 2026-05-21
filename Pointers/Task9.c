#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    //1
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node)); 
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));  

    //2
    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    //3
    struct Node *temp = first;
    for(int i = 0; i < 3; i ++)
    {
        printf("%d" , temp->data); 
        printf("%s"," , ");
        temp = temp->next;    
    }

    //4
    free(first);
    free(second);
    free(third);


    return 0;

}