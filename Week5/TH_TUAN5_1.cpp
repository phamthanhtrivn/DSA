#include <stdio.h>

struct Sach{
	char tenSach[50];
	char tacGia[50];
	char NXB[50];
	int namXB;
};

struct Node {
	struct Sach data;
	struct Node *next;
};

struct List{
	struct Node *head;
	struct Node *tail;
};

char *filename = "T:\\DSdcGhi.txt";
char *filename2 = "T:\\ThongKe.txt";
char cactg[50][50];
int n = 0;

void Init(List &l);
Node *getNode(Sach x);
int nhapSach(Sach &x);
void pushBack(List &l, Sach x);
void nhapDSSach(List &l);
void GhiDSVaoFile(List l, char *filename);
void nhapDSSach(List &l, char *filename);
int SoLuongSach(List l, char ten[50]);
void XuatSach(Sach x);
void phatHanh(List l, int nam, char nhaXB[50]);
void RemoveFirst(List &l);
void RemoveLast(List &l);
void RemoveAfter(List &l);
void ThongKe(List l, char *filename);
void DocThongKeTrenTep(char *filename);

int main() {
	
	return 0;
}

void Init(List &l) {
	l.head = l.tail = NULL;
}

Node *getNode(Sach x) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		return NULL;
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

int nhapSach(Sach &x) {
	fflush(stdin);
	printf("Ten sach: ");
	gets(x.tenSach);
	if (strcmp(x.tacGia, "0") == 0) {
		return 0;
	}
	print("Ten tac gia: ");
	gets(x.tacGia);
	trungtg(x.tacGia, n);
	printf("Nha xuat ban: ");
	gets(x.NXB);
	printf("Nam xuat ban: ");
	scanf("%d", &x.namXB);
	fflush(stdin);
	return 1;
}

void trungtg(char tg[50], int &n) {
	List l;
	Node *p = l.head;
	int i = 0;
	while (p != NULL) {
		if (!strcmp(p->data.tacGia, tg) == 0) {
			strcpy(cactg[i++], tg);
		}
		p = p->next;
	}
	n = i;
}

void pushBack(List &l, Sach x) {
	Node *newNode = getNode(x);
	if (newNode == NULL) {
		printf("Khong the them vao cuoi danh sach!");
		return;
	}
	if (l.head == NULL) {
		l.head = l.tail = NULL;
	}
	else {
		l.tail->next = newNode;
		l.tail = newNode;
	}
}


void GhiDSVaoFile(List l, char *filename) {
	FILE *f = fopen(filename, "w");
	if (!f) {
		printf("Khong the tao tep!\n");
		exit(1); return;
	}
	Node *p = l.head;
	while (p != NULL) {
		fprintf(f, "Ten Sach: %s\n", p->data.tenSach);
		fprintf(f, "Ten tac Gia: %s\n", p->data.tacGia)
		fprintf(f, "Nha Xuat Ban: %s\n", p->data.NXB)
		fprintf(f, "Nam Xuat Ban: %d\n", p->data.namXB);
		p = p->next;
	}
	fclose(f);
}

void nhapDSSach(List &l, char *filename) {
	Sach x;
	printf("Bat dau nhap sach.Nhap ten sach = 0 de dung!\n");
	int check = nhapSach(x);
	while (check) {
		pushBack(l, x);
		check = nhapSach(x);
	}
	GhiDSVaoFile(l, filename);
	printf("Ket thuc nhap danh sach! Da Ghi DS vao FILE\n");
}

int SoLuongSach(List l, char tg[50]) {
	int cnt = 0;
	Node *p = l.head;
	while (p != NULL) {
		if (strcmp(p->data.tacGia, tg) == 0) {
			++cnt;
		}
		p = p->next;
	}
	return cnt;
}

void XuatSach(Sach x) {
	printf("Ten Sach: %s\n", x.tenSach);
	printf("Ten Tac Gia: %s\n", x.tacGia);
	printf("Nha Xuat Ban: %s\n", x.NXB);
	printf("Nam Xuat Ban: %s\n", x.namXB);
}

void phatHanh(List l, int nam, char nhaXB[50]) {
	Node *p = l.head;
	while (p != NULL) {
		if (p->data.namXB == nam && strcmp(p->data.NXB, nhaXB) == 0) {
			XuatSach(p->data);
		}
		p = p->next;
	}
}

void RemoveFirst(List &l) {
	Node *p = l.head;
	l.head = p->next;
	if (l.head == NULL) l.tail = NULL;
	free(p);
}

//void RemoveLast(List &l) { // 1->2->3->4->5->NULL
//	Node *p = l.head;
//	while (p->next->next != NULL) {
//		p = p->next;
//	}
//	p->next = NULL;
//	l.tail = p;
//}
//
//void RemoveAfter(List &l) {
//	Node *p = l.head;
//	Node *q = NULL;
//	while (p != l.tail)
//}
//
//void XoaSach(List &l, char tg[50], char *filename) {
//	Node *p = l.head;
//	while (p != NULL) {
//		if (strcmp(p->data.tacGia, tg) == 0) {
//			if (p == l.head) {
//				RemoveFirst(l);
//			}
//			else if (p == l.tail) {
//				RemoveLast(l);
//			}
//			else {
//				
//			}
//		}
//		p = p->next;
//	}
//	GhiDSVaoFile(l, filename);
//}


void ThongKe(List l, char *filename) {
	FILE *f = fopen(filename, "w");
	if (!f) {
		printf("Khong the mo tep!\n");
		exit(1); return;
	}
	Node *p = l.head;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		while (p != NULL) {
			if (strcm(cactg[i], p->data.tacGia) == 0) {
				cnt++;
			}
			p = p->next;
		}
		fprintf(f, "Tac gia: %s co %d cuon sach\n", cactg[i], cnt);
		cnt = 0;
	}
	fclose(f);
}

void DocThongKeTrenTep(char *filename) {
	FILE *f = fopen(filename, "r");
	char s[1000]
	while (fgets(s, 1000, f) != NULL) {
		printf("%s", s);
	}
	fclose(f);
}

void DocFileDuaVaoDS(List &l, char *filename) {
	FILE *f = fopen(filename, "r");
	if (!f) {
		printf("Khong the mo tep!\n");
		exit(1); return;
	}
	char s[1000];
	char *token;
	while (fgets(s, 1000, f) != NULL) {
		str
	}
	fclose(f);
}






