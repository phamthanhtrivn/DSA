#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct Node{
	int mu;
	float heSo;
	Node *next;
};
struct List{
	Node *head;
	Node *last;
};
Node *makeNode(int hs,int mu){
	Node *newNode = new Node();
	if(newNode == NULL){
		return NULL;
	}
	newNode->mu = mu;
	newNode->heSo = hs;
	newNode->next = NULL;
	return newNode;
}
void init(List &L){
	L.head = NULL;
	L.last = NULL;
}
void swap1(int &a,int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
void swap2(float &a,float &b){
	int tmp = a;
	a = b;
	b = tmp;
}
void sort(List &L){
	for(Node *p = L.head;p->next != NULL;p = p->next){
		for(Node *q = p->next; q != NULL; q = q->next){
			if(p->mu < q->mu){
				swap1(q->mu,p->mu);
				swap2(p->heSo,q->heSo);
			}
		}
	}
}
void insertLast(List &L,float hs,int mu){
	Node *p = makeNode(hs,mu);
	if(L.head == NULL && L.last == NULL){
		L.head = p;
		L.last = p;
	}
	L.last->next = p;
	L.last = p;
}
void nhap(List &L){
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++){
		int mu;
		float heSo;
		if(heSo != 0){
		 scanf("%f",&heSo);
		}
		scanf("%d",&mu);
		insertLast(L,heSo,mu);
	}
}
void tru(List &L,List L1,List L2){
	init(L);
	Node *p = L1.head;
	Node *q = L2.head;
	while(q != NULL && p != NULL){
		if(q->mu == p->mu){
			int tong = p->heSo - q->heSo;
			if(tong != 0){
				insertLast(L,tong,p->mu);
			}
			p = p->next;
			q = q->next;
		}
		else if(q->mu < p->mu){
			insertLast(L,p->heSo,p->mu);
			p = p->next;
		}
		else{
		 insertLast(L,q->heSo,q->mu);
		 q = q->next;
		}
	}
	while(q != NULL){
		insertLast(L,q->heSo,q->mu);
		q = q->next;
	}
	while(p != NULL){
		insertLast(L,p->heSo,p->mu);
		p = p->next;
	}
}
void in(List L){
	if(L.head->heSo == 1){
		printf("x^%d",L.head->mu);
	}
	else{
		printf("%.0fx^%d",L.head->heSo,L.head->mu);
	}
	Node *p = L.head->next;
	while(p != NULL){
		if(p->heSo > 0){
			if(p->mu != 0 ){
				printf(" + %.0fx^%d",p->heSo,p->mu);
			}
			else{
				printf(" + %0.f",p->heSo);
			}
		}
		else{
			if(p->mu != 0 ){
				printf(" %.0fx^%d",p->heSo,p->mu);
			}
			else{
				printf(" %0.f",p->heSo);
			}
		}
		p = p->next;
	}
}
int main(){
	List L,L1,L2;
	init(L); init(L1); init(L2);
	nhap(L1); nhap(L2);
	sort(L1); sort(L2);
	tru(L,L1,L2);
	in(L);
	return 0;
}
