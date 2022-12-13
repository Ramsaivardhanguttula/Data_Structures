#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
    
};

struct node *head=0;
int count=0;

void display()
{
    struct node *temp=head;
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

void InsertAtBeginning(int data)
{
    struct node *newnode,*temp=head;
    
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=0;
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    count++;
    display();
    
}

void InsertAtEnd(int data)
{
    struct node * newnode, *temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=0;
    newnode->data=data;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    count++;
    display();
}
void InsertAtPos(int data)
{
    struct node *newnode, *temp=head;
    printf("Enter position:");
     int pos;
     scanf("%d",&pos);
     int i=1;
     if(pos>count)
     {
       printf("Invalid position");
     }
     else 
     {
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode=(struct node*)malloc(sizeof(struct node));
        //newnode->next=0;
        newnode->data=data;
        newnode->next=temp->next;
        temp->next=newnode;
        count++;
        display();
     }
    
   
    
}
int main()
{
    struct node *newnode, *temp;
    int choice=1;
    
    while(choice!=0)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {
            head=temp=newnode;
            
        }
        else {
            temp->next=newnode;
            temp=newnode;
        }
        count++;
        display();
        printf("\nWould u like to continue(0 for no/1 for yes):");
        scanf("%d",&choice);
    }
    
    printf("\nFor inserting newnode press 1:");
    int ch;
    scanf("%d",&ch);
   
    if(ch==1)
    {    
         int choice;
        do
           {   
               printf("\nPress\n");
               printf(" 1 for InsertAtBeginning\n2 for InsertAtEnd\n3 for Inserting at position\n0 to exit\n");
               scanf("%d",&choice);
               switch(choice)
               {
                   case 1: 
                       printf("Enter data:");
                       int ele;
                       scanf("%d",&ele);
                       InsertAtBeginning(ele);
                       break;
                    case 2:
                        printf("Enter data:");
                        int ele1;
                        scanf("%d",&ele1);
                        InsertAtEnd(ele1);
                        break;
                    case 3: 
                        printf("Enter data:");
                        int ele2;
                        scanf("%d",&ele2);
                        InsertAtPos(ele2);
                        break;
                    default :
                        break;
                    
                        
               }
               
               
           }
           while(choice!=0);
    }
}