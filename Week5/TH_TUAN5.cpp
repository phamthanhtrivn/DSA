#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Ngay {
	int ngay, thang, nam;
};

struct SinhVien{
	char maSV[8];
	char hoTen[50];
	char gioiTinh[4];
	Ngay ngaySinh;
	char diaChi[100];
	char lop[12];
	cahr khoa[7];
};

struct Node {
	SinhVien data;
	struct Node *next;
};

struct List{
	struct Node *first;
	struct Node *last;
};

Node *getNode(SinhVien x);
void Init(List &l);
void pushBack(List &l, SinhVien x);
int NhapSinhVien(SinhVien &x);
void nhapDSSV(List &l);
void xuatSinhVien(SinhVien x);
void xuatDSSV(List l);
int search(List l, char ma[8]);
int pushBack_KhongTrung(List &l, SinhVien x);
void removeFirst(List &l);
void removeAfter(List &l, Node *q);
Node *timXoa(List l, char ma[8]);
int XoaX(List &l, char ma[8]);
void swap(SinhVien &a, SinhVien &b);
void interchangSortList(List &l);
Node *partition(Node *l, Node *r);
void quickSort(List &l);

int main() {
	
	return 0;
}

Node *getNode(SinhVien x) {
	Node *newNode = malloc(sizeof(Node));
	if (newNode == NULL) {
		return NULL;
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void Init(List &l) {
	l.first = l.last = NULL;
}

void pushBack(List &l, SinhVien x) {
	Node *newNode = getNode(x);
	if (newNode == NULL) {
		printf("Khong the tao sinh vien!\n");
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

int NhapSinhVien(SinhVien &x) {
	printf("Ma so sinh vien: ");
	fflush(stdin);
	gets(x.maSV);
	if (strcmp(x.maSV, "0") == 0) {
		return 0;
	}
	printf("Ho ten: ");
	gets(x.hoTen);
	printf("Gioi tinh(Nam/Nu): ");
	gets(x.gioiTinh);
	printf("Ngay/Thang/Nam sinh: ");
	scanf("%d%d%d", &x.ngaySinh.ngay, &x.ngaySinh.thang, &x.ngaySinh.nam);
	printf("Dia chi: ");
	fflush(stdin);
	gets(x.diaChi);
	printf("Lop: ");
	gets(x.diaChi);
	printf("Khoa: ");
	gets(x.khoa);
	return 1;
}

void nhapDSSV(List &l) {
	printf("\nBat dau nhap danh sach sinh vien. Nhap MaSV = 0 de dung\n");
	SinhVien x;
	int flag = SinhVien(x);
	while (flag) {
		pushBack_KhongTrung(l, x);
		flag = SinhVien(x);
	}
	printf("\nKet thuc nhap sinh vien!\n");
}

void xuatSinhVien(SinhVien x) {
	printf("\n%10s %20s %5d/%d/%d %5s %40s %8s %8s", x.maSV, x.hoTen, x.ngaySinh.ngay, x.ngaySinh.thang,
	x.ngaySinh.nam, x.gioiTinh, x.diaChi, x.khoa, x.lop);
}

void xuatDSSV(List l) {
	Node *p = l.first;
	while (p != NULL) {
		xuatSinhVien(p->data);
		p = p->next;
	}
}

int search(List l, char ma[8]) {
	Node *p = l.first;
	while (p != NULL) {
		if (strcmp(p->data.maSV, ma) == 0) {
			return 1;
		}
	}
	return -1;
}

int pushBack_KhongTrung(List &l, SinhVien x) {
	if (search(l, x.maSV) == 1) {
		printf("Ma sinh vien trung\n");
		return 0;
	}
	else {
		pushBack(l, x);
		return 1;
	}
}

void removeFirst(List &l) {
	if (l.first == NULL) {
		printf("Danh sach rong khong the xoa!\n");
		return;
	}
	Node *p = l.first;
	l.first = p->next;
	if (l.first == NULL) l.last = NULL;
	free(p);
}

void removeAfter(List &l, Node *q) {
	if (q != NULL && q->next != NULL) {
		Node *p = q->next;
		q->next = p->next;
		if (p == l.last) l.last = q;
		free(p);
	}
}

Node *timXoa(List l, char ma[8]) {
	Node *p = l.first;
	while (p != l.last) {
		if (strcmp(p->next->data.maSV, ma) == 0) {
			break;
		}
		p = p->next;
	}
	if (p != l.last) {
		return p;
	}
	else {
		return NULL;
	}
}

int XoaX(List &l, char ma[8]) {
	if (strcmp(l.first->data.maSV, ma) == 0) {
		removeFirst(l); return 1;
	}
	else {
		Node *q = timXoa(l, ma);
		if (q == NULL) {
			printf("Khong tim thay phan tu can xoa!\n");
			return 0;
		}
		else {
			removeAfter(l, q);
			return 1;
		}
	}
}

void swap(SinhVien &a, SinhVien &b) {
	SinhVien tmp = a;
	a = b;
	b = tmp;
}

void interchangSortList(List &l) { // sap xep ho ten tang dan
	for (Node *i = l.first; i != l.last; i = i->next) {
		for (Node *j = i->next; j != NULL; j = j->next) {
			if (strcpm(i->data.hoTen, j->data.hoTen) == 1) {
				swap(i->data, j->data);
			}
		}
	}
}

//Node *partition(Node *l, Node *r) {
//	
//}
//
//void quickSort(List &l) {
//	
//}

void SListAppend(List &l, List &l2) {
	if (l2.first == NULL) {
		return;
	}
	if (l.first == NULL) {
		l = l2;
	}
	else {
		l.last->next = l2.first;
		l.last = l2.last;
	}
	Init(l2);
}

