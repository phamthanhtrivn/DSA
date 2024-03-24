#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MAX 50

typedef struct{
	char id[10], name[100], gt[4], dc[100];
	float dtb;  	
}SV;

SV a[MAX];
int n;
float max = 0;
int size = sizeof(SV);
char *filename = "D:\\HK1(2023-2024)\\CauTrucDuLieuVaGiaiThuat\\ThucHanh\\Week2\\SINHVIEN.bin";

void menu();
SV nhap1SV();
void nhapNsv(SV a[], int n);
void xuat1SV(SV a);
void xuatNsv(SV a[], int n);
int timkiem(SV a[], int n, char ms[]);
void timSV(SV a[], int n, char ms[]);
void swap(SV &a, SV &b);
void sxDTB(SV a[], int n);
void sxHoTen(SV a[], int n);
void suachua(char *filename);
void xoa(char *filename, int &n);
void MAX_DTB(char *filename, SV a[], int n);
void ghiFILE(char *filename);
void docFILE(char *filename, SV a[], int &n);

//22687551
//Pham Thanh Tri
//Nam
//Ben Tre
//7.8
//22687741
//Tran Thi Bao Anh
//Nu
//Ha Noi
//8.9
//22956431
//Le Viet Dung
//Nam
//Da Nang
//5.4

int main() {
	while (1) {
		menu();
		printf("Chon: ");
		int chon; scanf("%d", &chon);
		switch (chon) {
			case 1:
				printf("So luong sinh vien can nhap: ");
				scanf("%d", &n);
				fflush(stdin);
				ghiFILE(filename);
				break;
			case 2:
				docFILE(filename, a, n);
				break;
			case 3:
				fflush(stdin);
				printf("MSSV can tim: ");
				char ms[10]; gets(ms);
				timSV(a, n, ms);
				break;
			case 4:
				sxDTB(a, n);
				break;
			case 5:
				sxHoTen(a, n);
				break;
			case 6:
				suachua(filename);
				break;
			case 7:
				fflush(stdin);
				xoa(filename, n);
				break;
			case 8:
				MAX_DTB(filename, a, n);
				break;	
			case 0: return 1;
			default:
				printf("Lua chon khong hop le!!\n");
				break;	
		}
	}
}

void menu() {
	printf("---------------------Menu----------------------------\n");
	printf("1. Tao danh sach sinh vien vao file\n");
	printf("2. Hien thi danh sach sinh vien tu file\n");
	printf("3. Xuat thong tin sinh vien co ma so x trong file\n");
	printf("4. Sap xep danh sach sinh vien tang dan theo diem trung binh trong file\n");
	printf("5. Sap xep danh sach sinh vien tang dan theo ho va ten trong file\n");
	printf("6. Sua thong tin cua 1 sinh vien trong file\n");
	printf("7. Xoa sinh vien theo ma trong file\n");
	printf("8. Xuat ra cac sinh vien co ma so cao nhat trong file\n");
	printf("0. Thoat\n");
	printf("-----------------------------------------------------\n");
}

SV nhap1SV() {
	SV a; fflush(stdin);
	printf("MSSV: ");
	gets(a.id);
	printf("Ho Ten: ");
	gets(a.name);
	printf("Gioi Tinh(Nam/Nu): ");
	gets(a.gt);
	printf("Dia Chi: ");
	gets(a.dc);
	printf("Diem Trung Binh: ");
	scanf("%f", &a.dtb);
	max = fmax(max, a.dtb);
	return a;
}

void nhapNsv(SV a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = nhap1SV();
	}
}

void xuat1SV(SV a) {
	printf("%-20s %-20s %-20s %-20s %-20.1f\n", a.id, a.name, a.gt, a.dc, a.dtb);
}

void xuatNsv(SV a[], int n) {
	for (int i = 0; i < n; i++) {
		xuat1SV(a[i]);
	}
}

int timkiem(SV a[], int n, char ms[]) {
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].id, ms) == 0) {
			return i;
		}
	}
	return -1;
}

void timSV(SV a[], int n, char ms[]) {
	int kq = timkiem(a, n, ms);
	if (kq == -1) {
		printf("Khong tim thay!\n"); return;
	}
	else {
		xuat1SV(a[kq]);
	}
} 

void swap(SV &a, SV &b) {
	SV tmp = a;
	a = b;
	b = tmp;
}

void sxDTB(SV a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[min].dtb > a[j].dtb) {
				min = j;
			}
		}
		if (min != i) {
			swap(a[min], a[i]);
		}
	}
	FILE *f = fopen(filename, "wb");
	for (int i = 0; i < n; i++) {
		fwrite(&a[i], sizeof(SV), 1, f);
	}
	fclose(f);
}

