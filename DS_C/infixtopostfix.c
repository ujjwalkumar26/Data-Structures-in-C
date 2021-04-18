#include<stdio.h>
#include<string.h>
#include<ctype.h>
char stack[100];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}
int main()
{
    char exp[100],exp2[100], exp3[100];
    int k=0;
    char *e,*p, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    strcpy(exp2,exp);
    strrev(exp2);
    printf("\n");
    e = exp;
    while(exp2[k])
    {
        if(exp2[k]=='(')
            exp2[k]=')';
        if(exp2[k]==')')
            exp2[k]='(';
        k++;
    }
    k=0;
    p = exp2;
    printf("Postfix expression is: \n");
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            {push(*e);}
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        printf("%c ",pop());
    }
    top = -1;
    while(*p !='\0')
    {

        if(isalnum(*p))
            {exp3[k]=*p;
                k++;}
        else if(*p == '(')
           {push(*p);}
        else if(*p == ')')
        {
            while((x = pop()) != '(')
                {exp3[k]=x;
                k++;}
        }
        else
        {
            while(priority(stack[top]) >= priority(*p))
                {exp3[k]=pop();
                    k++;}
            push(*p);
        }
        p++;
    }
     while(top != -1)
    {
       exp3[k]=pop();
       k++;
    }
    exp3[k]='\0';
    strrev(exp3);
    k=0;
    while(exp3[k])
    {
        if(exp3[k]=='(')
            exp3[k]=')';
        if(exp3[k]==')')
            exp3[k]='(';
        k++;
    }
    printf("\nPrefix expression is: \n");
    k=0;
    while(exp3[k])
    {
        printf("%c ",exp3[k]);
        k++;
    }
}
