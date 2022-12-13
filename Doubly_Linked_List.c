#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* prev;
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
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
}

void insertAtEnd(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = temp;
	temp->next = newNode;
}

void insertAfter(struct Node* prevNode, int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = prevNode->next;
	prevNode->next = newNode;
	newNode->prev = prevNode;
}

void deleteFirst() {
	head = head->next;
	head->prev = NULL;
}

void deleteLast() {
	struct Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->prev->next = NULL;
}

void DeleteNode(int data) {
	struct Node* temp = head;
	while (temp->data != data) {
		temp = temp->next;
	}
	temp->prev->next = temp->next;
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
	struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n4 = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1;
	head->next = n1;
	head->prev = NULL;

	n1->data = 2;
	n1->next = n2;
	n1->prev = head;

	n2->data = 3;
	n2->next = n3;
	n2->prev = n1;

	n3->data = 4;
	n3->next = NULL;
	n3->prev = n2;

	insertAtStart(0);
	insertAtEnd(5);
	insertAfter(n1, 69);
	deleteFirst();
	deleteLast();
	DeleteNode(2);
	traverse();

	if (search(69)) {
		printf("Item exists in linked list");
	} else {
		printf("Item doesn't exist iin linked list");
	}
}