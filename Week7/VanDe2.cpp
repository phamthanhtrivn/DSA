#include <stdio.h>
#define MAXQUEUE 100

struct mathang{
	int mamh;
	char tenmh[12];
};

struct queue{
	int front, rear;
	mathang nodes[MAXQUEUE];
};

void init(queue *pq) {
	pq->front = pq->rear = MAXQUEUE - 1;
}

int empty(queue *pq) {
	return (pq->front == pq->rear) ? 1 : 0;
}

void insert(queue *pq, mathang x) {
	if (pq->rear == MAXQUEUE - 1)
		pq->rear = 0;
	else 
		pq->rear++;
	if (pq->front == pq->rear)
		printf("kho hang bi day!\n");
	else 
		pq->nodes[pq->rear] = x;
}

mathang remove(queue *pq) {
	if (empty(pq)) {
		printf("kho khong con hang!\n");
	}
	else 
	{
		if (pq->front == MAXQUEUE - 1)
			pq->front = 0;
		else 
			pq->front++;
		return pq->nodes[pq->front];
	}
}

void duyet(queue *pq) {
	int i;
	if (empty(pq)) {
		printf("Kho khong con hang!\n");
		return;
	}
	if (pq->front == MAXQUEUE - 1)
		i = 0;
	else
		i = pq->front + 1;
	while (i != pq->rear) {
		printf("%11d%15s", pq->nodes[i].mamh, pq->nodes[i].tenmh);
		if (i == MAXQUEUE - 1)
			i = 0;
		else 
			i++;
	}
	printf("%11d%15s", pq->nodes[i].mamh, pq->nodes[i].tenmh);
}

int main() {
	queue q;
	int chon, front1;
	char c;
	mathang mh;
	init(&q);
	do {
		printf("\n\n\t\t\tCHUONG TRINH QUAN LY KHO");
		printf("\n\t\t\t(NHAP TRUOC - XUAT TRUOC)");
		printf("\n\nCac chuc nang cua chuong trinh:\n");
		printf("1: Nhap mot mat hang\n");
		printf("2: Xuat mot mat hang\n");
		printf("3: Xem mat hang chuan bi xuat\n");
		printf("4: Xem mat hang moi nhap\n");
		printf("5: Xem cac mat hang co trong kho\n");
		printf("6: Xuat toan bo kho hang\n");
		printf("0: Ket thuc chuong trinh\n");
		printf("Chuc nang ban chon: ");
		scanf("%d", &chon);
		switch(chon) {
			case 1:
				printf("Ma mat hang: ");
				scanf("%d", &mh.mamh);
				printf("Ten mat hang: ");
				scanf("%s", &mh.tenmh);
				insert(&q, mh);
				break;
			case 2:
				if (!empty(&q))
				{
					mh = remove(&q);
					printf("\nMat hang xuat:Ma:%d, Ten:%s",mh.mamh, mh.tenmh);
				}
				printf("\nKho khong con hang");
				break;
			case 3:
				front1 = (q.front==MAXQUEUE-1 ? 0 : q.front+1);
				printf("\nMat hang chuan bi xuat: Ma:%d, Ten:%s", q.nodes[front1].mamh, q.nodes[front1].tenmh);
				break;
			case 4:
				printf("\nMat hang moi nhap: Ma:%d Ten:%s", q.nodes[q.rear].mamh,q.nodes[q.rear].tenmh);
				break;
			case 5:
				{
				printf("\nCac mat hang co trong kho:");
				printf("\n%11s%15s", "MA MAT HANG", "TEN MAT HANG");
				duyet(&q);
				break;
				}
			case 6: // xoa toan bo queue (khoi dong queue)
				printf("\nBan co chac khong (c/k): ");
				c = getchar();
				if (c == 'c' || c == 'C')
					init(&q);
				break;
		}
	} while (chon != 0);
	return 0;
}
