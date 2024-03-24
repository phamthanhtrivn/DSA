#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct item {
	char masv[20];
	char name[20];
	double diem;
};

struct Node {
	item key;
	Node *left, *right;
};

typedef Node *Tree;

//int addItemId(Node *p, Tree &t); // Them node sinh vien 
//int addItemName(Node *p, Tree &t);	
//int addItemGpa(Node *p, Tree &t);
//int insertNode(Tree &t, item x); // Them Node vao cay
Node *makeNode(item x); // Tao Node sinh vien
Node *insert(Tree &t, item x);
void nhapSV(Tree &t); // Nhap va them node sinh vien vao cay
void xuat1SV(item x);
void duyetLNR(Tree t);
int leafNode(Tree t); // Diem so node la
int height(Tree t); // Chieu cao cua cay
Node *searchNode(Tree t, char masv[20]);
void searchStandFor(Tree &x, Tree &y); // tim node trai nhat cua cay con ben phai
int delNode(Tree &t, char masv[20]);

int main() {
	Tree t = NULL;
	do {
		printf("====================Menu=======================\n");
		printf("0. Thoat\n");
		printf("1. Nhap sinh vien\n");
		printf("2. Xuat sinh vien\n");
		printf("3. So node la cua cay\n");
		printf("4. Chieu cao cua cay\n");
		printf("5. Them 1 sinh vien vao cay\n");
		printf("6. Tim kiem node theo ma sinh vien\n");
		printf("7. Xoa node theo ma sinh vien\n");
		printf("===============================================\n");
		printf("Chon: ");
		int lc; scanf("%d", &lc);
		if (lc == 0) {
			break;
		}
		else if (lc == 1) {
			printf("Nhap so luong sinh vien muon them vao: ");
			int n; scanf("%d", &n);
			for (int i = 0; i < n; i++) {
				printf("--Sinh vien thu %d--\n", i + 1);
				fflush(stdin);
				nhapSV(t);
			}
		}
		else if (lc == 2) {
			printf("\n\t--Danh sach sinh vien--\n");
			printf("|%-10s | %-20s | %-5s|\n", "Ma SV", "Ho Ten", "Gpa");
			printf("-----------------------------------------\n");
			duyetLNR(t);
			printf("\n");
		}
		else if (lc == 3) {
			printf("\n--So node la cua cay la: %d--\n\n", leafNode(t));
		}
		else if (lc == 4) {
			printf("\n--Chieu cao cua cay la: %d--\n\n", height(t));
		}
		else if (lc == 5) {
			fflush(stdin);
			nhapSV(t);
		}
		else if (lc == 6) {
			fflush(stdin);
			printf("Nhap ma sinh vien can tim: ");
			char masv[20]; gets(masv);
			Node *x = searchNode(t, masv);
			if (x == NULL) {
				printf("Khong ton tai ma sinh vien can tim!\n");
			}
			else {
				xuat1SV(x->key);
			}
		}
		else if (lc == 7) {
			fflush(stdin);
			printf("Nhap ma sinh vien can xoa: ");
			char masv[20]; gets(masv);
			int check = delNode(t, masv);
			if (check) {
				printf("Xoa thanh cong!\n");
			}
			else {
				printf("Khong ton tai ma sinh vien can xoa!\n");
			}
		}
		else {
			printf("Lua chon khong hop le!\n");
		}
	} while (1);
	return 0;
}

