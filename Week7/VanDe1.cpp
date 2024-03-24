#include <stdio.h>

struct Node {
	int data;
	Node *link;
};

struct queue{
	Node *front, *rear;
};

void init(queue &q) {
	q.front = q.rear = NULL;
}

int empty(queue q) {
	return q.front == NULL ? 1 : 0;
}

void enqueue(queue &q, int x) {
	Node *p = new Node;
	p->data = x;
	p->link = NULL;
	if (empty(q)) {
		q.front = q.rear = p;
	}
	else {
		q.rear->link = p;
		q.rear = p;
	}
}

int dequeue(queue &q) {
	if (empty(q)) {
		printf("Queue rong!\n");
		return -1;
	}
	Node *p = q.front;
	q.front = q.front->link;
	if (empty(q)) {
		q.rear = NULL;
	}
	int x = p->data;
	p->link = NULL;
	delete(p);
	return x;
}

int front(queue q) {
	if (empty(q)) return 1;
	return q.front->data;
}

void duyet(queue q) {
	Node *p = q.front;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
}

int main() {
	queue q;
	int k;
	init(q);
	enqueue(q, 4);
	enqueue(q, 2);
	enqueue(q, 5);
	enqueue(q, 1);
	enqueue(q, 6);
	duyet(q);
	return 0;
}
