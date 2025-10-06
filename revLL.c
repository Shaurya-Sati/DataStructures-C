//C program to reverse a linked list (Iterative and Recursive)

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *create(int data) {
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
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

struct node *reverse(struct node *head) { //Iterative method
	struct node *prev=NULL;
	struct node *curr=head;
	struct node *next=NULL;
	while (curr!=NULL) {
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}

struct node *revrecursion(struct node *head) { //Recursive method
	if (head==NULL || head->next==NULL)
		return head;
	struct node *rest=revrecursion(head->next);
	head->next->next=head;
	head->next=NULL;
	return rest;
}

void display(struct node *head) {
	struct node *temp=head;
	while (temp!=NULL) {
		printf("%d ", temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main() {
	struct node *head=NULL;
	insertatend(&head,1);
	insertatend(&head,2);
	insertatend(&head,3);
	insertatend(&head,4);
	insertatend(&head,5);
	printf("List before reversing\n");
	display(head);
	struct node *rev=reverse(head);
	printf("List after reversing\n");
	display(rev);
	return 0;
}