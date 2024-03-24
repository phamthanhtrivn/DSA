
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100
typedef struct 
{  
	char Name[256];  
	char Meaning[512]; 
}WORD;  
 
WORD a[MAX];
int n;
int size = sizeof(WORD);

void Hoanvi(int &c,int &d);
void QuickSort(WORD a[], int l, int r);
int BinarySearch(WORD a[], int left, int right, char *x);
int menu();
void nhaptu(WORD a[], int &n);
void hienthi(WORD s);
void taomoi(char *ttep);
void doctep(char *ttep,WORD a[],int &n);
void suachua(char *ttep);

int main(int argc, char *argv[])
{
	int chon,n = 0, kq;
	char x[256];
	do
	{
		chon = menu();
		switch(chon)	
		{
			case 1: taomoi("E:\\TUDIEN.txt"); break;
			case 2: doctep("E:\\TUDIEN.txt",a,n);				
					break;
			case 3: 
					printf("\n Tu can tra: ");
					fflush(stdin);
					gets(x);
					kq = BinarySearch(a,0,n-1,x);
					if(kq == -1) printf("\nKhong tim thay");
					else hienthi(a[kq]);break;
			case 4:  
					suachua("E:\\TUDIEN.txt");
					break;
		}
	
	}
	while (chon>0 && chon<6);
}
int menu()
{
	int chon;
	printf("\n 1. Tao bo tu");
	printf("\n 2. Hien thi bo tu dien");
	printf("\n 3. Tra tu");
	printf("\n 4. Sua chua");
	printf("\n 5. Xoa tu");
	printf("\n 6. Thoat");
	scanf("%d",&chon);
	return chon;
}

// Hoan vi
void Hoanvi(WORD &c,WORD &d)
{
	WORD t;
	t=c;
	c=d;
	d=t;
}

// Sap xep QuickSort
void QuickSort(WORD a[], int l, int r)
{
	int   i,j,N; 
	char   x[256];   
	N=r; 
	strcpy(x, a[(l+r)/2].Name);        // chen phan tu gia làm giá tri moc
	i =l; j = r; 
	do
	{ 
	   	while(strcmp(a[i].Name, x)<0) i++; 
	   	while(strcmp(a[j].Name, x)>0) j--; 
	    if(i <= j) 
	   { 
 		     Hoanvi(a[i],a[j]);
		     i++ ; j--; 
 	  } 
	}while(i < j);
	if(l < j)    QuickSort(a,l,j); 
	if(i < r)    QuickSort(a,i,r);
}
// Tim kiem nhi phan
int BinarySearch(WORD a[], int left, int right, char *x)
{ 
	if (left > right) return -1;
	int mid = (left + right) / 2;
 	if (strcmp(a[mid].Name, x)==0) 
 		return mid;
 	if (strcmp(a[mid].Name, x)>0) 
 		return BinarySearch(a,left,mid-1,x);
 	if (strcmp(a[mid].Name, x)<0) 
 		return BinarySearch(a,mid+1,right,x);
}
// NHap danh sach tu
void nhaptu(WORD a[], int &n)
{
	while(1)
	{  
		system("cls");		
		printf("\n Tu thu %d: \n", n+1);
		printf("\n Nhap vao tu khoa - Go enter de ket thuc:");
		fflush(stdin);
		gets(a[n].Name);
		if(a[n].Name[0] == '\0') break;
		printf("\n Nhap nghia cua tu:");
		fflush(stdin);
		gets(a[n].Meaning);
		n++;
	} 
}
// Hien thi
void hienthi(WORD s)
{
	printf("\n Tu khoa: %-21s", s.Name);
	printf("\n Nghia cua tu: %-11s", s.Meaning);
}
// Cap nhat
void suachua(char *ttep)
{
	WORD t;
	char x[256];
	FILE *fp;
	int n, i=0;
	if((fp=fopen(ttep,"r+b"))==NULL)
	{
		printf("khong the mo tep.\n");
		exit(1);
	}

	fseek(fp,0,SEEK_END);// Con tro chi ve vi tri cuoi tep
	n = ftell(fp)/size; // So ban ghi
	
	while(1)
	{  
		system("cls");
		printf("\n Tu can sua: ");
		fflush(stdin);
		gets(x);
		if(strlen(x)== 0) break;
		while(fread(&t ,sizeof(WORD),1,fp)>0)
		{
			if (strcmp(t.Name, x)==0) break;
			i++;
		} 
		printf("\n Vi tri cua tu: %d", i);
		if(i>=0 && i<=n)
		{
			fseek(fp,(i)*size,SEEK_SET);// Con tro chi ve vi tri cuoi tep
			printf("\n Thong tin hien tai:");
			fread(&t ,sizeof(WORD),1,fp);
			printf("\n Tu %s:", t.Name);
			printf("\n Nghia %s:", t.Meaning);
			printf("\n Nhap vao tu- Go enter de ket thuc:");
			fflush(stdin);
			gets(t.Name);
			if(t.Name[0] == '\0') break;
			printf("\n Nhap nghia cua tu:");
			fflush(stdin);
			gets(t.Meaning);
			printf("\n Co luu lai thong tin khong? C/K:");
			fflush(stdin);
			if(toupper(getchar())=='C')
			{
				fseek(fp,(i)*size,SEEK_SET);
				fwrite(&t,sizeof(WORD),1,fp);//ghi vao file
			}
		}
		else 
		{
			printf("\n tu can sua ko co trong tu dien");
			break;
		}
	} 
	fclose(fp);//dong file
}
// Ghi tep
void taomoi(char *ttep)
{
	FILE *fp;
	if((fp=fopen(ttep,"wb"))== NULL)
	{
		printf("khong the mo tep.\n");
		exit(1);
	}
	nhaptu(a, n);
	QuickSort(a,0,n-1);	
	fwrite(a,sizeof(WORD),n,fp);
	//for (int i = 0; i<n; i++)
		//fwrite(&a[i],sizeof(WORD),1,fp);//ghi vao file
	fclose(fp);//dong file	
}
// Doc tep
void doctep(char *ttep, WORD a[], int &n)
{
	FILE *fp;
	int i = 0;
	if((fp=fopen(ttep,"rb"))==NULL)
	{
		printf("khong the mo tep.\n");
		exit(1);
	}
	while(fread(&a[i] ,sizeof(WORD),1,fp)>0)
	{
		printf("\n %s: %s ",a[i].Name, a[i].Meaning);
		i++;
	} 
	n = i;
	fclose(fp);//dong file
}
