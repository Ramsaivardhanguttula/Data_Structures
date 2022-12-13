#include<stdio.h>
void printFun(int arr[],int n)
 { printf("Quick Sort\n");
     for(int i=0;i<n;i++)
     {
         printf("%d ",arr[i]);
     }
     printf("\n");
     
 }
void Swap(int arr[],int a,int b){
    int temp=0;
    temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

int Partition( int arr[],int lb,int ub)

{
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
      
    while(start<end)  
      {
            while(pivot>=arr[start])
           {
               start++;
           }
           while(arr[end]>pivot)
           {
               end--;
           }
           if(start<end)
           {
               Swap(arr,start,end);
            //   int temp=0;
            //   temp=arr[start];
            //   arr[start]=arr[end];
            //   arr[end]=temp;
           }
      } 
    Swap(arr,lb,end);
   // printf("hi");
    return end;
       
}
void QuickSort(int arr[],int lb,int ub)
{
  if(lb<ub)
  {
      int loc=Partition(arr,lb,ub);
      QuickSort(arr,lb,loc-1);
      QuickSort(arr,loc+1,ub);
  }
    
    
}
int main()
{
    int arr[10]={10,8,3,21,8,9,2,1,7,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ub=n-1;
    int lb=0;
    QuickSort(arr,lb,ub);
    printFun(arr,n);

}