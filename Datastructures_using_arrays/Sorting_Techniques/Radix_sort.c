#include<stdio.h>

void printFun(int arr[],int n)
 { printf("Radix Sort\n");
     for(int i=0;i<n;i++)
     {
        printf("%d ",arr[i]);
     }
     printf("\n");
     
 }
void countSort(int arr[], int pos, int n)
{
    int count[10]={0};
    for(int i=0;i<n;i++)
    {
        ++count[(arr[i]/pos)%10];
    }
    for(int i=1;i<=9;i++)
    {
        count[i]=count[i]+count[i-1];
        
    }
    int a[n];
    for(int i=n-1;i>=0;i--)
    {
        a[--count[(arr[i]/pos)%10]]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=a[i];
    }
}
void RadixSort(int arr[],int n,int max)
{
    for(int pos=1;(max/pos)>0;pos*=10)
    {
        countSort(arr, pos, n);
    }
}
int MaxElement(int arr[],int n)
{
    int max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(max<=arr[i])
        {
            max=arr[i];
        }
    }
    //printf("%d",max);
    return max;
}
int main()
{
    int arr[]={432,8,530,90,88,231,011,045,677,199};
    int n = sizeof(arr)/sizeof(arr[0]);
    //printf("%d",n);
    int max = MaxElement(arr, n);
    //printf("%d\n",max);
    RadixSort(arr,n,max);
    printFun(arr,n);
}