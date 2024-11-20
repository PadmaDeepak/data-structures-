#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};


struct node *CreateNode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertatfirst(struct node **head, int data)
{
    struct node *newnode = CreateNode(data);
    newnode->next = *head;
    *head = newnode;
}

struct node *Concate(struct node *head1,struct node *head2){
    struct node *temp = head1;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
};

struct node *Sort(struct node *head){
    struct node *temp,*current;
    current = head;
    while(current!=NULL){
        temp = head;
        while(temp->next!=NULL){
            if(temp->data > temp->next->data){
                int t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
            }
            temp = temp->next;
        }
        current = current->next;
    }

    return head;
}


struct node *Reverse(struct node *head){
    struct node *temp,*prev,*next;
    prev = NULL;
    temp = head;

    while(temp!=NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;

    return head;
}

void display(struct node **head)
{
    if (*head == NULL)
    {
        printf("Empty");
    }
    else
    {
        struct node *temp = *head;
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int choice, value;

    printf("Enter 5 elements for Linked List 1:\n");
    for (int i = 0; i < 5; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertatfirst(&head1, value);
    }

    printf("Enter 5 elements for Linked List 2:\n");
    for (int i = 0; i < 5; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertatfirst(&head2, value);
    }

    printf("Initial Linked Lists:\n");
    display(&head1);
    display(&head2);

    do {
        printf("\nChoose an operation:\n");
        printf("1. Sort\n");
        printf("2. Reverse\n");
        printf("3. Concatenate\n");
        printf("4. Display Linked Lists\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head1 = Sort(head1);
                head2 = Sort(head2);
                printf("Sorted Linked Lists:\n");
                display(&head1);
                display(&head2);
                break;
            case 2:
                head1 = Reverse(head1);
                head2 = Reverse(head2);
                printf("reversed Linked Lists:\n");
                display(&head1);
                display(&head2);
                break;
            case 3:
                head1 = Concate(head1, head2);
                printf("concatenated Linked Lists:\n");
                display(&head1);
                display(&head2);
                break;
            case 4:
                printf("Current Linked Lists:\n");
                display(&head1);

                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
