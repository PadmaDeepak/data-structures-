#include<stdio.h>
#include<stdlib.h>

 struct Node
 {
     int data;
     struct Node *left,*right;
 };

  struct Node* newnode(int value)
  {
        struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=value;
        temp->left=temp->right=NULL;
        return temp;
  }
  struct Node* insertNode(struct Node* node,int value)
  {
      if(node==NULL){
            return newnode(value);
      }
      if(value<node->data)
      {
          node->left=insertNode(node->left,value);
      }
      else if(value>node->data)
      {
          node->right=insertNode(node->right,value);
      }
      return node;
  }

  void postOrder(struct Node* root)
  {
      if(root!=NULL)
      {
          postOrder(root->left);
          postOrder(root->right);
          printf("%d ",root->data);
      }
  }

  void inOrder(struct Node* root)
  {
      if(root!=NULL)
      {
          inOrder(root->left);
          printf("%d ",root->data);
          inOrder(root->right);
      }
  }

  void preOrder(struct Node* root)
  {
      if(root!=NULL)
      {
          printf("%d ",root->data);
          preOrder(root->left);
          preOrder(root->right);
      }
  }

  int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Insert a node into the binary tree\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Inorder Traversal:\n");
                inOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal:\n");
                preOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal:\n");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
