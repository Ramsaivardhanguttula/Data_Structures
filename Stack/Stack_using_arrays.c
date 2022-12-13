#include <stdio.h>
#define N 5
int stack[N];
int top=-1;
void push()
{
    int x;
    printf("Enter data: \n");
    scanf("%d",&x);
    if (top==(N-1))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}
void pop()
{
  if(top==-1)
  {
      printf("Stack Underflow\n");
      
  }
  else
  {
      int item=top;
      top--;
      printf("popped item is %d\n",item);
  }
}
void peek()
{
   if(top==-1)
  {
      printf("Stack Underflow\n");
      
  } 
  else 
  {
      printf("top item is %d\n",stack[top]);
  }
}
void display()
{
    if(top==-1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        for (int i=0;i<=top;i++)
        {
            printf("%d",stack[i]);
        }
    }    
}

int main()
{
    int ch;
    do 
    {
       printf("\nEnter choice:\n 1 for push\t 2 for pop\t 3 for peek\t 4 for display\n");
        
        scanf("\n%d",&ch); 
        switch(ch)
        {
            case 1:push();
            break;
            case 2: pop();
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