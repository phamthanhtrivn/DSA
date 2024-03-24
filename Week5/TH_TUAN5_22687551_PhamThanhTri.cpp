#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ngay{
	int ngay, thang, nam;
};

struct SinhVien{
	char maSV[8];
	char hoTen[50];
	int gioiTinh;
	Ngay ngaySinh;
	char diaChi[100];
	char lop[12];
	char khoa[7];
};

struct Node {
	SinhVien data;
	struct Node *next;
};

struct List{
	struct Node *first;
	struct Node *last;
};

void KhoiTao(List &L);
Node *getNode(SinhVien x);
int nhapSV(SinhVien &x);
void nhapDSSV(List &l);
void pushBack(List &l, SinhVien x);
void xuatSinhVien(SinhVien s);
void xuatDSSV(List &l);
int search(List l, char ma[8]);
int pushBack_KhongTrung(List &l, SinhVien x);

int main() {
	List l;
	KhoiTao(l);
	nhapDSSV(l);
	xuatDSSV(l);
	return 0;
}

void KhoiTao(List &l) {
	l.first = l.last = NULL;
}

void pushBack(List &l, SinhVien x) {
	Node *newNode = getNode(x);
	if (newNode == NULL) {
		printf("Khong the nhap sinh vien!\n");
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

Node *getNode(SinhVien x) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		return NULL;
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

int nhapSV(SinhVien &x) {
	fflush(stdin);
	printf("Nhap ma so sinh vien: ");
	gets(x.maSV);
	if (strcmp(x.maSV, "0") == 0) {
		return 0;
	}
	fflush(stdin);
	printf("Ho ten: ");
	gets(x.hoTen);
	fflush(stdin);
	printf("Gioi tinh(0:Nam/1:Nu): ");
	scanf("%d", &x.gioiTinh);
	fflush(stdin);
	printf("Ngay thang nam sinh: ");
	scanf("%d%d%d", &x.ngaySinh.ngay, &x.ngaySinh.thang, &x.ngaySinh.nam);
	fflush(stdin);
	printf("Dia chi: ");
	gets(x.diaChi);
	fflush(stdin);
	printf("Lop: ");
	gets(x.lop);
	fflush(stdin);
	printf("Khoa: ");
	gets(x.khoa);
	return 1;
}

void nhapDSSV(List &l) {
	printf("Bat dau nhap DSSV. Nhap MSSV = 0 de dung!\n");
	SinhVien x;
	int flag = nhapSV(x);
	while (flag) {
		pushBack_KhongTrung(l, x);
		flag = nhapSV(x);
	}
	printf("Ket thuc nhap DSSV.\n");
}

void xuatSinhVien(SinhVien s) {
	char gt[4];
	if (s.gioiTinh == 0) {
		strcpy(gt, "Nam");
	}
	else {
		strcpy(gt, "Nu");
	}
	printf("%10s %20s %5d/%d/%d %5s %40s %8s %8s", 
	s.maSV, s.hoTen, s.ngaySinh.ngay, s.ngaySinh.thang, s.ngaySinh.nam, gt, s.diaChi, s.khoa, s.lop);
}

void xuatDSSV(List &l) {
	Node *head = l.first;
	while (head != NULL) {
		xuatSinhVien(head->data);
		head = head->next;
	}
}

int search(List l, char ma[8]) {
	Node *head = l.first;
	while (head != NULL) {
		if (strcmp(head->data.maSV, ma) == 0) {
			return 1;
		}
	}
	return -1;
}

int pushBack_KhongTrung(List &l, SinhVien x) {
	if (search(l, x.maSV)) {
		printf("Ma sinh vien trung");
		return 0;
	}
	else {
		pushBack(l, x);
		return 1;
	}
}

void popFront(List &l) {
	Node *head = l.first;
	l.first = head->next;
	free(head);
}

void popAfter(List &l, Node *p) {
	Node *q = p->next;
	p->next = q->next;
	free(q);
}

Node *timXoa(List l, char ma[8]) {
	Node *head = l.first;
	while (head != l.last) {
		if (strcmp(head->next->data.maSV, ma) == 0) {
			break;
		}
		head = head->next;
	}
	if (head != l.last) {
		return head;
	}
	else {
		return NULL;
	}
}

int XoaX(List &l, char ma[8]) {
	if (strcmp(l.first->data.maSV, ma) == 0) {
		popFront(l);
		return 1;
	}
	else {
		Node *p = timXoa(l, ma);
		if (p == NULL) {
			printf("Khong tim thay phan tu can xoa!\n");
			return 0;
		}
		else {
			popAfter(l, p);
			return 1;
		}
	}
}

