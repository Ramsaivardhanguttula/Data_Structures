#include<stdio.h>
void printFun(int arr[],int n)
 { //printf("rm");
 printf("Merge_sort\n");
     for(int i=0;i<n;i++)
     {
         printf("%d ",arr[i]);
         
     }
     printf("\n");
     
 }
 void Merge(int arr[],int lb,int mid,int ub)
 {
    int i= lb;
    int j=mid+1;
    int k=lb;
    int dup[ub+1];
    while(i<=mid && j<=ub)
    {
        if(arr[i]<=arr[j])
        {
          dup[k]=arr[i];
         
          i++,k++;
        }
        else
        {
          dup[k]=arr[j];
          j++,k++;
        }
        
    }
    
    //For the Remaining elements of the subsets
    if(i>mid)//if left side sebset if less than the size of rightside subset
    {
        while(j<=ub)//for including every element left in the right subset
        {
            dup[k]=arr[j];
            k++,j++;
        }
    }
    else//for right side sebset if less than the size of left side subset
    {
        while(i<=mid)//for including every element left in the left subset
        {
            dup[k]=arr[i];
            k++,i++;
        }
    }
     for(int i=lb;i<=ub;i++)//Storing the duplicate array elements to the actual array
    {
        arr[i]=dup[i];
    }
    
 }
 void MergeSort(int arr[],int lb,int ub)
 { 
     if(lb<ub)
    {  
        int mid=(lb+ub)/2;
       
        MergeSort(arr,lb,mid);
        MergeSort(arr,mid+1,ub);
        Merge(arr,lb,mid,ub);
    } 
    
 }

int main()
{
    int arr[10]={10,8,3,21,8,9,2,1,7,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int lb=0;
    int ub=n-1;
    MergeSort(arr,lb,ub);
    printFun(arr,n);
}
