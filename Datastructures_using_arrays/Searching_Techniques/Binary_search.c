#include<stdio.h>
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Enter Element:");
    int ele;
    scanf("%d",&ele);
    int lb=0;
    int ub=n-1;
    int mid=0;//(lb+ub/2);
    while(lb<ub)
    { mid=(lb+ub)/2;
        if(arr[mid]<ele)
        {
            lb=mid+1;
        }
        else if(arr[mid]==ele)
        {
            printf("Element found at index %d\n", mid);
            break;
        }
        else
        {
            ub=mid-1;
        }
        // else
        // printf("Element is not found\n");
            
        // }
    }
}