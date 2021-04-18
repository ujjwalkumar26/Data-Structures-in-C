#include<stdio.h>
typedef int bool;
#define true 1;
#define false 0;
#define SIZE 5

int A[SIZE];
int front = -1;
int rear = -1;

bool isempty()
{
    if (front == -1 && rear == -1)
        {return true;}
    else return false;
}

void enqueue ( int value )
{
 if ((rear+1)%SIZE == front)
    printf("Queue is full\n");
 else
 {
  if( front == -1)
     front = 0;
    rear = (rear+1)%SIZE;
    A[rear] = value;
 }
}

void dequeue ( )
{
 if( isempty() )
 printf("Queue is empty\n");
 else
 if( front == rear )
  front = rear = -1;
 else
  front = (front + 1)%SIZE;
}

void getfront( )
{
 if( isempty())
 printf("Queue is empty\n");
 else
 printf("element at front is: %d\n",A[front]);
}

void printQueue()
{
 if(isempty())
  printf("Queue is empty\n");
 else
 {
  int i;
  if( front <= rear )
  {
   for( i=front ; i<= rear ; i++)
   printf("%d ",A[i]);
  }
  else
  {
   i=front;
   while( i < SIZE)
   {
   printf("%d ",A[i]);
   i++;
   }
   i=0;
   while( i <= rear)
   {
   printf("%d ",A[i]);
   i++;
   }
  }
 }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    getfront();
    enqueue(100);
    printQueue();
 return 0;
}
