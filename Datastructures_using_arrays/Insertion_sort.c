#include<stdio.h>
void printFun(int arr[],int n)
 {
     for(int i=0;i<n;i++)
     {
         printf("%d ",arr[i]);
     }}
int main()
{
    int arr[10]={10,8,3,21,8,9,2,1,7,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int temp=0,j;
    for(int i=1;i<n;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>=temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
        
    }
    printFun(arr,n);
}