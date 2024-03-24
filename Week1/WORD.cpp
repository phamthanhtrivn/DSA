#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char Name[256];
	char Meaning[512];
}WORD;

void iMenu();
WORD nhap1tu();
void nhapNtu(WORD a[], int n);
void xuat1tu(WORD a);
void xuatNtu(WORD a[], int n);
void swap(char a[], char b[]);
void sorting(WORD a[], int n);
int timkiem(WORD a[], int n, char keyword[]) ;
void timtu(WORD a[], int n, char keyword[]);
void update_meaning(WORD a[], int n);
int trungtu(WORD a[], int n, char word[]);
void them1tu(WORD a[], int &n);
void xoa1tu(WORD a[], int &n);
void GhiVaoFile(WORD a[], int n);
void DocFile(WORD a[], int n);

int main() {
	int n, chon;
	char keyword[256], word[256];
	printf("Nhap so luong tu can them vao: ");
	scanf("%d", &n); fflush(stdin);
	WORD a[n];
	nhapNtu(a, n);
	do {
		iMenu();
		printf("Chon: ");
		scanf("%d", &chon);
		switch(chon) {
			case 1:
				fflush(stdin);
				xuatNtu(a, n);
				break;
			case 2:
				fflush(stdin);
				GhiVaoFile(a, n);
				break;
			case 3:	
				fflush(stdin);
				DocFile(a, n);
				break;
			case 4:	
				sorting(a, n);
				break;
			case 5:
				fflush(stdin);
				printf("Nhap tu can tim kiem: ");
				gets(keyword);	
				timtu(a, n, keyword);
				break;
			case 6:	
				fflush(stdin);
				update_meaning(a, n);
				break;
			case 7:	
				fflush(stdin);
				xoa1tu(a, n);
				break;
			case 8:	
				fflush(stdin);
				them1tu(a, n);
				break;
			case 0:
				return 0;		
			default:
				printf("Lc khong hop le. Vui long chon lai!\n");
				break;
		}
	} while (1);
	return 0;
}

void iMenu() {
	printf("\n====================================\n");
	printf("1. Xuat danh sach tu dien\n");
	printf("2. Ghi noi dung vao File\n");
	printf("3. Doc noi dung tu File\n");
	printf("4. Sap xep tu dien theo tang dan bang chu cai TA\n");
	printf("5. Tim kiem nghia cua tu\n");
	printf("6. Cap nhat nghia cua tu\n"); // lay tu file va ghi lai vao file
	printf("7. Xoa 1 tu trong file\n");
	printf("8. Them 1 tu vao file\n");
	printf("0. Thoat\n");
	printf("\n====================================\n");
}

WORD nhap1tu() {
	WORD a;
	printf("Nhap tu: ");
	gets(a.Name);
	printf("Nhap nghia cua tu: ");
	gets(a.Meaning);
	return a;	
}

void nhapNtu(WORD a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = nhap1tu();
	}
}

void xuat1tu(WORD a) {
	printf("%s: %s\n", a.Name, a.Meaning);
}

void xuatNtu(WORD a[], int n) {
	for (int i = 0; i < n; i++) {
		xuat1tu(a[i]);
	}
}

void swap(WORD &a, WORD &b) {
	WORD tmp = a;
	a = b;
	b = tmp;
}

void sorting(WORD a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (strcmp(a[i].Name, a[j].Name) > 0) {
				min = j;
			}
		}
		if (min != i) {
			swap(a[i], a[min]);
		}
	}
	GhiVaoFile(a, n);
}

int timkiem(WORD a[], int n, char keyword[]) {
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].Name, keyword) == 0) {
			return i;
		}
	}
	return -1;
}

void timtu(WORD a[], int n, char keyword[]) {
	int kq = timkiem(a, n, keyword);
	if (kq == -1) {
		printf("Khong tim thay!\n"); return;
	}
	else {
		xuat1tu(a[kq]);
	}
}

void update_meaning(WORD a[], int n) {
	char word[256];
	printf("Nhap tu can sua nghia: ");
	gets(word);
	int kq = timkiem(a, n, word);
	if (kq == -1) {
		printf("Khong tim thay!\n"); return;
	}
	else {
		char meaning[512];
		printf("Nhap nghia can update: ");
		gets(a[kq].Meaning);
		GhiVaoFile(a, n);
	}
}

void xoa1tu(WORD a[], int &n) {
	char word[256]; 
	printf("Nhap tu can xoa: ");
	gets(word);
	int kq = timkiem(a, n, word);
	if (kq == -1) {
		printf("Khong tim thay!\n"); return;
	}
	else {
		for (int i = kq; i < n - 1; i++) {
			strcpy(a[i].Name, a[i + 1].Name);
			strcpy(a[i].Meaning, a[i + 1].Meaning);
		}
		--n;
		GhiVaoFile(a, n);
	}
}

int trungtu(WORD a[], int n, char word[]) {
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].Name, word) == 0) 
			return 1;
	}
	return 0;
}

void them1tu(WORD a[], int &n) {
	char word[256];
	printf("Nhap tu can them: ");
	gets(word);
	while (trungtu(a, n, word)) {
		printf("Tu da co trong danh sach. Vui long nhap lai!\n");
		printf("Nhap tu can them: ");
		gets(word);
	}	
	strcpy(a[n].Name, word);
	printf("Nhap nghia cua tu can them: ");
	gets(a[n].Meaning);
	FILE *f = fopen("word.txt", "a");
	fprintf(f, "%s : %s", a[n].Name, a[n].Meaning);
	fclose(f);
	++n;
	printf("Da them vao FILE\n");
}



void GhiVaoFile(WORD a[], int n) {
	FILE *f = fopen("word.txt", "w");
	if (!f) 
		return;
	for (int i = 0; i < n; i++) {
		fprintf(f, "%s: %s\n", a[i].Name, a[i].Meaning);
	}
	fclose(f);
}

void DocFile(WORD a[], int n) {
	char line[1000];
	FILE *f = fopen("word.txt", "r");
	if (!f)
		return;
	while (fgets(line, 1000, f) != NULL) {
		printf("%s", line);
	}
}


