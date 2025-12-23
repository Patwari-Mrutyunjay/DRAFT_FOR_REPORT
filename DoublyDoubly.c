#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL, *newnode;

createList(n){
    int i,data;
    struct node *temp;
    for(i=1; i<=n; i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter data for %d node: ",i);
        scanf("%d",&data);
        newnode->data=data;
        newnode->prev=NULL;
        newnode->next=NULL;

        if(head==NULL){
            head=temp=newnode;

        }
        else{
            temp->next=newnode;
            newnode->prev=temp->prev;
            temp=newnode;
        }
    }
    printf("\nList created Bhai! ");
}

struct node* createNode(){
    int data;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data for this left new node: ");
        scanf("%d",&data);
        newnode->data=data;
        newnode->prev=NULL;
        newnode->next=NULL;
    return newnode;
}

void displayList(){
    struct node *temp;
    temp=head;
    if(head==NULL){
        printf("\nThe list is empty! Nothing to display.");
        return;
    }
    printf("\nThe Linked list is:\n");
    while(temp!=NULL){
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void insertAtLeft(int value){
    struct node *temp;
    temp=head;

    // if(temp==NULL){
    //     printf("\nInvalid position");
    //     return;
    // }

    while(temp->data!=value && temp!=NULL){
        temp=temp->next;
    }

    newnode->next=temp;
    newnode->prev=temp->prev;
    temp->prev->next=newnode;
    temp->prev=newnode;




}

void main(){
    int choice,n,value;

    printf("\n--Doubly Linked List operations--\n");
    printf("\n1.Create a Linked List");
    printf("\n2.Insert the node at the left");
    printf("\n3. Display LIst");
    printf("\n4. Exit ");
    printf("");

    while(1){
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:printf("\nEnter no of nodes: ");
                    scanf("%d",&n);
                     createList(n);
                     break;

            case 2: printf("\nEnter a particular node: ");
                    scanf("%d",&value);
                    insertAtLeft(value);
                    break;

            case 3: displayList();
                    break;

            case 4: printf("\nProgram ended successfully");
                     exit(0);

            default:printf("\nInvalid choice!");
                    break;

        }
    }
}
