#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linear(int a[], int n, int x);
int binary(int a[], int n, int x);
void PhatSinhMang(int a[], int n);
void XuatMang(int a[], int n);

int main() {
	int n = 100, x;
	int a[n];
	PhatSinhMang(a, n);
	XuatMang(a, n);
	printf("\nNhap khoa can tim: ");
	scanf("%d", &x);
	
	//tim kiem tuyen tinh
	clock_t start = clock();
	int kq = linear(a, n, x);
	clock_t end = clock();
	double t = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Thoi gian cua tim kiem tuyen tinh la: %lfs\n", t);
	
	//tim kiem nhi phan
//	start = clock();
//	binary(a, n, x);
//	end = clock();
//	t = end - start;
//	printf("Thoi gian cua tim kiem tuyen tinh la: %lf\n", t);
	return 0;
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

int linear(int a[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) 
			return i;
	}
	return -1;
}

void PhatSinhMang(int a[], int n) {
	srand(time(NULL));
	a[0] = rand() % 50;
	for (int i = 1; i < n; i++) {
		a[i] = a[i - 1] + rand() % 50;
	}
}

void XuatMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

