#include <stdio.h>

//Cho thong tin sinh vien gom: ma, ten, ngaysinh, dia chi, dtb
//1. Them sinh vien vao danh sach(khong trung ma)
//2. Doc, ghi file
//3. Sap xep sinh vien theo diem tang dan
//4. Tim sinh vien co ma X
//5. Xoa sinh vien co ma X
//6. Xoa tat ca sinh vien o HCM
//7. Them sinh vien vao sau sinh vien X
//8. Xoa sinh vien sau sinh vien X
//9. Dao nguoc danh sach
//10. Sua thong tin sinh vien co ma X

struct NamSinh{
	int ngay, thang, nam;
};

struct SinhVien{
	char ma[8];
	char ten[100];
	NamSinh ngaysinh;
	char diachi[100];
	float gpa;
};

struct Node{
	SinhVien data;
	Node *next;
};

struct List{
	Node *head;
	Node *tail;
};

void init(List &l);
void ghiFile(char *filenam, List l);
void docFile(char *filename, List &l);
Node *makeNode(SinhVien a);
void pushBack(List &l, SinhVien a);
void pushBack_KhongTrung(List &l, SinhVien a) ;
void insert(List &l, SinhVien a, Node *q);
void nhap(SinhVien &a);
void nhapDSSV(List &l);
void in1SV(SinhVien a);
void duyet(List &l);
Node *Search(List l, char ma[8]);
void swap(SinhVien a, SinhVien b);
void sort(List l);
void pop(List &l, char ma[8]);
void removeList(List &l);
void removeL(List &l, char dc[100]);
int size(List l);

int main() {
	List l;
	init(l);
	do {
		printf("=================================Menu=================================\n");
		printf("1. Nhap DSSV\n");
		printf("2. Doc DSSV vao dslk\n");
		printf("3. Ghi DSSV vao file\n");
		printf("4. ")
	} while (1)
	return 0;
}

void ghiFile(char *filenam, List l) {
	FILE *f = fopen(filename, "wb");
	if (!f) {
		printf("Khong the mo file de ghi!\n");
		return;
	}
	Node *p = l.head;
	while (p != NULL) {
		SinhVien a = p->data;
		fwrite(&a, sizeof(SinhVien), 1, f);
		p = p->next;
	}
	printf("Ghi vao file thanh cong!\n");
	fclose(f);
}

void docFile(char *filename, List &l) {
	init(l);
	FILE *f = fopen(filename, "rb");
	if (!f) {
		printf("Khong the mo file de doc!\n");
		return;
	}
	SinhVien a;
	while (fread(&a, sizeof(SinhVien), 1, f) > 0) {
		pushBack(l, a);
	}
	printf("Doc file thanh cong!\n");
	fclose(f);
}


void init(List &l) { // Khoi tao danh sach
	l.head = l.tail = NULL;
}

Node *makeNode(SinhVien a) { // Tao 1 sinh vien cho danh sach
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		return NULL;
	}
	newNode->data = a;
	newNode->next = NULL;
	return newNode;
}

void pushBack(List &l, SinhVien a) { //Them sinh vien vao cuoi danh sach
	Node* newNode = makeNode(a);
	if (newNode == NULL) {
		printf("Khong du bo nho de cap phat!\n");
		return;
	}
	if (l.head == NULL) {
		l.head = l.tail = newNode;
	}
	else {
		l.tail->next = newNode;
		l.tail = newNode;
	}
}

void pushBack_KhongTrung(List &l, SinhVien a) { //Them sinh vien vao cuoi khong trung danh sach
	Node *p = Search(l, a.ma);
	if (p == NULL) {
		pushBack(l, a);
	}
	else {
		printf("Khong the them vi trung ma sinh vien!\n");
		return;
	}
}

void nhap(SinhVien &a) {
	fflush(stdin);
	printf("Nhap MSSV: ");
	gets(a.ma);
	printf("Nhap ho ten: ");
	gets(a.ten);
	printf("Nhap ngay sinh: ");
	scanf("%d%d%d", &a.ngaysinh.ngay, &a.ngaysinh.thang, &a.ngaysinh.nam);
	fflush(stdin);
	printf("Nhap dia chi: ");
	gets(a.diachi);
	printf("Nhap gpa: ");
	scanf("%f", &a.gpa); 
}

