#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
void insertionfront( struct node **head, int info)
{
     struct node *temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=info;
    temp->link=(*head);
    (*head)=temp;
}
void insertionend(struct node **head,int info)
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
void printlist(struct node **head)
{
    struct node* p;
    p=*head;
    while(p!=NULL)
    {
        printf("%d -> ",p->data);
        p=p->link;
    }
    printf(" NULL ");
}
void deletenode(struct node **head,int key)
{
    struct node *temp=(*head),*prev=NULL;

    if(temp!=NULL && temp->data==key)
    {
        (*head)=temp->link;
        free(temp);
        return;
    }
    while(temp!=NULL || temp->data != key)
    {
        prev=temp;
        temp=temp->link;
    }
    if(temp==NULL)
        return;
    prev->link=temp->link;
    free(temp);

}
int main()
{
    int i;
    struct node* head=NULL;
    for(i=1;i<=10;i++)
        insertionend(&head,i);

    printf("\n\n----------------------------------\n\n");
    printlist(&head);
    printf("\n\n----------------------------------\n\n\n deletion of 2\n\nNew List\n");
    deletenode(&head,1);
    printlist(&head);



}
