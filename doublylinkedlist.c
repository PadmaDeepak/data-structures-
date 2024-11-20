#include <stdio.h>
#include <stdlib.h>

// node creation
struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

// insert node at the front
    void insertFront(struct Node** head, int data) {
      // allocate memory for newNode
      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

      // assign data to newNode
      newNode->data = data;

      // make newNode as a head
      newNode->next = (*head);

      // assign null to prev
      newNode->prev = NULL;

      // previous of head (now head is the second node) is newNode
      if ((*head) != NULL)
        (*head)->prev = newNode;

      // head points to newNode
      (*head) = newNode;
    }
// Function to delete a node from a specified position
    void deleteAtPosition(struct Node** head, int position)
    {
        if (*head == NULL) {
            printf("The list is already empty.\n");
            return;
        }
       struct Node* temp = *head;
        if (position == 1) {
            if (*head == NULL) {
            printf("The list is already empty.\n");
            return;
        }
        struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
            return;
        }
        for (int i = 1; temp != NULL && i < position; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position is greater than the number of "
                   "nodes.\n");
            return;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        free(temp);
    }

// print the doubly linked list
void displayList(struct Node* node) {
  struct Node* last;

  while (node != NULL) {
    printf("%d->", node->data);
    last = node;
    node = node->next;
  }
  if (node == NULL)
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // Initialize the doubly linked list as empty
    int choice, data, position;

    while (1) {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Insert at Front\n");
        printf("2. Delete at Position\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertFront(&head, data);
                printf("Node inserted at the front.\n");
                break;

            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;

            case 3:
                printf("The list is: ");
                displayList(head);
                break;

            case 4:
                printf("Exiting the program.\n");
                // Free all remaining nodes in the list before exiting
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
