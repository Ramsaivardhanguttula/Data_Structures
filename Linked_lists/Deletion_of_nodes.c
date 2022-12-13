#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
    
};

struct node *head=0;
int count=0;


int Display()
{
    struct node *temp=head;
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
void DeleteAtBeginning()
{
    struct node *temp = head;
    head=head->next;
    free(temp);
    count--;
    Display();
    
}

void DeleteAtEnd()
{
   struct node *temp = head, *prevnode;
   while(temp->next!=0)
   {
       prevnode=temp;
       temp=temp->next;
   }
   if(temp==head){
       head->next=0;
   }
   else
   {
       prevnode->next=0;
   }
   count--;
   free(temp);
   Display();
    
}

void DeleteAtPos()
{
    int i=1,pos;
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos>count)
    {
        printf("Invalid Position");
    }
    else{
        struct node *nextnode,*temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        nextnode=temp->next;
        temp->next=nextnode->next;
        count--;
        free(nextnode);
        Display();
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
        Display();
        printf("\nWould u like to continue(0 for no/1 for yes):");
        scanf("%d",&choice);
    }
 
     printf("\nFor deleting node press 1:");
     int ch;
     scanf("%d",&ch);
 
     if(ch==1)
     {    
          int choice;
         do
           {   
               printf("\nPress\n");
               printf(" 1 for DeleteAtBeginning\n2 for DeleteAtEnd\n3 for deleting at position\n0 to exit\n");
               scanf("%d",&choice);
               switch(choice)
               {
                   case 1: 
                       DeleteAtBeginning();
                       break;
                     case 2:
                       DeleteAtEnd();
                         break;
                     case 3: 
                        
                         DeleteAtPos();
                         break;
                     default :
                         break;
               }
           }
           while(choice!=0);
     }
}