#include<stdio.h>
void printFun(int arr[],int n)
 {
    printf("Counting Sort\n");
     for(int i=0;i<n;i++)
     {
         printf("%d ",arr[i]);
     }
     printf("\n");
     
 }
void CountSort(int arr[],int n,int k)
{
    //printf("%d\n",k);
    int count[k+1];
  for(int i=0;i<n;i++)
  {
    ++count[arr[i]]; 
  }
  for(int i=1;i<=9;i++)
  {
    count[i]=count[i]+count[i-1];
  }
  int a[n];
  for(int i=n-1;i>=0;i--)
  {
      a[--count[arr[i]]] = arr[i];
  }
  for(int i=0;i<n;i++ )
  {
      arr[i]=a[i];
  }
  
}
int main()
{
    int arr[10]={9,8,7,6,5,4,3,2,1,0};
    int n=(sizeof(arr)/sizeof(arr[0]));
    int k=9;//Highest digit in the array
    CountSort(arr,n,k);
    printFun(arr,n);
}
