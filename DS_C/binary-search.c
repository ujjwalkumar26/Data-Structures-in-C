#include<stdio.h>
int binarySearch(int a[],int l, int u, int key)
{
    if(l<=u)
    {
       int mid=(l+u)/2;
       if(a[mid]==key)
        return mid;
       if(a[mid]>key)
            return binarySearch(a,l,mid-1,key);
        if(a[mid]<key)
            return binarySearch(a,mid+1,u,key);
    }
    return -1;
}
int main()
{
   int n,i,key;
    int a[1000];
    printf("Enter the size of array\t");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the number to be searched\t");
    scanf("%d",&key);
    if(binarySearch(a,0,n-1,key)==-1)
        printf("Number is not present in the array\n");
    else printf("Element found at index %d\n",binarySearch(a,0,n-1,key));


}
