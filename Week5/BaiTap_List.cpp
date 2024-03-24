#include <stdio.h>
#include <iostream>
using namespace std;
struct SACH
{
	char TenSach[250];
	char *TacGia[5];
	int SoTG;
	int NamXB;
};
struct NODE
{
	SACH Data;
	NODE *pNext;
};
struct LIST
{
	NODE *pHead;
	NODE *pTail;
};
// Nhap thong tin 1 quyen sach
void InputSach(SACH &s)
{
	char TenTG[50];
	int dodai;
	fflush(stdin);
	printf("\n Nhap vao ten sach: ");
	gets(s.TenSach);
	
	printf("\n Nhap vao nam XB: ");
	scanf("%d", &s.NamXB);
	
	printf("\n Nhap vao so tac gia: ");
	scanf("%d", &s.SoTG);
	
	for(int i = 0; i < s.SoTG; i++)
	{
		fflush(stdin);
		printf("\n Nhap vao ten TG %d: ", i+1);
		gets(TenTG);
		dodai = strlen(TenTG);
		s.TacGia[i] = new char[dodai];
		strcpy(s.TacGia[i],TenTG);
	}
}
// Xuat thong tin 1 quyen sach
void OutputSach(SACH s)
{
	printf("\n Ten sach: %s",s.TenSach);	
	printf("\n Nam XB: %d", s.NamXB);	
	printf("\n So tac gia: %d", s.SoTG);
	
	for(int i = 0; i < s.SoTG; i++)
		printf("\n Ten TG %d: %s",i+1,s.TacGia[i]);
}
// Khoi tao danh sach
void Init(LIST &L)
{
	L.pHead = L.pTail= NULL;
}
// Tao mot Node
NODE* getNode ( SACH x) 
	{	
		NODE *p;		
		p = new NODE;  // C?p phát vùng nh? cho node
		if  (p==NULL)   
		{ 
			cout<<"Khong du bo nho!";  
			return NULL; 
		}
		p->Data = x; 	// Gán d? li?u cho ph?n t? p
		p->pNext = NULL;
		return p; 
	}
// Chen 1 node vao cuoi danh sach	
void InsertLast(LIST &L,SACH x) {
	NODE* p = getNode(x);
	if(p == NULL) {
		return;
	}
	if(L.pHead == NULL && L.pTail == NULL) {
		L.pHead = L.pTail = p;
	}
	L.pTail->pNext = p;
	L.pTail = p;
}
// Tao Danh sach
void CreateList(LIST &L)
{
	int n;
	SACH x;
	Init(L);
	printf("\n Nhap vao so muc sach: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		InputSach(x);
		InsertLast(L,x);
	}		
}
// Hien thi danh sach
void Display(LIST L) {
	NODE *p = L.pHead;
	if(p == NULL) printf("\n Danh sach rong");
	while(p!=NULL)
	{
		OutputSach(p->Data);
		p = p->pNext;
	}	
}
// Dem so muc sach cua tac gia bat ky
int DemSoLuong(LIST L, char TenTG[])
{
	int dem = 0;
	NODE *p = L.pHead;
	if(p == NULL) printf("\n Danh sach rong");
	while(p!=NULL)
	{
		
		for(int i = 0; i < p->Data.SoTG; i++)
		{
			if(strcmp(p->Data.TacGia[i],TenTG)==0)
				dem++;			
		}
		p = p->pNext;
	}
	return dem;		
}
//
int main(int argc, char *argv[])
{
	LIST L;
	SACH s;
	char TenTG[50];
	CreateList(L);	
	Display(L);
	printf("\n Nhap vao ten TG can tinh: ");
	gets(TenTG);
	int kq = DemSoLuong(L,TenTG);
	printf("\n So muc sach cua TG %s: %d",TenTG, kq);
	return 0;
}