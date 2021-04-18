#include<stdio.h>
int partition(int a[],int l, int u)
{
    int pivot=a[l];
    int i=l,j=u;
    while(j>i)
    {

        do{
            i++;
        } while(a[i]<=pivot);

        do{
            j--;
        }
        while(a[j]>pivot);
    }
    if(i<j)
    {
        int temp;
        temp=a[j];
        a[j]=a[i];
        a[i]=temp;
    }
    int temp2;
    temp2=a[l];
    a[l]=a[j];
    a[j]=temp2;

    return j;
}
void   QuickSort(int a[],int l, int u)
{
    if(l<u)
    {
        int p=partition(a,l,u);
        QuickSort(a,l,p);
        QuickSort(a,p+1,u);
    }
}
int main()
{
    int a[100];
    int n,i;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    QuickSort(a,0,n);
    printf("Sorted array\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
