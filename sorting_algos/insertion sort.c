#include<stdio.h>
void insertionSort(int a[],int n)
{
    int i,j=0,key;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while( j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }

}
int main()
{
    int a[1000];
    int i,n;
    printf("Enter the number of elements of ARRAY\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    insertionSort(a,10);
printf("\nSORTED ARRAY\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
