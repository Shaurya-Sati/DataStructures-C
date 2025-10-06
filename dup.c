

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

void insertatend(struct node **head, int data) {
	struct node *newnode = create(data);
	if (*head == NULL) {
		*head = newnode;
		return;
	}
	struct node *temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newnode;
}

void remdup(struct node *head) {
	struct node *ptr1=head;
	struct node *ptr2;
	struct node *dup;
	while (ptr1!=NULL && ptr1->next!=NULL) {
		ptr2=ptr1;
		while (ptr2->next!=NULL) {
			if (ptr1->data==ptr2->next->data) {
				dup=ptr2->next;
				ptr2->next=ptr2->next->next;
				free(dup);
			} else {
				ptr2=ptr2->next;
			}
		}
		ptr1=ptr1->next;
	}
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
	insertatend(&head,1);
	insertatend(&head,2);
	insertatend(&head,3);
	insertatend(&head,4);
	printf("Original list\n");
	display(head);
	printf("List after removing duplicates\n");
	remdup(head);
	display(head);
	return 0;
}
