#include <stdio.h>
void bubblesort(int a[],int n)
{
    int i=0,j=0;
    for(i=0;i<n-1;i++)
    for(j=0;j<n-1-i;j++)
    if(a[j]>a[j+1])
    {
        a[j]=a[j+1]+a[j];
        a[j+1]=a[j]-a[j+1];
        a[j]=a[j]-a[j+1];
    }
}

int main() {
    int a[1000];
    int n;
    int i=0,j=0;
    printf("Enter the number of elements\n\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    	scanf("%d",&a[i]);
    bubblesort(a,n);
    printf("\n\n");
    for(i=0;i<n;i++)
    	printf("%d  ",a[i]);    
}
