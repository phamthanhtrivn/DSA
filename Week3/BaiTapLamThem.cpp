#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	Node *link;
};

struct List{
	Node *first;
	Node *last;
};

typedef struct Node Node;
typedef struct List List;

void Init(List &l);
Node *getNode(int x);
void addFirst(List &l, Node *newNode);
void InsertFirst(List &l, int x);
void CreateListFirst(List &l);
void printList(List l);
long SumEvenNumber(List &l);
int Search(List l, int x);
void addLast(List &l, Node *p);
void InsertLast(List &l, int x);
void CreateListLast(List &l);

int main() {
	List l;
	Init(l);
	CreateListFirst(l);
	printList(l);
	printf("\nTong cac phan tu chan trong List: %ld\n", SumEvenNumber(l));
	printf("Nhap phan tu can tim: ");
	int x; scanf("%d", &x);
	if (Search(l, x) == 1) {
		printf("Found\n\n");
	}
	else {
		printf("Not Found\n\n");
	}
	CreateListLast(l);
	printList(l);
	return 0;
}

void Init(List &l) {
	l.first = l.last = NULL;
}

Node *getNode(int x) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		return NULL;
	}
	newNode->data = x;
	newNode->link = NULL;
	return newNode;
}

void addFirst(List &l, Node *newNode) {
	if (l.first == NULL) {
		l.first = newNode;
		l.last = l.first;
	}
	else {
		newNode->link = l.first;
		l.first = newNode;
	}
}

void InsertFirst(List &l, int x) {
	Node *newNode = getNode(x);
	if (newNode == NULL) {
		return;
	}
	addFirst(l, newNode);
}

void CreateListFirst(List &l) {
	int x;
	do { 
		printf("Nhap danh sach cac so nguyen(nhap -1 de ket thuc) vao dau:");
		scanf("%d", &x);
		if (x == -1) {
			break;
		}
		InsertFirst(l, x);
	} while (1);
	printf("\nDa nhap du lieu xong: ");
}

void printList(List l) {
	Node *p = l.first;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}

long SumEvenNumber(List &l) {
	long sum = 0;
	Node *p = l.first;
	while (p != NULL) {
		if (p->data % 2 == 0) {
			sum += p->data;
		}
		p = p->link;
	}
	return sum;
}

int Search(List l, int x) {
	Node *p = l.first;
	while (p != NULL) {
		if (p->data == x) {
			return 1;
		}
		p = p->link;
	}
	return 0;
}

void addLast(List &l, Node *p) {
	if (l.first == NULL) {
		l.first = l.last = p;
	}
	else {
		l.last->link = p;
		l.last = p;
	}
}

void InsertLast(List &l, int x) {
	Node *newNode = getNode(x);
	if (newNode == NULL) {
		return;
	}
	addLast(l, newNode);
}

void CreateListLast(List &l) {
	int x;
	do {
		printf("Nhap cac so nguyen (nhap -1 de ket thuc) vao cuoi: ");
		scanf("%d", &x);
		if (x == -1) {
			break;
		}
		InsertLast(l, x);
	} while (1);
	printf("\nDa nhap xong danh sach: ");
}

