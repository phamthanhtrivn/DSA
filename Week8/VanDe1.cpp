#include <stdio.h>

struct Node {
	int data;
	Node *pLeft;
	Node *pRight;
};

typedef Node *Tree;

Node *makeNode(int x);
void themNodeVaoCay(Node *p, Tree &t);
void nhap(Tree &t, int x);
void xuat(Tree t);

int main() {
	Tree t = NULL;
	nhap(t, 2);
	nhap(t, 3);
	nhap(t, 4);
	nhap(t, 5);
	nhap(t, 6);
	printf("Xuat cay LNR(tang dan): ");
	xuat(t);
	return 0;
}

Node *makeNode(int x) {
	Node *p = new Node;
	if (p == NULL) {
		return NULL;
	}
	p->data = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

void themNodeVaoCay(Node *p, Tree &t) {
	if (t == NULL) { //Neu cay rong
		t = p;
	}
	else {
		if (p->data > t->data) 
			themNodeVaoCay(p, t->pRight);
		else if (p->data < t->data) 
			themNodeVaoCay(p, t->pLeft);
		else 
			return;
	}
}

void nhap(Tree &t, int x) {
	Node *p = makeNode(x);
	themNodeVaoCay(p, t);
}

void xuat(Tree t) {
	if (t != NULL) {
		if (t->pLeft != NULL) 
			xuat(t->pLeft);
		printf("%d ", t->data);
		if (t->pRight != NULL) 
			xuat(t->pRight);
	}
}
