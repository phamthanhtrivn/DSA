#include <stdio.h>

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
				swap(&a[i], &a[j]);
				print(a, n);
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
			swap(&a[i], &a[min_pos]);
			print(a, n);
		}
	}
}

void insertionSort(int a[], int n) { // chen truc tiep
	for (int i = 1; i < n; i++) {
		int temp = a[i]; //temp la vi tri dang xet, j la vi tri cua so truoc do
		int j = i - 1;
		while (j >= 0 && a[j] > temp) {
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = temp;
		print(a, n);
	}
}

void bubblesort(int a[], int n) { // noi bot
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
				print(a, n);
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
			swap(&a[i], &a[j]);
			print(a, 8);
		}
	}
	// dua chot ve giua
	++i; swap(&a[i], &a[r]); print(a, 8);
	return i; // vi tri
}
void quickSort(int a[], int l, int r) { // lomuto, O(n^2)
	if (l >= r) return;
	int p = partition(a, l, r);
	quickSort(a, l, p - 1);
	quickSort(a, p + 1, r); 
}

void iMenu() {
	printf("=======================Menu=====================\n");
	printf("0. Thoat\n");
	printf("1. Sap xep chon\n");
	printf("2. Sap xep chen\n");
	printf("3. Sap xep doi cho\n");
	printf("4. Sap xep noi bot\n");
	printf("5. Sap xep nhanh\n");
	printf("================================================\n");
}

int main() {
	int a[] = {10, 3, 7, 4, 2, 8, 5, 12}; 
	int b[] = {14, 33, 27, 10, 35, 19, 42, 44};
	int n = 8;
	printf("Mang a: ");
	print(a, n);
	do {
		iMenu();
		printf("Chon: ");
		int lc; scanf("%d", &lc);
		if (lc == 0) {
			break;
		}
		else if (lc == 1) {
			printf("Mang sau khi sap xep:\n");
			selectionSort(a, n);
		}
		else if (lc == 2) {
			printf("Mang sau khi sap xep:\n");
			insertionSort(a, n);
		}
		else if (lc == 3) {
			printf("Mang sau khi sap xep:\n");
			interchangesort(a, n);
		}
		else if (lc == 4){
			printf("Mang sau khi sap xep:\n");
			bubblesort(a, n);
		}
		else if (lc == 5) {
			printf("Mang sau khi sap xep:\n");
			quickSort(a, 0, 7);
		}
		else {
			printf("Lua chon khogn hop le!\n");
		}
	} while (n != 0);
	printf("Mang b: ");
	print(b, n);
	do {
		iMenu();
		printf("Chon: ");
		int lc; scanf("%d", &lc);
		if (lc == 0) {
			break;
		}
		else if (lc == 1) {
			printf("Mang sau khi sap xep:\n");
			selectionSort(b, n);
		}
		else if (lc == 2) {
			printf("Mang sau khi sap xep:\n");
			insertionSort(b, n);
		}
		else if (lc == 3) {
			printf("Mang sau khi sap xep:\n");
			interchangesort(b, n);
		}
		else if (lc == 4){
			printf("Mang sau khi sap xep:\n");
			bubblesort(b, n);
		}
		else if (lc == 5) {
			printf("Mang sau khi sap xep:\n");
			quickSort(b, 0, 7);
		}
		else {
			printf("Lua chon khogn hop le!\n");
		}
	} while (n != 0);
	return 0;
}
