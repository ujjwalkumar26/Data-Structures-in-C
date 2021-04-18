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
int main()
{
    int i;
    struct node* head=NULL;
    for(i=1;i<=10;i++)
        insertionfront(&head,i);

    printf("\n\n----------------------------------\n\n");
    printlist(&head);
    printf("\n\n----------------------------------\n\n");
}
