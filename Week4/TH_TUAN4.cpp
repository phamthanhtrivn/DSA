#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
	float heSo;
	int soMu;
	struct Node *next;
};

struct List {
	struct Node *first;
	struct Node *last;
};

typedef struct Node Node;
typedef struct List List;

void init(List &l);
Node *getNode(float heSo, int soMu);
void pushBack(List &l, float heSo, int soMu);
void nhapDaThuc(List &l);
void swap(float &a, float &b);
void swap2(int &a, int &b);
void selectionSort(List &l);
void duyet(List &l);
void congDaThuc(List l1, List l2, List &l3);

int main() {
	List l1, l2, l3;
	init(l1); init(l2); init(l3);
	nhapDaThuc(l1);
	printf("\nDanh sach bieu dien da thuc d1: ");
	duyet(l1);
	nhapDaThuc(l2);
	printf("\nDanh sach bieu dien da thuc d2: ");
	duyet(l2);
	congDaThuc(l1, l2, l3);
	printf("\nDanh sach bieu dien da thuc tong: ");
	duyet(l3);
	return 0;
}

void init(List &l) {
	l.first = l.last = NULL;
}

Node *getNode(float heSo, int soMu) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		return NULL;
	}
	newNode->heSo = heSo;
	newNode->soMu = soMu;
	newNode->next = NULL;
	return newNode;
}

void pushBack(List &l, float heSo, int soMu) {
	Node *newNode = getNode(heSo, soMu);
	if (newNode == NULL) {
		return;
	}
	if (l.first == NULL) {
		l.first = l.last = newNode;
	}
	else {
		l.last->next = newNode;
		l.last = newNode;
	}
}

void duyet(List &l) {
	Node *head = l.first;
	while (head != NULL) {
		printf("%.0f %d    ", head->heSo, head->soMu);
		
		head = head->next;
	}
}

void nhapDaThuc(List &l) {
	float heSo;
	int soMu;
	printf("\nBat dau nhap da thuc(nhap he so 0 de ket thuc)\n");
	while (1) {
		printf("Nhap he so: ");
		scanf("%f", &heSo);
		if (heSo == 0) {
			break;
		}
		printf("Nhap so mu: ");
		scanf("%d", &soMu);
		pushBack(l, heSo, soMu);
	}
	printf("\nDa nhap da thuc xong!\n");
}

void swap(float &a, float &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void swap2(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void selectionSort(List &l) {
	for (Node *i = l.first; i != l.last; i = i->next) {
		Node *max = i;
		for (Node *j = i->next; j != NULL; j = j->next) {
			if (max->soMu < j->soMu) {
				max = j;
			}
		}
		if (i != max) {
			swap(max->heSo, i->heSo);
			swap2(max->soMu, i->soMu);
		}
	}
}

void congDaThuc(List l1, List l2, List &l3) {
	init(l3);
	Node *p = l1.first, *q = l2.first;
	float tongHeSo;
	while (p != NULL & q != NULL) {
		if (p->soMu == q->soMu) {
			tongHeSo = p->heSo + q->heSo;
			if (tongHeSo != 0) {
				pushBack(l3, tongHeSo, p->soMu);
			}
			p = p->next;
			q = q->next;
		}
		else {
			if (p->soMu > q->soMu) {
				pushBack(l3, p->heSo, p->soMu);
				p = p->next;
			}
			else {
				pushBack(l3, q->heSo, q->soMu);
				q = q->next;
			}
		}
	}
	while (p != NULL) {
		pushBack(l3, p->heSo, p->soMu);
		p = p->next;
	}
	while (q != NULL) {
		pushBack(l3, q->heSo, q->soMu);
		q = q->next;
	}
}


