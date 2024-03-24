#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct SACH{
	char tenSach[40];
	char tacGia[5][100];
	int soTG;
	char nhaXB[40];
	int namXB;
};
struct Node{
	SACH data;
	Node *next;
};
struct List{
	Node *head;
	Node *last;
};
void init(List &L){
	L.head = NULL;
	L.last = NULL;
}
void nhap(SACH &a){
	fflush(stdin);
//	printf("Nhap ten ten Sach\n");
	gets(a.tenSach);
//	printf("Nhap so luong tac gia\n");
	scanf("%d",&a.soTG);
	for(int i=0;i<a.soTG;i++){
		fflush(stdin);
//		printf("Nhap ten tac gia\n");
		gets(a.tacGia[i]);
	}
//	printf("Nhap ten nha san xuat\n");
    fflush(stdin);
	gets(a.nhaXB);
//	printf("Nhap ten nam xuat ban\n");
	scanf("%d",&a.namXB);
}


void in(SACH a){
	printf("Ten Sach : %s\n",a.tenSach);
	for(int i=0;i<a.soTG;i++){
		printf("Tac gia  : %s\n",a.tacGia[i]);
	} 
	printf("Nha xuat ban : %s\n",a.nhaXB);
	printf("Nam xuat ban : %d\n",a.namXB);
}
Node *makeNode(SACH a){
	Node *newNode = new Node();
	newNode->data = a;
	newNode->next = NULL;
	return newNode;
}
void insertLast(SACH a,List &L){
	Node *p = makeNode(a);
	if(L.head == NULL && L.last == NULL){
		L.head = p;
		L.last = p;
		return;
	}
	L.last->next = p;
	L.last = p;
}
void ghiFile(char *tenFile,List L){
	FILE *f;
	f = fopen(tenFile,"wb");
	Node *p = L.head;
	while(p != NULL){
		SACH a = p->data;
	fwrite(&a,sizeof(SACH),1,f);
	p = p->next;
}
	fclose(f);
}
void docFile(char *tenFile,List &L){
	init(L);
	FILE *f;
	f = fopen(tenFile,"rb");
	if(f == NULL) return;
	SACH a;
	while(fread(&a,sizeof(SACH),1,f) > 0){
		insertLast(a,L);
	}
	fclose(f);
}


int soLuong(char tacGia[],List L){
	int cnt = 0;
	Node *p = L.head;
	while(p != NULL){
		for(int i=0;i<p->data.soTG;i++){
			if(strcmp(tacGia,p->data.tacGia[i]) == 0){
				cnt++;
			}
		}
		p = p->next;
	}
	return cnt;
}
void xoaTatCaTacGia(char tenTG[],List &L,char *tenFile){
	Node *p = L.head;
	Node *q = NULL;
	while(p != NULL){
		int check = 0;
		for(int i=0;i<p->data.soTG;i++){
			if(strcmp(p->data.tacGia[i],tenTG) == 0){
				check = 1;
			}
		}
		if(check == 1){
			if(q == NULL){
				L.head = L.head->next;
			}
			else{
				q->next = p->next;
			}
			p = p->next;
		}
		else{
			q = p;
			p = p->next;
		}
	}
	ghiFile(tenFile,L);
}


char arr[50][100];
int check(char name[]){
	for(int i=0;i<50;i++){
		if(arr[i][0] == NULL){
			return 0;
		}
		if(strcmp(arr[i],name) == 0){
			return 1;
		}
	}
}
void thongKe(char *tenFile,List L){
	FILE *f;
	f = fopen(tenFile,"w");
	Node *p = L.head;
	int j = 0; // quan li ham arr;
	while(p != NULL){
		for(int i=0;i<p->data.soTG;i++){
			if(check(p->data.tacGia[i]) == 0){
				int cnt = 1;// khoi tao tac gia nay co 1 quyen sach
				strcpy(arr[j],p->data.tacGia[i]);// danh dau da xuat hien;
				j++;
				fprintf(f,"Ten Tac Gia : %s\n",p->data.tacGia[i]); // ghi ten tac gia vao file
				fprintf(f,"Ten sach : %s\n",p->data.tenSach);
				Node *q = p->next;
				while(q != NULL){
					for(int k=0;k<q->data.soTG;k++){
						if(strcmp(p->data.tacGia[i],q->data.tacGia[k]) == 0){
							fprintf(f,"Ten sach : %s\n",q->data.tenSach);
							cnt++; 
						}
					}
					q = q->next;
				}
				fprintf(f,"So Luong Sach : %d\n",cnt);
			}
		}
		p = p->next;
	}
	fclose(f);
}
void duyet(List L){
	Node *p = L.head;
	while(p != NULL){
		in(p->data);
		p = p->next;
	}
}
int main(){
	int n;
	printf("Nhap so luong sach : \n");
	scanf("%d",&n);
	List L; init(L);
	SACH a[n];
	while(1){
		printf("====================================================\n");
		printf("1.Nhap thong tin cho sach\n");
		printf("2.Xuat thong tin sach\n");
		printf("3.Ghi thong tin sach vao danh sach lien ket\n");
		printf("4.Ghi vao file\n");
		printf("5.Ghi File vao lai\n");
		printf("6.So luong so sach cua tac gia\n");
		printf("7.Xoa mot quyen sach cua tac gia a\n");
		printf("8.Thong ke so luong quyen sach cua tung tac gia\n");
		printf("9.Duyet List\n");
		printf("10.Thoat chuong trinh\n");
		printf("====================================================\n");
		printf("Moi lua chon\n");
		int chon; scanf("%d",&chon);
		if(chon == 1){
			for(int i=0;i<n;i++){
				nhap(a[i]);
			}
		}
		else if(chon == 2){
			for(int i=0;i<n;i++){
				in(a[i]);
			}
		}
		else if(chon == 3){
			for(int i=0;i<n;i++){
				insertLast(a[i],L);
			}
		}
		else if(chon == 4){
			ghiFile("DanhSachSACH.bin",L);
		}
		else if(chon == 5){
			docFile("DanhSachSACH.bin",L);
		}
		else if(chon == 6){
			fflush(stdin);
			char tg[100];
			printf("Nhap ten tac gia\n");
			gets(tg);
			printf("%d\n",soLuong(tg,L));
		}
		else if(chon == 7){
			fflush(stdin);
			char tg[100];
			printf("Nhap ten tac gia\n");
			gets(tg);
			xoaTatCaTacGia(tg,L,"XoaTacGia.bin");
		}
		else if(chon == 8){
			thongKe("ThongKe.txt",L);
		}
		else if(chon == 9){
			duyet(L);
		}
		else{
			break;
		}
	}
}
/*
AAA
3
Nguyen Van A
Nguyen Van B
Tran Van B
AAA
1234
BBB
3
Nguyen Van A
Tran Van B
Nguyen Van C
BBB
1290
CCC
2
Nguyen Van A
Nguyen Van B
CCC
1235
*/