//int addItemId(Node *p, Tree &t) {
//	if (t == NULL) { // Truong hop cay rong
//		t == p;
//		return 0;
//	}
//	else { // Truong hop cay khac rong
//		if (strcmp(p->key.masv, t->key.masv) < 0) // Neu masv be hon node hien tai thi di chuyen sang trai
//			addItemId(p, t->left);
//		else if (strcmp(p->key.masv, t->key.masv) > 0) // Neu masv lon hon node hien tai thi di chuyen sang trai
//			addItemId(p, t->right);
//		else // Neu masv == node hien tai thi khop hop le
//			return 1;
//
//	}
//}
//
//int addItemName(Node *p, Tree &t) {
//	if (t == NULL) { // Truong hop cay rong
//		t == p;
//		return 0;
//	}
//	else { // Truong hop cay khac rong
//		if (strcmp(p->key.masv, t->key.masv) < 0) // Neu tensv be hon node hien tai thi di chuyen sang trai
//			addItemName(p, t->left);
//		else if (strcmp(p->key.masv, t->key.masv) > 0) // Neu tensv lon hon node hien tai thi di chuyen sang trai
//			addItemName(p, t->right);
//		else // Neu tensv == node hien tai thi khop hop le
//			return 1;
//
//	}
//}
//
//int addItemGpa(Node *p, Tree &t) {
//	if (t == NULL) { // Truong hop cay rong
//		t == p;
//		return 0;
//	}
//	else { // Truong hop cay khac rong
//		if (strcmp(p->key.masv, t->key.masv) < 0) // Neu diem be hon node hien tai thi di chuyen sang trai
//			addItemGpa(p, t->left);
//		else if (strcmp(p->key.masv, t->key.masv) > 0) // Neu diem lon hon node hien tai thi di chuyen sang trai
//			addItemGpa(p, t->right);
//		else // Neu diem == node hien tai thi khop hop le
//			return 1;
//	}
//}
//
//int insertNode(Tree &t, item x) {
//	if (t != NULL) {
//		if (strcmp(t->key.masv, x.masv) == 0)
//			return 1;
//		if (strcmp(t->key.masv, x.masv) > 0)
//			return insertNode(t->left, x);
//		return insertNode(t->right, x);
//	}
//	Node *newNode = makeNode(x);
//	return 0;
//}

Node *makeNode(item x) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) 
		return NULL;
	newNode->key = x;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node *insert(Tree &t, item x) {
	if (t == NULL) {
        return makeNode(x);
    }
    
    if (strcmp(t->key.masv, x.masv) > 0) {
        t->left = insert(t->left, x);
    } 
	else if (strcmp(t->key.masv, x.masv) < 0) {
        t->right = insert(t->right, x);
    } 
	else {
        printf("Trung ma sinh vien\n");
    }
    return t;
}

void nhapSV(Tree &t) {
	item x;
	printf("Nhap Ma SV: ");
	gets(x.masv);
	printf("Nhap Ten SV: ");
	gets(x.name);
	printf("Nhap GPA: ");
	scanf("%lf", &x.diem);
	t = insert(t, x);
}

void xuat1SV(item x) {
	printf("|%-10s | %-20s | %-5.2lf\n|", x.masv, x.name, x.diem);
}

void duyetLNR(Tree t) {
	if (t != NULL) {
		duyetLNR(t->left);
		xuat1SV(t->key);
		duyetLNR(t->right);
	} 
}

int leafNode(Tree t) {
	if (t == NULL) 
		return 0;
	else {
		if (t->left == NULL && t->right == NULL)
			return 1 + leafNode(t->left) + leafNode(t->right);
		return leafNode(t->left) + leafNode(t->right);
	}
}

int height(Tree t) {
	if (t == NULL) 
		return -1;
	else 
		return 1 + fmax(height(t->left), height(t->right));
}

Node *searchNode(Tree t, char masv[20]) {
	if (t != NULL) {
		if (strcmp(t->key.masv, masv) == 0)
			return t;
		if (strcmp(t->key.masv, masv) < 0)
			return searchNode(t->right, masv);
		return searchNode(t->left, masv);
	}
	return NULL;
} 

void searchStandFor(Tree &x, Tree &y) { // Node y la node the mang cho node can xoa
	if (y->left != NULL) { // duyet sang ben trai
		searchStandFor(x, y->left);
	}
	else {
		x->key = y->key; // cap nhat key cua node can xoa chinh la key cua node the mang
		x = y; // cho node x (la node se xoa) tro den node the mang ==> ra khoi ham ta se xoa node x
		y = y->right; // cap nhat lai moi lien ket cho node cha cua node the mang(ma ta xoa) voi node con cua node the mang
	}
}

int delNode(Tree &t, char masv[20]) {
	if (t == NULL)
		return 0;
	//B1: Di tim node xoa
	if (strcmp(t->key.masv, masv) > 0)
		return delNode(t->left, masv);
	else if (strcmp(t->key.masv, masv) < 0)
		return delNode(t->right, masv);
	else { //t->key.masv == masv => xoa | xac dinh duoc node xoa
		//B2: Xoa node 
		Node *x = t;
		//TH1: co 1 node con hoac khong co node con
		if (t->left == NULL)
			t = t->right;
		else if (t->right == NULL)
			t = t->left;
		//TH2: co 2 node con 
		else {
			searchStandFor(x, t->right);
		}
		free(x);  
	}
}
