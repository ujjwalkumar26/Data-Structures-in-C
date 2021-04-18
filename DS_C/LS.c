#include<stdio.h>
void swap(int* a,int* b)
{
	int temp =*a;
	*a=*b;
	*b=temp;
}
int partition(int a[],int l,int n)
{
	int pivot = a[n];
	int i=l-1;
	for (int j=l;j<n;j++)
	{
	    if (a[j] < pivot)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1],&a[n]);
	return (i+1);
}
void quicksort(int a[],int l, int n)
{
	if (l<n)
	{
		int part = partition(a,l,n);
		quicksort(a,l,part-1);
		quicksort(a,part+1,n);
	}
}

int main()
{
	int n,i;
	int a[1000];
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
        scanf("%d",&a[i]);
	quicksort(a,0,n-1);
	printf("Sorted array\n");
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
	return 0;
}
