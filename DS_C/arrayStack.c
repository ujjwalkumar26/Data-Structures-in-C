//STACK USING ARRAY
#include<stdio.h>
#define SIZE 10
int Stack[SIZE], top=-1;
void push(int value)
{
    if(top==SIZE)
        {printf("Stack Overflow!\n");
        return;}
    top++;
    Stack[top]=value;
}
void pop()
{
    if(top==-1)
    {
        printf("Stack underflow!\n");
        return;
    }
    top--;
}
void getTop()
{
    if(top==-1)
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("%d\n",Stack[top]);
}
int main()
{
    push(1);
    push(2);
    getTop();
    pop();
    pop();
    pop();
    push(100);
    getTop();
}
