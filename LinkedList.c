#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node {
    int data;
    struct node *next;
};

struct node *create(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void insertatfront(struct node **head,int data) {
    struct node *newnode=create(data);
    newnode->next=*head;
    *head=newnode;
}

void insertatend(struct node **head,int data) {
    struct node *newnode=create(data);
    if (*head==NULL) {
        *head=newnode;
        return;
    }
    struct node *temp=*head;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newnode;
}

void insertanywhere(struct node **head,int data,int pos) {
    if (*head==NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos==1) {
        insertatfront(head,data);
        return;
    }
    struct node *newnode=create(data);
    struct node *temp=*head;
    int i=1;
    while (i<pos-1 && temp!=NULL) {
        temp=temp->next;
        i++;
    }
    if (temp==NULL) {
        printf("Invalid position\n");
    } else {
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void deletefromfront(struct node **head) {
    if (*head==NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp=*head;
    *head=(*head)->next;
    free(temp);
}

void deletefromend(struct node **head) {
    if (*head==NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next==NULL) {
        free(*head);
        *head=NULL;
        return;
    }
    struct node *temp=*head;
    struct node *prev=NULL;
    while (temp->next!=NULL) {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}

void deleteanywhere(struct node **head,int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = *head;
    if (pos == 1) {
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct node *prev = NULL;
    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}


void display(struct node *head) {
    while (head!=NULL) {
        printf("%d\n",head->data);
        head=head->next;
    }
}

int main() {
    struct node *head=NULL;
    int choice,data,pos;
    do {
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert at a position\n");
        printf("4. Delete from front\n");
        printf("5. Delete from end\n");
        printf("6. Delete from a postion\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &data);
                insertatfront(&head,data);
                break;
            case 2:
                printf("Enter a value to insert: ");
                scanf("%d", &data);
                insertatend(&head,data);
                break;
            case 3:
                printf("Enter a value to insert: ");
                scanf("%d", &data);
                printf("Enter a position: ");
                scanf("%d", &pos);
                insertanywhere(&head,data,pos);
                break;
            case 4:
                deletefromfront(&head);
                break;
            case 5:
                deletefromend(&head);
                break;
            case 6:
                printf("Enter a position: ");
                scanf("%d" ,&pos);
                deleteanywhere(&head,pos);
                break;
            case 7:
                printf("Singly Linked List elements\n");
                display(head);
                break;
            case 8:
                printf("Exiting...");
                break;
            default:
            printf("Invalid choice");
        }
    } while (choice !=8);
    return 0;
}