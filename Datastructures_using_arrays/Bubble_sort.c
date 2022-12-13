#include<stdio.h>
int main()
{
    int n=0,temp=0;
    printf("enter the size:\n");
    scanf("%d",&n);
    int arr[20];
    printf("Enter the array elements\n");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        
    }
    
    printf("Array elements are:\n");
    for(int j=0;j<n;j++)
    {
        printf("%d\n",arr[j]);
    }
    
    for(int k=0;k<n-1;k++)
    {
        for(int l=0;l<n-1-k;l++)
        {
           if(arr[l]>arr[l+1])
           {
               temp=arr[l];
               arr[l]=arr[l+1];
               arr[l+1]=temp;
           }
        }
    }
    printf("Sorted Elements are:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    
}