#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct List{
	Node *head;
	Node *tail;
};

typedef struct Node Node;
typedef struct List List;
void Init(List &l);
Node *getNode(int x);
void addFirst(List &l, Node *newNode);
void InsertFirst(List &l, int x);
void insert(List &l, int k, int x);
void Separating_List(List &l, List &l1, int x);
void del(List &l, int k);
int size(List l);
void xuat(List l);

int main() {
	List l, l1;
	Init(l);
	Init(l1);
	do {
		int x;
		printf("Them vao dau danh sach (-1 de ket thuc): ");
		scanf("%d", &x);
		if (x == -1) {
			break;
		}
		InsertFirst(l, x);
	} while (1);
	int k;
	printf("Nhap phan tu k de tach danh sach: ");
	scanf("%d", &k);
	Separating_List(l, l1, x);
	return 0;
}

void Init(List &l) {
	l.head = l.tail = NULL;
}

Node *getNode(int x) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		return NULL;
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void addFirst(List &l, Node *newNode) {
	if (l.head == NULL) {
		l.head = newNode;
		l.tail = l.head;
	}
	else {
		newNode->next = l.head;
		l.head = newNode;
	}
}

void InsertFirst(List &l, int x) {
	Node *newNode = getNode(x);
	if (newNode == NULL) {
		return;
	}
	addFirst(l, newNode);
}


void del(List &l, int k) { // Xoa node k
	Node *p = l.head;
	Node *tmp = NULL;
	while (p != NULL && p->data != k) {
		tmp = p;
		p = p->next;
	}
	if (p == NULL) {
		return;
	}
	if (tmp == NULL) {
		l.head = p->next;
	}
	else {
		tmp->next = p->next;
	}
	free(p);
}

void Separating_List(List &l, List &l1, int x) {
	Node *p = l.head;
	Node *p1 = l1.head;
	while (p != NULL) {
		Node *newNode = getNode(x);
		if (p->data >= x) {
			if (l1.head == NULL) {
				l1.head = p;
				l1.last = l1.head; 
			}
			else {
				newNode-> next
			}
		}
		p = p->next;
	}
}

int size(List l) {
	int cnt = 0;
	Node *p = l.head;
	while (p != NULL) {
		++cnt;
		p = p->next;
	}
	return cnt;
}

void xuat(List l) {
	Node *p = l.head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
