#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node* prev;
struct node* next;
};
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
        last=last->next;
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
    printf("NULL\n");
}
void reverseList(struct node **head)
{
    struct node *temp=NULL,*p;
    p=*head;
    while(p!=NULL)
    {
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        p= p->prev;
    }
    if(temp != NULL )
        *head = temp->prev;
}
int main()
{
    int i,n,data;
    struct node* head=NULL;
    printf("Enter the number of elements in linked list:  ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        insertEnd(&head,data);
    }
    printf("\n THE LIST ENTERED IS:\n");
    printList(head);
    printf("REVERSED LIST\n");
    reverseList(&head);
    printList(head);
}
