#include<stdio.h>

 void printFun(int arr[],int n)
 {
     for(int i=0;i<n;i++)
     {
         printf("%d ",arr[i]);
     }
}
void Swap(int arr[], int x,int i)
{int temp=0;
        temp=arr[i];
        arr[i]=arr[x];
        arr[x]=temp;
}
int main()
{
    int arr[10]={10,8,3,21,8,9,2,1,7,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    //printf("%d",n);
    int min=0,index=0;
    for(int i=0;i<n;i++)
    {
        min=arr[i];
        for (int j=i;j<n;j++)
        {
         if(min>=arr[j])
         {
             min=arr[j];
             index=j;
             
         }
        }
        Swap(arr,index,i);
    }
    printFun(arr,n);   
}