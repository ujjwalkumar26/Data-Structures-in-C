#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
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
void printlist(struct node **head)
{
    struct node* p;
    p=*head;
    while(p!=NULL)
    {
        printf("%d -> ",p->data);
        p=p->link;
    }
    printf(" NULL \n");
}
struct node* concat(struct node **head1,struct node **head2)
{
        struct node* temp= *head1;
        if(*head1==NULL)
            {*head1=*head2;
                return *head1;
            }
        if(*head2==NULL)
            return *head1;
         while(temp->link!=NULL)
            temp=temp->link;
            temp->link=*head2;
            return *head1;
}
int main()
{
    struct node *head1=NULL,*head2=NULL;
    int i;
    for(i=100;i<=500;i+=100)
        insertEnd(&head1,i);
    printf("First list\n");
    printlist(&head1);
    printf("Second list\n");
    for(i=90;i<=150;i+=10)
        insertEnd(&head2,i);
    printlist(&head2);
    //concatinate and store head in head1
    head1=concat(&head1,&head2);
    printf("THE CONCATINDATED LIST\n");
    printlist(&head1);

}
