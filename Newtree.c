#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// a) Insert into BST
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// b) Traversals
// In-order traversal (Left, Root, Right)
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Pre-order traversal (Root, Left, Right)
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal (Left, Right, Root)
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// c) Display tree elements (In-order is natural sorted output)
void display(struct node* root) {
    printf("\nElements in the tree (In-order): ");
    inorder(root);
}

// Main program
int main() {
    struct node* root = NULL;
    int choice, value;
    printf("\n\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Display Elements\n");
        printf("6. Exit\n");

    while (1) {

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("In-order Traversal: ");
                inorder(root);
                break;

            case 3:
                printf("Pre-order Traversal: ");
                preorder(root);
                break;

            case 4:
                printf("Post-order Traversal: ");
                postorder(root);
                break;

            case 5:
                display(root);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
