#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
}* head;

void traverse() {
	struct Node* temp = head;
	do {
		printf("%d\n", temp->data);
		temp = temp->next;
	} while (temp != head);
}

void insertAtStart(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	struct Node* temp = head->next;
	while (temp->next != head) {
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	head = newNode;
}

void insertAfter(struct Node* prevNode, int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	struct Node* temp = head;
	while (temp != prevNode) {
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

void deleteFirst() {
	struct Node* temp = head;
	while (temp->next != head) {
		temp = temp->next;
	}
	temp->next = head->next;
	head = temp->next;
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

void main() {
	head = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n4 = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1;
	head->next = n1;

	n1->data = 2;
	n1->next = n2;

	n2->data = 3;
	n2->next = n3;

	n3->data = 4;
	n3->next = n4;

	n4->data = 5;
	n4->next = head;

	insertAtStart(0);
	insertAfter(n3, 69);
	deleteFirst();
	deleteNode(4);
	traverse();
}