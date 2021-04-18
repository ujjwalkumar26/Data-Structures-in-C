#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void insertEnd(struct node **head,int info)
{
    struct node *last,*temp;
    last=*head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=info;
    temp->link= NULL;
    if(*head==NULL)
    {
        (*head)=temp;
        return;
    }
        while(last->link!=NULL)
            last=last->link;
        last->link=temp;

}
void printList(struct node *head)
{
    struct node *p=head;
    while(p!=NULL)
    {
        printf("%d->",p->data);
        p=p->link;
    }
    printf("NULL\n");
}

int main()
{
    int i;
    struct node *head=NULL;
    for(i=100;i<1000;i+=100)
        insertEnd(&head,i);
    printList(head);
}
