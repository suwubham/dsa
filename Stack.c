#include <stdio.h>
#include <stdlib.h>

struct stack {
	int top;
	int* data;
	int size;
}* s;

int isEmpty() {
	if (s->top == -1) {
		return 1;
	} else {
		return 0;
	}
}

int isFull() {
	if (s->top == s->size - 1) {
		return 1;
	} else {
		return 0;
	}
}

void push(int data) {
	if (isFull()) {
		printf("Stack Overflow\n");
	} else {
		s->top++;
		s->data[s->top] = data;
	}
}

int pop() {
	if (isEmpty()) {
		printf("Stack is Empty\n");
		return -1;
	} else {
		int val = s->data[s->top];
		s->top--;
		return val;
	}
}

void main() {
	s = (struct stack*)malloc(sizeof(struct stack));
	s->top = -1;
	s->size = 10;
	s->data = (int*)malloc(s->size * sizeof(int));

	push(1);
	push(2);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
}