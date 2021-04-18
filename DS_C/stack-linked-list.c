#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void push(struct node **head,int newdata)
{
    struct node *temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=newdata;
    if(*head==NULL)
    {
        *head=temp;
        temp->next=NULL;
        return;
    }
    temp->next=*head;
    *head=temp;
    return;
}
void pop(struct node **head)
{
    if(*head==NULL)
    {
        printf("Underflow - empty stack\n");
        return;
    }
    struct node *temp=*head;
    *head=temp->next;
    free(temp);
}
void top(struct node **head)
{
    if(*head==NULL)
    {
        printf("Underflow - empty stack\n");
        return;
    }
    printf("The top of the stack is %d \n",(*head)->data);
}
struct stack{
    struct node *head;
};
int main()
{
    struct stack S1;
    S1.head=NULL;
    push(&S1.head,1);
    push(&S1.head,2);
    push(&S1.head,3);
    push(&S1.head,4);

    top(&S1.head);

    pop(&S1.head);
    pop(&S1.head);

    top(&S1.head);

    pop(&S1.head);
    pop(&S1.head);

    top(&S1.head);
}
