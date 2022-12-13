#include<stdio.h>
#include<stdlib.h>
int main()
{
    struct node
    {
        int data;
        struct node *next;
        
    };
    
    struct node *head, *newnode, *temp;
    head=0;
    int choice=1,count=0;
while(choice!=0)
  {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=0;
        printf("Enter Data:\n");
        scanf("%d",&newnode->data);
        
        if(head==0)
        {
            head=temp=newnode;
            
        }
        else {
            temp->next=newnode;
            temp=newnode;
            
        }
        printf("Want to continue(0 to stop, 1 to continue)\n");
        scanf("%d",&choice);
        count++;
  } 
    temp=head;
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
        
    }
    printf("\nNumber of nodes are : %d\n",count);
}