#include <stdio.h>

struct Node {
	int data;
	Node *link;
};

struct stack{
	Node *top;
};

void init(stack &s);
int Empty(stack s);
void push(stack &s, int x);
int pop(stack &s);
void duyet(stack s);

int main() {
	stack s;
	init(s);
	push(s, 4);
	push(s, 1);
	push(s, 2);
	push(s, 7);
	push(s, 5);
	duyet(s);
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	duyet(s);
	return 0;
}

void init(stack &s) {
	s.top = NULL;
}

int Empty(stack s) {
	return s.top == NULL ? 1 : 0;
}

void push(stack &s, int x) {
	Node *p = new Node;
	if (p == NULL) {
		return;
	}
	p->data = x;
	p->link = s.top;
	s.top = p;
}

int pop(stack &s) {
	int x;
	if (!Empty(s)) {
		Node *p = s.top;
		s.top = p->link;
		x = p->data;
		delete(p);
		return x;
	}
}

void duyet(stack s) {
	Node *p = s.top;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}
