#include<stdio.h>
void BinarySearch(int arr[], int ele,int lb,int ub)
{
        int mid=(lb+ub)/2;
        if(arr[mid]<ele)
        {
            BinarySearch(arr,ele,mid+1,ub);
        }
        else if(arr[mid]==ele)
        {
            printf("Element found at %d index and %d position\n",mid, mid+1);
        }
        else
        {
            BinarySearch(arr,ele,lb,mid-1);
        }
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ele;
    printf("Enter Element:");
    scanf("%d",&ele);
    int lb=0;
    int ub=n-1;
    //int mid=0;//(lb+ub/2);
    BinarySearch(arr,ele,lb,ub);

}