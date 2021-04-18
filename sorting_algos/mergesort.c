#include<stdio.h>
void merge(int a[],int l,int m,int n)
{
    int i=0,j=0,k=0,n1,n2;
    n1=m-l+1;
    n2=n-m;
    int a1[n1],b1[n2];
    for(i=0;i<n1;i++)
    {
        a1[i]=a[l+i];
    }
    for(j=0;j<n2;j++)
    {
        b1[j]=a[m+j+1];
    }
    i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(a1[i]<b1[j])
        {
           a[k]=a1[i];
           i++;
        }
        else
        {
            a[k]=b1[j];
            j++;
        }
        k++;
    }
    for(;i<n1;i++)
    {
        a[k]=a1[i];
        k++;
    }
    for(;j<n2;j++)
    {
        a[k]=b1[j];
        k++;
    }

}
void mergesort(int a[],int l, int n)
{
    if(l<n)
    {
        int m=(l+n)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,n);
        merge(a,l,m,n);
    }
}
int main()
{
    int a[1000];
    int i=0,n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    printf("\nSORTED ARRAY\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
