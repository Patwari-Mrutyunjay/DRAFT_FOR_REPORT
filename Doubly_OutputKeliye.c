#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* head = NULL;

// (a) Create a new node and add at end
void create(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// (b) Insert new node to the left of a node with given value
void insertLeft(int key, int value) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Key not found!\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode;

    temp->prev = newNode;
}

// (c) Delete node by value
void deleteValue(int value) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// (d) Display list
void display() {
    struct Node* temp = head;
    printf("List: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value, key;

    while (1) {
        printf("\n1. Create Node");
        printf("\n2. Insert Left of Node");
        printf("\n3. Delete Node by Value");
        printf("\n4. Display");
        printf("\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            create(value);
            break;

        case 2:
            printf("Enter key (insert left of): ");
            scanf("%d", &key);
            printf("Enter new value: ");
            scanf("%d", &value);
            insertLeft(key, value);
            break;

        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteValue(value);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
