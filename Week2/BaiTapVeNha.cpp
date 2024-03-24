#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int &a, int &b);
void interchange(int a[], int n);
void buble(int a[], int n);
void printArray(int a[], int n);

int main() {
	int n; scanf("%d", &n);
	int a[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 51;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
//	printf("Mang duoc sap xep theo kieu doi cho truc tiep:\n");
//	interchange(a, n);
	printf("Mang duoc sap xep theo kieu noi bot:\n");
	buble(a, n);
	return 0;
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void interchange(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
				printArray(a, n);
			}
		}
	}
}

void buble(int a[], int n) {
	int check = 0;
	for (int i = 0; i < n - 1; i ++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				printArray(a, n);
				check = 1;
			}
		}
		if (check == 0) {
			break;
		}
	}
}

void printArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
