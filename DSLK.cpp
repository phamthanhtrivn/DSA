#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct List{
	struct node *head;
	struct node *tail;
};

typedef struct node node;
typedef struct List List;

void KhoiTao(List &l) {
	l.head = l.tail = NULL;
}

void duyet(List l) {
	node *head = l.head;
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int size(List l) {
	node *head = l.head;
	int cnt = 0;
	while (head != NULL) {
		++cnt;
		head = head->next;
	}
	return cnt;
}

node *getNode(int x) {
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void pushFront(List &l, int x) {
	node *newNode = getNode(x);
	if (l.head == NULL) {
		l.head = l.tail = newNode;
	}
	else {
		newNode->next = l.head;
		l.head = newNode;
	}
}

void pushBack(List &l, int x) {
	node *newNode = getNode(x);
	if (l.head != NULL) {
		l.tail->next = newNode;
		l.tail = newNode;
	}
	else {
		l.head = l.tail = newNode;
	}
}

// chen vao vi tri k trong danh sach lien ket
void insert(List &l, int k, int x) { 
	int n = size(l);
	if (k < 1 || k > n + 1) {
		printf("Vi tri chen khong hop le!\n");
		return;
	}
	if (k == 1) {
		pushFront(l, x);
	}
	else if (k == n + 1) {
		pushBack(l, x);
	}
	else {
		node *head = l.head;
		for (int i = 1; i < k - 1; i++) {
			head = head->next;
		}
		node *newNode = getNode(x);
		newNode->next = head->next;
		head->next = newNode;
	}
	
}


int main() {
	List l;
	KhoiTao(l);
	while (1) {
		printf("---------------------------------------------\n");
		printf("0. Thoat\n");
		printf("1. Them vao dau\n");
		printf("2. Them vao cuoi\n");
		printf("3. So node trong DSLK\n");
		printf("4. Duyet DSLK\n");
		printf("5. Chen vao giua\n");
		printf("---------------------------------------------\n");
		printf("Chon: ");
		int lc; scanf("%d", &lc);
		if (lc == 0) {
			break;
		}	
		else if (lc == 1) {
			printf("Nhap gia tri can them: ");
			int x; scanf("%d", &x);
			pushFront(l, x);
		}
		else if (lc == 2) {
			printf("Nhap gia tri can them: ");
			int x; scanf("%d", &x);
			pushBack(l, x);
		}
		else if (lc == 3) {
			printf("%d\n", size(l));
		}
		else if (lc == 4) {
			duyet(l);
		}
		else if (lc == 5) {
			printf("Nhap vi tri chen: ");
			int k; scanf("%d", &k);
			printf("Nhap gia tri can chen: ");
			int x; scanf("%d", &x);
			insert(l, k, x);
		}
	}
	return 0;
}
