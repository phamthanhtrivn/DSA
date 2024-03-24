#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LinearSearch(int a[], int n, int x);
int LinearSearch_CaiTien(int a[], int n, int x);
int linear(int a[], int n, int x);
void XuatMang(int a[], int n);

int main() {
	int n, x;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d", &n);
	int a[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand();
	}
	XuatMang(a, n);
	printf("Nhap khoa can tim: ");
	scanf("%d", &x);
	int kq = LinearSearch(a, n, x);
	if (kq == -1) {
		printf("Khong tim thay\n");
	} 
	else {
		printf("Tim thay tai vi tri %d\n", kq);
	}
	return 0;
}

int LinearSearch(int a[], int n, int x) {
	int i = 0;
	while (i < n && a[i] != x) {
		i++;
	}
	if (i < n) return i;
	return -1;
}

int LinearSearch_CaiTien(int a[], int n, int x) {
	int i = 0;
	a[n] = x;
	while (a[i] != x) {
		i++;
	}
	if (i < n) return i;
	return -1;
}

int linear(int a[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) 
			return i;
	}
	return -1;
}

void XuatMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
