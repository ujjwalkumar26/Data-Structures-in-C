#include<stdio.h>
void swap(int a[], int i, int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void selectionSort(int a[],int s,int n)
{
    int i;
    if(s>=n)
        return;
    int min;
    min =s;
    for(i=s+1;i<=n;i++)
        if(a[i]<a[min])
            min=i;
    swap(a,min,s);
    selectionSort(a,s+1,n);
}
int main()
{
    int i,n;
    int a[1000];
    printf("Enter the number of elements\n");
    scanf("%d ",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selectionSort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
