#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PhatSinhMangTang(int a[], int n);
int BinarySearch(int a[], int l, int r, int x);
int binary(int a[], int n, int x);
void XuatMang(int a[], int n);

int main() {
	int n, x;
	printf("Nhap so luong phan tu cua mang: ");
	scanf("%d", &n);
	int a[n];
	PhatSinhMangTang(a, n);
	XuatMang(a, n);
	printf("Nhap khoa can tim: ");
	scanf("%d", &x);
	int kq = BinarySearch(a, 0, n - 1, x);
	if (kq == -1) {
		printf("Khong tim thay\n");
	}
	else {
		printf("Tim thay tai vi tri %d", kq);
	}
	
	return 0;
}

void PhatSinhMangTang(int a[], int n) {
	srand(time(NULL));
	a[0] = rand() % 50;
	for (int i = 1; i < n; i++) {
		a[i] = rand() % 50 + a[i - 1];
	}
}

void XuatMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int BinarySearch(int a[], int l, int r, int x) {
	if (l > r) return -1;
	int m = (l + r) / 2;
	if (a[m] == x) {
		return m;
	} 
	else if (a[m] > x) {
		return BinarySearch(a, l, m - 1, x);
	}
	else {
		return BinarySearch(a, m + 1, r, x);
	}
}

int binary(int a[], int n, int x) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = (l + r) /2;
		if (a[m] == x) {
			return m;
		}
		else if (a[m] > x) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return -1;
}