void nhapDSSV(List &l) {
	int n;
	init(l);
	SinhVien a;
	printf("Nhap so luong sinh vien muon nhap: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		nhap(a);
		pushBack_KhongTrung(l, a);
	}
}

void in1SV(SinhVien a) {
	printf("%-10s | %-20s | %-10d/%d/%d | %-20s | %-10.2f\n", a.ma, a.ten, a.ngaysinh.ngay, a.ngaysinh.thang, a.ngaysinh.nam, a.diachi, a.gpa);
}

void duyet(List &l) {
	Node *p = l.head;
	printf("%-10s | %-20s | %-18s | %-20s | %-10s\n", "Ma SV", "Ho Ten", "Ngay Sinh", "Dia Chi", "DTB");
	while (p != NULL) {
		in1SV(p->data);
		p = p->next;
	}
} 

Node *Search(List l, char ma[8]) {
	Node *p = l.head;
	while (p != NULL) {
		if (strcmp(p->data.ma, ma) == 0) {
			return p;
		}
		p = p->next;
	}
	return NULL;
} 

void insert(List &l, SinhVien a, Node *q) { // Them sinh vien vao sau sinh vien q
	Node *newNode = makeNode(a);
	if (q != NULL) {
		a->next = q->next;
		q->next = a;
		if (q->next == l.tail) l.tail = a;
	}
}

void swap(SinhVien a, SinhVien b) {
	SinhVien tmp = a;
	a = b;
	b = tmp;
}

void sort(List l) { // Sap xep sinh vien theo gpa tang dan
	for (Node *i = l.head; i != l.tail; i = i->next) {
		for (Node *j = i->next; j != NULL; j = j->next) {
			if (i->data.gpa > j->data.gpa) {
				swap(i->data, j->data);
			}
		}
	}
}

void removeHead(List &l) {
	if (l.head == NULL) {
		printf("Danh sach rong!\n");
		return;
	}
	Node *p = l.head;
	l.head = p->next;
	if (l.head == NULL) l.tail = NULL;
	delete p;
}

void pop(List &l, char ma[8]) { // Xoa sinh vien co ma X
	Node *p = l.head;
	Node *q = NULL;
	while (p != NULL) {
		if (strcmp(p->data.ma, ma) == 0) {
			break;
		}
		q = p;
		p = p->next;
	}
	if (p == NULL) {
		printf("Khong tim thay sinh vien co ma can xoa!\n");
		return;
	}
	else if (q != NULL) { 
		if (p == l.tail) l.tail = q;
		q->next = p->next;
		delete p;
	}
	else { // p la phan tu dau xau
		l.head = p->next;
		if (l.head == NULL) l.tail = NULL;// ds co 1 phan tu
	}
}

void removeList(List &l) { //Xoa toan bo danh sach
	Node *p;
	while (l.head != NULL) {
		p = l.head;
		l.head = p->next;
		delete p;
	}
	l.tail = NULL;
}


void remove(List &l, char dc[100]) { //Xoa sinh vien co dia chi X trong danh sach
	Node *p = l.head;
	Node *q = NULL;
	while (p != NULL) {
		if (strcmp(p->data.dc, dc) == 0) {
			if (q == NULL) { // Neu la node dau danh sach
				l.head = p->next;
				delete p;
				p = l.head;
			}
			else if (q->next == l.tail) { // Neu la node cuoi danh sach
				q->next = NULL;
				delete p;
				l.tail = q;
			}
			else { // Neu la node giua danh sach
				q->next = p->next;
				delete p;
				p = q->next;
			}
		}
		else {
			q = p;
			p = p->next;
		}
	}
}

int size(List l) { // Dem so sinh vien co trong danh sach
	int cnt = 0;
	Node *p = l.head;
	while (p != NULL) {
		++count;
		p = p->next;
	}
	return cnt;
}

void reverse(List &l) {
	Node *prev = NULL;
	Node *current = l.head;
	Node *pnext = NULL;
	while (p != NULL) {
		pnext = current->next;
		current->next = prev;
		
		prev = current;
		current = next;
	}
	l.head = prev;
}
