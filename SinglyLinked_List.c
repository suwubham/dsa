#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
}* head;

void traverse() {
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

void insertAtStart(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}

void insertAtEnd(int data) {
	struct Node* temp = head;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
	newNode->data = data;
	newNode->next = NULL;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}

void insertAfter(struct Node* prevNode, int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
	newNode->data = data;
	newNode->next = prevNode->next;
	prevNode->next = newNode;
}

void deleteFirst() {
	head = head->next;
}

void deleteLast() {
	struct Node* temp = head;
	while (temp->next->next != NULL) {
		temp = temp->next;
	}
	temp->next = NULL;
}

void deleteNode(int data) {
	struct Node* temp1 = head;
	struct Node* temp2 = temp1->next;
	while (temp2->data != data) {
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
}

int search(int data) {
	struct Node* temp = head;
	while (temp != NULL) {
		if (temp->data == data) {
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

void main() {
	head = (struct Node*)malloc(sizeof(struct Node*));
	struct Node* n1 = (struct Node*)malloc(sizeof(struct Node*));
	struct Node* n2 = (struct Node*)malloc(sizeof(struct Node*));
	struct Node* n3 = (struct Node*)malloc(sizeof(struct Node*));
	struct Node* n4 = (struct Node*)malloc(sizeof(struct Node*));

	head->data = 1;
	head->next = n1;

	n1->data = 2;
	n1->next = n2;

	n2->data = 3;
	n2->next = n3;

	n3->data = 4;
	n3->next = n4;

	n4->data = 5;
	n4->next = NULL;

	insertAtStart(0);
	insertAtEnd(6);
	insertAfter(n3, 69);
	deleteFirst();
	deleteLast(head);
	deleteNode(3);
	traverse(head);

	if (search(5)) {
		printf("Item exists in linked list.");
	} else {
		printf("Item doesn't exist in linked list.");
	}
}