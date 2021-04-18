#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node* prev;
struct node* next;
};
void insertFront(struct node** head,int newData)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=newData;
    temp->prev=NULL;
    if(*head==NULL)
    {
        temp->next=NULL;
        *head=temp;
        return;
    }
    temp->next=*head;
    (*head)->prev=temp;
    (*head)=temp;
}
void insertEnd(struct node **head,int newData)
{
    struct node *temp,*last;
    last=*head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=newData;
    temp->next=NULL;
    if(*head==NULL)
    {
        temp->prev=NULL;
        *head=temp;
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }

    last->next=temp;
    temp->prev=last;
}
void printList(struct node* head)
{
    struct node* p;
    p=head;
    while(p!=NULL)
    {
        printf("%d->",p->data);
        p=p->next;
    }
}
void deleteNode(struct node **head,int del)
{
    struct node *temp=*head;
    if((*head)->data==del)
        {(*head)=(*head)->next;
            free(temp);
            return;
        }
        while(temp->next!=NULL && temp->data!=del)
        {
            temp=temp->next;
        }
        if(temp->next==NULL && temp->data!=del)
            return;
        if(temp->next==NULL && temp->data==del)
        {
            temp->prev->next=temp->next;
            return;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
}
int main()
{
    int i;
    struct node * head=NULL;
    for(i=1;i<=10;i++)
    insertFront(&head,i);
    printList(head);
    printf("\n\n\n");
    for(i=50;i<=500;i+=50)
    insertEnd(&head,i);
    printList(head);
    //deletion
    deleteNode(&head,500);
    printf("\n\n\n");
    printList(head);

}
