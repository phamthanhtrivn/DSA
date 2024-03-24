#include <stdio.h>
#include <string.h>

typedef struct{
	char Name[256];
	char Meaning[512];
}WORD;

int search(WORD dic[], int n, char keyword[]) {
	for (int i = 0; i < n; i++) {
		if (strcmp(dic[i].Name, keyword) == 0) {
			printf("Word: %s\nMeaing: %s\n", keyword, dic[i].Meaning);
			return i;
		}
	}
	return -1;
}

int main() {
	WORD dic[] = {
		{"apple", "qua tao"},
        {"banana", "qua chuoi"},
        {"cat", "con meo"},
        {"dog", "con cho"},
        {"elephant", "con voi"}
	};
	
	int n = sizeof(dic)/sizeof(dic[0]);
	char keyword[256];
	printf("Nhap tu can tim kiem: ");
	scanf("%s", keyword);
	int kq = search(dic, n, keyword);
	if (kq == -1) {
		printf("Khong co trong tu dien\n");
	}
}


