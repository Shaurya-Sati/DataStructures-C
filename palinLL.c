//C program to check if a list is palindrome

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

struct node *reverse(struct node *head) {
	struct node *prev = NULL, *curr = head, *next = NULL;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

int palindrome(struct node *head) {
	if (head==NULL) {
		printf("List is empty\n");
		return 0;
	}
	struct node *slow=head;
	struct node *fast=head;
	while (fast!=NULL && fast->next!=NULL) {
		slow=slow->next;
		fast=fast->next->next;
	}
	struct node *second=reverse(slow->next);
	slow->next=NULL;
	struct node *temp1=head;
	struct node *temp2=second;
	while (temp1!=NULL && temp2!=NULL) {
		if (temp1->data!=temp2->data) {
			return 0;
		}
		temp1=temp1->next;
		temp2=temp2->next;
	}
	return 1;
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
	insertatend(&head,2);
	insertatend(&head,1);
	if (palindrome(head)) {
		printf("List is a palindrome\n");
	} else {
		printf("List is not a palindrome\n");
	}
	return 0;
}