#include<stdio.h>

struct node {
	int data;
	struct node *pNext;
};
typedef struct node NODE;
struct queue{
	NODE *pTail;
	NODE *pHead;
};
typedef struct queue QUEUE;
void KhoiTaoQUEUE(QUEUE &q){
	q.pTail = NULL;
	q.pHead = NULL;
}
NODE *KhoiTaoNode(int x){
	NODE *p = new NODE();
	p->data = x;
	p->pNext = NULL;
}
bool isEmpty(QUEUE q){
	if(q.pTail == NULL){
		return true;
	}
	return false;
}
bool pop(QUEUE &q,int &x){
	if(isEmpty(q)){
		return false;
	}else{
		NODE *k  = q.pHead;
		x = k->data;
		q.pHead = k->pNext;
		delete k;
	}
	return true;
	
}
bool push(QUEUE &q,NODE *p){
	if(p == NULL){
		return false;
	}
	if(isEmpty(q)){
		q.pHead = q.pTail = p;
	}else{
		q.pTail->pNext = p;
		q.pTail = p;
	}
	return true;
	
}
bool Top(QUEUE &q,int &x){
	if(isEmpty(q)){
		return false;
	}else{
		x = q.pHead->data;
	}
	return true;
	
}
void Xuat(QUEUE q){
	for(NODE *k = q.pHead ; k != NULL ; k = k->pNext){
		printf("%d ",k->data);
	}
}

int main(){
	QUEUE q;
	KhoiTaoQUEUE(q);
	printf("Nhap So Luong can tao \n");
	int n ;
	scanf("%d",&n);
	int x ; 
	for(int i = 0 ; i < n ; i++){
		printf("Nhap Gia Tri X : \n");
		scanf("%d",&x);
		NODE *p = KhoiTaoNode(x);
		push(q,p);
	}
	printf("\n--------------");
	Xuat(q);
	
	int f;
	pop(q,f);
	
	printf("POP duoc la : %d",f);
	
	printf("\n--------------");
	Xuat(q);
	
	Top(q,f);
	
	printf("TOP duoc la : %d",f);
	
	printf("\n--------------");
	Xuat(q);
	
	return 0 ;
}
