#include <stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void Enque()
{
    int x;
    printf("Enter data:\n");
    scanf("%d",&x);    
    if(rear==N-1)
    {
        printf("*********Stack Overflow************\n");
        
    }
    else if( front==-1&&rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}

void Deque()
{
    if(front==-1&&rear==-1)
    {
        printf("Queue is Empty\n");
        
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
    

}

void peek()
{
    if(front==-1&&rear==-1)
    {
        printf("Queue is Empty\n");
        
    }
    else
    {    printf("Top element is:");
        printf("%d\n",queue[front]);}
    
}
void display()
{
    if(rear==-1&&front==-1)
    {
        printf("Queue is Empty\n");
    }
    for(int i=front;i<=rear;i++)
    {
        printf("%d\t",queue[i]);
    }
    
}

int main()
{
    int ch;
    do 
    {
       printf("\nEnter choice:\n 1 for inserting\t 2 for deleting\t 3 for peek\t 4 for display\n");
        
        scanf("\n%d",&ch); 
        switch(ch)
        {
            case 1:Enque();
            break;
            case 2: Deque();
            break;
            case 3: peek();
            break;
            case 4: display();
            break;
            default: 
            printf("Wrong Choice\n");
        }
    }
    while(ch!=0);
    //getch();
}