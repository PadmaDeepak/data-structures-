#import<stdio.h>
#define MAX 5


void push(int stack[], int *top, int value)
{
  if (*top==MAX-1)
  {
    printf("Stack overflow. Cannot push %d onto the stack\n", value);
   
  }
  else
  {
    (*top)++;
    stack[*top]=value;
    printf("The value %d has been pushed onto the stack\n", value);
   
  }
 
}

int pop(int stack[], int *top)
{
  if (*top==-1)
  {
    printf("Stack underflow. Cannot pop from an empty stack\n");
  return -1;
  }
  else{
    return stack[*top--];
   
  }
}

void display(int stack[], int top)
{
  if (top==-1)
  {
    printf("The stack is empty\n");
  }
  else{
    for(int i=top; i>=0; i--)
      {
        printf("%d\n", stack[i]);
       
      }
  }
}

int main()
{
  int stack[MAX];
  int top=-1;
  int choice, value;
  do{
    printf("Stack menu\n");
    printf("1. Push\n");
    printf("2.Pop\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("\n");
    printf("Enter your choice");
    scanf("%d", &choice);
    printf("\n");

    switch(choice)
      {
        case 1:
        printf("Enter value to be pushed:");
        scanf("%d", &value);
        push(stack, &top, value);
        break;
        case 2:
        value=pop(stack, &top);
        if (value!=-1)
          printf("%d value popped from the stack\n", value);
        break;
        case 3:
        display(stack, top);
        break;
        case 4:
        printf("Exiting the program");
        break;
        default:
        printf("Invalid choice! Please try again");
      }
  }while (choice!=4);
  return 0;
}
