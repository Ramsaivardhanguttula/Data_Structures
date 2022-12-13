#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
    
};

struct node *head=0;
int count=0;



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
    

void DeleteAtBeginning()
{
    struct node *temp = head;
    head=head->next;
    free(temp);
    count--;
    display();
    
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
   display();
    
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
        display();
    }
}


void display()
{
    struct node *temp=head;
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
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
        printf("\nWould u like to continue??(0 for no/1 for yes):");
        scanf("%d",&choice);
    }
 
    int ch;
    
    do{
        printf("\n For inserting newnode press 1 /For deleting node press 2:");
        // int ch;
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
    
         if(ch==2)
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
    }while(ch!=0);
}