#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n, slHoanVi = 0;
int a[100000];
char *filename = "mang1.txt";

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void interchangesort(int a[], int n) { // doi cho truc tiep
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(&a[i], &a[j]); ++slHoanVi;
			}
		}
	}
}

void selectionSort(int a[], int n) { // chon truc tiep
	for (int i = 0; i < n - 1; i++) {
		int min_pos = i;
		for (int j = i + 1; j < n; j++) {
			if (a[min_pos] > a[j])
				min_pos = j;
		}
		if (min_pos != i) {
			swap(&a[i], &a[min_pos]); ++slHoanVi;
		}
	}
}

void insertionSort(int a[], int n) { // chen truc tiep
	for (int i = 1; i < n; i++) {
		int temp = a[i]; //temp la vi tri dang xet, j la vi tri cua so truoc do
		int j = i - 1;
		while (j >= 0 && a[j] > temp) {
			a[j + 1] = a[j];
			--j; ++slHoanVi;
		}
		a[j + 1] = temp; ++slHoanVi;
	}
}

void bubblesort(int a[], int n) { // noi bot
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]); ++slHoanVi;
			}
		}
	}
}

int partition(int a[], int l, int r) { // quick sort
	int pivot = a[r]; // phan tu ben phai cuoi cung
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (a[j] <= pivot) {
			++i;
			swap(&a[i], &a[j]); ++slHoanVi;
		}
	}
	// dua chot ve giua
	++i; swap(&a[i], &a[r]); ++slHoanVi;
	return i; // vi tri
}
void quickSort(int a[], int l, int r, int &slHoanVi) { // lomuto, O(n^2)
	if (l >= r) return;
	int p = partition(a, l, r);
	quickSort(a, l, p - 1, slHoanVi);
	quickSort(a, p + 1, r, slHoanVi); 
}

void GhiMangVaoFileText(char *filename, int a[], int n) {
	FILE *f = fopen(filename, "w");
	if (!f) {
		printf("Khong the mo tep!\n");
		exit(1);
	}
	for (int i = 0; i < n; i++) {
		fprintf(f, "%d\t", a[i]);
	}
	fclose(f);
}

void DocMangTuFileText(char *filename, int a[], int &n) {
	FILE *f = fopen(filename, "r");
	if (!f) {
		printf("Khong the mo tep!\n");
		exit(1);
	}
	int i = 0;
	while (!feof(f)) {
		fscanf(f, "%d", &a[i]);
		i++;
	}
	n = i;
	fclose(f);
}

void phatSinhMang(int a[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand();
	}
}
void xuatMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
}

void iMenu() {
	printf("=======================Menu=====================\n");
	printf("0. Thoat\n");
	printf("1. Tao Mang\n");
	printf("2. Phat Sinh Mang\n");
	printf("3. Selection\n");
	printf("4. Interchange\n");
	printf("5. BubBle\n");
	printf("6. Insertion\n");
	printf("7. QuickSort\n");
	printf("8. Ghi Mang Vao File TEXT\n");
	printf("9. Doc Mang Tu File TEXT\n");
	printf("10. Xuat Mang\n");
	printf("================================================\n");
}

//Mang1: 
//Selection: 9.10s, slHV = 49987
//Interchange: 15.23s, slHV = 397997033
//BubBle: 9.14s, slHV = 49987
//Insertion: 6.90s, slHV = 623428101
//QuickSort: 0.02s, slHv = 626796771

int main() {
	do {
		iMenu();
		printf("Chon: ");
		int c; scanf("%d", &c);
		if (c == 0) {
			break;
		}
		else if (c == 1) {
			printf("Nhap so luong phan tu cho mang: ");
			scanf("%d", &n);
		}
		else if (c == 2) {
			phatSinhMang(a, n);
		}
		else if (c == 3) {
			clock_t start, end;
			start = clock();
			selectionSort(a, n);
			end = clock();
			printf("Thoi gian chay: %.2f, So lan Hoan Vi: %d\n", ((double)end - start) / 1000, slHoanVi);
		}
		else if (c == 4) {
			clock_t start, end;
			start = clock();
			interchangesort(a, n);
			end = clock();
			printf("Thoi gian chay: %.2f, So lan Hoan Vi: %d\n", ((double)end - start) / 1000, slHoanVi);
		}
		else if (c == 5) {
			clock_t start, end;
			start = clock();
			bubblesort(a, n);
			end = clock();
			printf("Thoi gian chay: %.2f, So lan Hoan Vi: %d\n", ((double)end - start) / 1000, slHoanVi);
		}
		else if (c == 6) {
			clock_t start, end;
			start = clock();
			insertionSort(a, n);
			end = clock();
			printf("Thoi gian chay: %.2f, So lan Hoan Vi: %d\n", ((double)end - start) / 1000, slHoanVi);
		}
		else if (c == 7) {
			clock_t start, end;
			start = clock();
			quickSort(a, 0, n - 1, slHoanVi);
			end = clock();
			printf("Thoi gian chay: %.2f, So lan Hoan Vi: %d\n", ((double)end - start) / 1000, slHoanVi);
		}
		else if (c == 8) {
			GhiMangVaoFileText(filename, a, n);
		}
		else if (c == 9) {
			GhiMangVaoFileText(filename, a, n);
		}
		else if (c == 10) {
			xuatMang(a, n);
		}
		else {
			printf("Lua chon khong hop le!\n");
		}
	} while (1);
	return 0;
}
