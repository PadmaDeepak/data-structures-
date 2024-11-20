#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int isFull(int front, int rear)
{
  return (front==(rear+1)%MAX);
}

int isEmpty(int front, int rear)
{
  return front==-1;
}

void enqueue(int queue[], int *front, int *rear, int value)
{
  if (isFull(*front, *rear))
  {
    printf("Queue is full. The element cannot be entered.");
  }
  else{
    if(*front==-1)
      *front=0;
    *rear=(*rear+1)%MAX;
    queue[*rear]=value;
    printf("The value has been inserted.");
  }
}

void dequeue(int queue[], int *front, int *rear)
{
  if (isEmpty(*front, *rear))
  {
    printf("Queue is empty. Element cannot be deleted");
  }
  else
  {
    printf("The deleted element is %d", queue[*front]);
    if(*front==*rear)
      *front=*rear=-1;
    else
    {
      *front=(*front+1)%MAX;
    }
  }
}

void display(int queue[], int front, int rear)
{
  if (isEmpty(front, rear))
  {
    printf("Queue is empty. It cannot be displayed");
  }
  else{
    printf("The elements in the queue are:\n");
    int i=front;
    while(i!=rear)
      {
        printf("%d\n", queue[i]);
        i=(i+1)%MAX;
      }
    printf("%d\n", queue[i]);
  }
}

int main()
{
  int queue[MAX];
  int front=-1, rear=-1;
  int choice, value;

  do{

    printf("\nCircular Queue menu:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter a valid option:");
    scanf("%d", &choice);

    switch(choice)
      {
        case 1:
          printf("Enter the value to be inserted:\n");
          scanf("%d", &value);
          enqueue(queue, &front, &rear, value);
          break;
        case 2:
          dequeue(queue, &front, &rear);
          break;
        case 3:
             display(queue, front, rear);
             break;
        case 4:
             printf("The program has been terminated");
             break;  
        default:
             printf("Invalid option. Please enter a valid choice:");
      }
  }while(choice!=4);
}
