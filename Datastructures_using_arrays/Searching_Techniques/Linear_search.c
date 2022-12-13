#include<stdio.h>
int main()
{
    int arr[]={1,3,4,9,6,5,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int count=0;
    int ele,found=0;
    printf("Enter element:");
    scanf("%d",&ele);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele)
        {
            found++;
            count=i;
        }
    }
    if(found>=1)
    {
        printf("Element found at %d index and %d position\n",count,count+1);
    }
    else{
        printf("Element not found\n");
    }
    
}