void sxHoTen(SV a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(a[i].name, a[j].name) > 0) {
				swap(a[i], a[j]);
			}
		}
	}
	FILE *f = fopen(filename, "wb");
	for (int i = 0; i < n; i++) {
		fwrite(&a[i], sizeof(SV), 1, f);
	}
	fclose(f);
}


void xoa(char *filename, int &n) {
	char ms[10];
	FILE *f = fopen(filename, "rb+");
	if (!f) {
		printf("Khong the mo tep!\n");
		exit(1);
	}
	int i = 0, check = 0;
	SV tmp;
	fflush(stdin);
	printf("Nhap MSSV can xoa: ");
	gets(ms);
	while (fread(&tmp, sizeof(SV), 1, f) > 0) {
		if (strcmp(tmp.id, ms) == 0) {
			check = 1; break;
		}
		i++;
	}
//	if (check) {
//		for (int j = i; j < n - 1; j++) {
//			//di chuyen den sau vi tri can xoa
//			fseek(f, -(j + 1) * sizeof(SV), SEEK_SET);
//			//doc
//			fread(&tmp, sizeof(SV), 1, f);
//			//di chuyen len vi tri can xoa
//			fseek(f, j * sizeof(SV), SEEK_SET);
//			//ghi de
//			fwrite(&tmp, sizeof(SV), 1, f);
//		}
//		n--;
//	}
	if (check) {
    	// di chuyen den phan tu cuoi cung
    	fseek(f, -sizeof(SV), SEEK_END);
    	// doc vi tri cuoi cung
    	fread(&tmp, sizeof(SV), 1, f);
    	// di chuyen len vi tri can xoa
    	fseek(f, i * sizeof(SV), SEEK_SET);
    	// ghi de len vi tri can xoa
    	fwrite(&tmp, sizeof(SV), 1, f);  
      n--;
    }
	fclose(f);
}

void suachua(char *filename) {
	SV x;
	char ms[10];
	int i = 0;
	FILE *f = fopen(filename, "rb+");
	if (!f) {
		printf("Khong the mo tep!\n");
		exit(1);
	}
	fflush(stdin);
	printf("Nhap MSSV can sua chua: ");
	gets(ms);
	while (fread(&x, sizeof(SV), 1, f) > 0) {
		if (strcmp(x.id, ms) == 0) {
			fseek(f, i*sizeof(SV), SEEK_SET);
			SV fixInfor;
			printf("Nhap MSSV moi: ");
			gets(fixInfor.id);
			if (strlen(fixInfor.id) == 0) {
				strcpy(fixInfor.id, x.id);
			} 
			printf("Nhap ho ten moi: ");
			gets(fixInfor.name);
			if (strlen(fixInfor.name) == 0) {
				strcpy(fixInfor.name, x.name);
			} 
			printf("Nhap gioi tinh moi: ");
			gets(fixInfor.gt);
			if (strlen(fixInfor.gt) == 0) {
				strcpy(fixInfor.gt, x.gt);
			} 
			printf("Nhap dia chi moi: ");
			gets(fixInfor.dc);
			if (strlen(fixInfor.dc) == 0) {
				strcpy(fixInfor.dc, x.dc);
			} 
			printf("Nhap diem trung binh moi: ");
			scanf("%f", &fixInfor.dtb);
			if (fixInfor.dtb == 0) {
				fixInfor.dtb = x.dtb;
			} 
			fwrite(&fixInfor, sizeof(SV), 1, f);
			break;
		}
		i++;
	}
	fclose(f);
}


void MAX_DTB(char *filename, SV a[], int n) {
	FILE *f = fopen(filename, "rb");
	if (!f) {
		printf("Khong the mo tep!\n");
		exit(1);
	}
	int i = 0;
	printf("-----Danh sach cac sinh vien co DTB cao nhat-----\n");
	while (fread(&a[i], sizeof(SV), 1, f) > 0) {
		if (a[i].dtb == max) {
			xuat1SV(a[i]);
		}
		i++;
	}
	fclose(f);
}

void ghiFILE(char *filename) {
	FILE *f = fopen(filename, "wb");
	if (!f) {
		printf("Khong the mo tep!\n");
		exit(1);
	}
	nhapNsv(a, n);
	for (int i = 0; i < n; i++) {
		fwrite(&a[i], sizeof(SV), 1, f);
	}
	fclose(f);
}

void docFILE(char *filename, SV a[], int &n) {
	FILE *f = fopen(filename, "rb");
	if (!f) {
		printf("Khong the mo tep!\n");
		exit(1);
	}
	int i = 0;
	while (fread(&a[i], sizeof(SV), 1, f) > 0) {
		if (i < n) {
			xuat1SV(a[i]);
			i++;
		} 
	}
	n = i;
	fclose(f);
}

