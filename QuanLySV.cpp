#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000

struct SV {
	char maSV[10], hoTen[30];
	float TK, GK, CK, TH, TB;
};

typedef struct SV SV;

void nhap1SV(SV &sv); 
int trungMa(SV a[], int n, char ma[10], int i);
void nhapnSV(SV a[], int n);
void xuat1SV(SV a);
void xuatnSV(SV a[], int n);
void xuat_SV_DTB_Nhohon4(SV a[], int n);
int timMaSV(SV a[], int n, char ma[]);
void timkiemSV(SV a[], int n);
void sapxepGiamtheoDTB(SV a[], int n);
void sapxepTangtheohoten(SV a[], int n);
void xuatdsSV(SV a[], int n);
void xuatdsDTBMax(SV a[], int n);
void them1SV(SV a[], int &n);
void timvaxoaSVtheoma(SV a[], int &n);
void GhiFileNhiPhan(SV a[], int n);
void DocFileNhiPhan(SV a[], int &n);
void iMenu();

int main() {
	SV a[MAX], b[MAX];
	int n, chon, n2;
	char traloi;
	do {
		iMenu();
		printf("Chon: ");
		scanf("%d", &chon);
		switch (chon) {
			case 1:
				printf("\nNhap so luong sinh vien: ");
				scanf("%d", &n);
				nhapnSV(a, n);
				break;
			case 2:
				printf("\n\tDanh sach sinh vien sau khi nhap:\n");
				xuatnSV(a, n);
				break;
			case 3:
				GhiFileNhiPhan(a, n);
				break;
			case 4:
				xuat_SV_DTB_Nhohon4(a, n);
				break;
			case 5:
				timkiemSV(a, n);
				break;
			case 6:
				sapxepGiamtheoDTB(a, n);
				break;
			case 7:
				sapxepTangtheohoten(a, n);
				break;
			case 8:
				printf("\n\tDanh sach diem SV lop KTLT\n");
				xuatdsSV(a, n);
				break;
			case 9:
				printf("\n\tDanh sach diem trung binh cao nhat\n");
				xuatdsDTBMax(a, n);
				break;
			case 10:
				printf("\n\tThem 1 sinh vien vao danh sach\n");
				them1SV(a, n);
				break;
			case 11:
				timvaxoaSVtheoma(a, n);
				break;
			case 12:
				DocFileNhiPhan(b, n2);
				printf("Noi dung duoc doc tu File!\n");
				xuatnSV(b, n2);
				break;
			case 0:
				return 0;
			default:
				printf("\n\tLua chon ko hop le. Vui long nhap lai!\n");
				break;
		}
	} while (1);
	return 0;
}

void nhap1SV(SV &sv) {
	printf("\t\tNhap Ho ten SV: ");
	fflush(stdin);
	gets(sv.hoTen);
	printf("\t\tDiem TK: ");
	scanf("%f", &sv.TK);
	printf("\t\tDiem GK: ");
	scanf("%f", &sv.GK);
	printf("\t\tDiem CK: ");
	scanf("%f", &sv.CK);
	printf("\t\tDiem TH: ");
	scanf("%f", &sv.TH);
	sv.TB = ((((2*sv.TK + 3*sv.GK + 5*sv.CK)/10)*2) + sv.TH)/3;
}

int trungMa(SV a[], int n, char ma[10], int i) {
	for (int j = 0; j < i; j++) {
		if (strcmp(a[j].maSV, ma) == 0) 
			return 1;
	}
	return 0;
}

void nhapnSV(SV a[], int n) {
	char ma[10];
	for (int i = 0; i < n; i++) {
		printf("\t\tNhap ma SV: ");
		fflush(stdin);
		gets(ma);
		while (trungMa(a, n, ma, i)) {
			printf("\t\tTrung Ma. Nhap lai ma SV: ");
			gets(ma);
		}
		strcpy(a[i].maSV, ma);
		nhap1SV(a[i]);
	}
}

void xuat_SV_DTB_Nhohon4(SV a[], int n) {
	int oke = 0, stt = 0;
	for (int i = 0 ; i < n; i++) {
		if (a[i].TB < 4.0) {
			if (oke = 0) {
				printf("\n\tDanh sach sinh vien co diem trung binh nho hon 4:\n");
				printf("\t%-6s %-20s %-10s %-15s\n", "STT", "HO TEN", "MA SV", "DTB");
				oke = 1;
			}
			printf("\t%-6d", ++stt);
		}
	}
	if (oke == 0) {
		printf("\tKhong co sinh vien co DTB < 4.0!\n");
	}
}

int timMaSV(SV a[], int n, char ma[]) {
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].maSV, ma) == 0)
			return i;
	}
	return -1;
}

