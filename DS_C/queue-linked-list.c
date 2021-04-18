#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void enQ(struct node **head,struct node **last,int newdata)
{
    struct node *temp,*temp2;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=newdata;
    temp->next=NULL;
    if(*last==NULL)
    {
        (*last)=temp;
        (*head)=temp;
        return;
    }
        (*last)->next=temp;
        (*last)=temp;
        return;
}
void  deQ(struct node **head,struct node **last)
{
    struct node *temp=*head;
    if(*head==*last)
    {
        if(*head==NULL)
        {
            printf("QUEUE IS EMPTY\n");
            return;
        }
        else {
            *head=NULL;
            *last=NULL;
                free(temp);
                return;
        }
    }
        *head=temp->next;
        free(temp);
}
int QFront(struct node **head)
{
    if(*head==NULL)
       return -1;
    return (*head)->data;
}
int Qend(struct node **last)
{
    if(*last==NULL)
        return -1;
    return (*last)->data;
}
struct Q
{
    struct node *head;
    struct node *last;
};
int main()
{
    struct Q Q1;
    Q1.head=NULL;
    Q1.last=NULL;

    enQ(&Q1.head,&Q1.last,1);
    enQ(&Q1.head,&Q1.last,2);
    enQ(&Q1.head,&Q1.last,3);
    deQ(&Q1.head,&Q1.last);
    printf("The front of the queue is : %d\n",QFront(&Q1.head));
    printf("The end of the queue is : %d\n",Qend(&Q1.last));

}
