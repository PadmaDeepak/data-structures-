#include <stdio.h>
#include <stdlib.h>

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

void inseratend(struct node **head, int data)
{
    struct node *newnode = CreateNode(data);
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insertatposition(struct node **head, int data, int pos)
{
    if (pos == 0)
    {
        insertatfirst(head, data);
    }
    else
    {
        struct node *newnode = CreateNode(data);
        struct node *temp = *head;
        for (int i = 0; temp != NULL && i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
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

void deleteatfirst(struct node **head)
{
    if (*head == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        struct node *temp = *head;
        *head = temp->next;
        free(temp);
    }
}

void deleteatend(struct node **head)
{
    if (*head == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        struct node *temp = *head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void deleteatposition(struct node **head, int pos)
{
    if (*head == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        struct node *temp = *head;
        for (int i = 0; temp != NULL && i < pos - 1; i++)
        {
            temp = temp->next;
        }
        struct node *afternode = temp->next->next;
        free(temp->next);
        temp->next = afternode;
    }
}

int main()
{
    struct node **head = NULL;

    while (1)
    {
        printf("To insert\n");
        printf("1 for at beginning\n");
        printf("2 for at end\n");
        printf("3 for at position\n");
        printf("To delete\n");
        printf("4 for at beginning\n");
        printf("5 for at end\n");
        printf("6 for at position\n");
        printf("7 to display\n");
        printf("8 to exit\n");
        int n;
        scanf("%d", &n);
        if (n == 1)
        {
            int data;
            printf("Enter the value\n");
            scanf("%d", &data);
            insertatfirst(&head, data);
        }
        else if (n == 2)
        {
            int data;
            printf("Enter the value\n");
            scanf("%d", &data);
            inseratend(&head, data);
        }
        else if (n == 3)
        {
            int data;
            printf("Enter the value\n");
            scanf("%d", &data);
            printf("Enter the position");
            int pos;
            scanf("%d", &pos);
            if (pos < 0)
            {
                printf("invalid input");
                break;
            }
            insertatposition(&head, data, pos);
        }
        else if (n == 4)
        {
            deleteatfirst(&head);
        }
        else if (n == 5)
        {
            deleteatend(&head);
        }
        else if (n == 6)
        {
            ;
            printf("Enter the position");
            int pos;
            scanf("%d", &pos);
            if (pos < 0)
            {
                printf("invalid input");
                break;
            }
            deleteatposition(&head, pos);
        }
        else if (n == 7)
        {
            display(&head);
        }
        else
            break;
    }
}