void timkiemSV(SV a[], int n) {
	char ma[10];
	int stt;
	printf("Nhap ma SV can tim: ");
	fflush(stdin);
	gets(ma);
	stt = timMaSV(a, n, ma);
	if (stt == -1) {
		printf("Khong tim thay sinh vien co ma %s\n", ma);
	} else {
		printf("\t%-20s : %-20s\n", "HO TEN", a[stt].hoTen);
		printf("\t%-20s : %-20s\n", "MA SV", a[stt].maSV);
		printf("\t%-20s : %-20.1f\n", "Diem thuong ky", a[stt].TK);
		printf("\t%-20s : %-20.1f\n", "Diem giua ky", a[stt].GK);
		printf("\t%-20s : %-20.1f\n", "Diem cuoi ky", a[stt].CK);
		printf("\t%-20s : %-20.1f\n", "Diem trung binh", a[stt].TB);
	}
}

void sapxepGiamtheoDTB(SV a[], int n) {
	SV tmp;
	for (int i = 0 ; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i].TB < a[j].TB) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	xuatnSV(a, n);
}

void sapxepTangtheohoten(SV a[], int n) {
	SV tmp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(a[i].hoTen, a[j].hoTen) == 1) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	xuatnSV(a,n);
}

void xuat1SV(SV a) {
	printf("\t%-20s %-10s %-15.1f\n", a.hoTen, a.maSV, a.TB);
}

void xuatnSV(SV a[], int n) {
	int stt = 0;
	printf("\t%-6s %-20s %-10s %-15s\n", "STT", "HO TEN", "MA SV", "DTB");
	for (int i = 0; i < n; i++) {
		printf("\t%-6d", ++stt);
		xuat1SV(a[i]);
	}
}

void xuatdsSV(SV a[], int n) {
	int stt = 0;
	printf("%-6s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n", "STT", "HO TEN", "MA SV", "TK", "GK", "CK", " DIEM TB", "GHI CHU");
	for (int i = 0; i < n; i++) {
		printf("%-6d", ++stt);
		printf(" %-20s %-10s %-10.1f %-10.1f %-10.1f %-10.1f ", a[i].hoTen, a[i].maSV, a[i].TK, a[i].GK, a[i].CK, a[i].TB);
		if (a[i].TB < 4.0) {
			printf("%-10s\n", "Hoa lai");
		} else {
			printf("\n");
		}
	}
}

void xuatdsDTBMax(SV a[], int n) {
	float max = a[0].TB;
	int i, td = 0;
	for (int i = 1; i < n; i++) {
		if (a[i].TB > max) 
			max = a[i].TB;
	}
	for (int i = 0; i < n; i++) {
		if (a[i].TB == max) {
			if (td == 0) {
				printf("\t%-20s %-10s %-15s\n", "HO TEN", "MA SV", "DIEM TB");
				td = 1;
			}
			xuat1SV(a[i]);
		}
	}
}

void them1SV(SV a[], int &n) {
	char ma[10];
	int i;
	printf("\n\tNhap ma SV: ");
	fflush(stdin);
	gets(ma);
	while (trungMa(a, n, ma, i)) {
		printf("\tTrung Ma!\n\tNhap lai Ma SV: ");
		gets(ma);
	}
	strcpy(a[n].maSV, ma);
	nhap1SV(a[n]);
	n++;
	printf("Da them sinh vien vao danh sach\n");
}

void timvaxoaSVtheoma(SV a[], int &n) {
	int stt;
	char ma[10];
	printf("Nhap ma SV can xoa: ");
	fflush(stdin);
	gets(ma);
	stt = timMaSV(a, n, ma);
	if (stt == -1) {
		printf("Khong tim thay sinh vien co ma %s\n", ma);
	} else {
		for (int i = stt; i < n - 1; i++) {
			a[i] = a[i+1];
		}
		n--;
		printf("Da xoa sinh vien ra khoi danh sach!\n");
	}
}

void GhiFileNhiPhan(SV a[], int n) {
	FILE *f;
	f = fopen("OutPutQLSV.dat", "wb");
	if (f == NULL) {
		printf("File Erorr!\n");
	} else {
		fwrite(a, sizeof(SV), n, f);
	}
	fclose(f);
	printf("\tDa ghi mang vao File!\n");
}

void DocFileNhiPhan(SV a[], int &n) {
	FILE *f;
	f = fopen("OutPutQLSV.dat", "rb");
	fseek(f, 0, SEEK_END);
	n = ftell(f) / sizeof(SV);
	fseek(f, 0, SEEK_SET);
	fread(a, sizeof(SV), n, f);
	fclose(f);
}

void iMenu() {
	printf("\n====================================\n");
	printf("	1. Nhap danh sach sinh vien\n");
	printf("	2. Xuat danh sach sinh vien\n");
	printf("	3. Ghi noi dung vao File\n");
	printf("	4. Danh sach sinh vien co DTB < 4.0\n");
	printf("	5. Tim kiem sinh vien theo ma\n");
	printf("	6. Sap xep giam dan theo DTB\n");
	printf("	7. Sap xep tang dan theo Ho Ten\n");
	printf("	8. Danh sach sinh vien mon KTLT\n");
	printf("	9. Danh sach sinh vien co DTB cao nhat\n");
	printf("	10. Them 1 sinh vien vao danh sach\n");
	printf("	11. Tim va xoa sinh vien theo ma sinh vien\n");
	printf("	12. Doc noi dung tu File va hien thi\n");
	printf("	0. Thoat\n");
	printf("\n====================================\n");
}




