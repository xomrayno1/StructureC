#include<stdio.h>

// con tro la dung de luu dia chi cua gia tri khac
struct node{
	int data;
	struct node *pNext;   // con tro pnext luu dia chi kieu node cua gia tri khac
};
typedef struct node NODE;


struct list{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;
void KhoiTao(LIST &l){
	l.pHead = NULL;
	l.pTail  = NULL;
}
NODE *KhoiTaoNODE(int x){
	NODE *p = new NODE();
	if(p == NULL){
		printf("\nKhong du bo nho");
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void ThemVaoDau(LIST &l,NODE *p){
	if(l.pHead == NULL){ // neu rong
		l.pHead = l.pTail = p;
	}else{ // neu da co  thi node moi pnext se luu dia chi cua gia tri dau tien cu// sau do cho phead = p de quay ve dau
					//list la danh sach cac node
		p->pNext = l.pHead ;
		l.pHead = p;
	}
}
void ThemVaoCuoi(LIST &l, NODE *p){
	if(l.pHead == NULL){
		l.pHead = l.pTail = p;
	}else{
		l.pTail->pNext = p;
		l.pTail = p ;
	}
}
void HamXuatNode(LIST l){
	
	for(NODE *k = l.pHead ; k != NULL; k = k->pNext){
		printf("%d",k->data);
		
	}
	
}
void ThemNodePSauNodeQ(LIST &l,NODE *p , int q){
	if(l.pTail->data == q){
		l.pTail->pNext = p;
		l.pTail = p;
		return ;
	}
	NODE *G;
	for(NODE *k = l.pHead ; k != NULL ;  k = k->pNext ){
			G = k->pNext;
		if(k->data  == q){
			k->pNext = p;
			p->pNext = G;
			return ; 
		}
	
	}
}
void ThemNodePTruocNodeQ(LIST &l, NODE *p , int q){
	if(l.pHead->data == q){
		ThemVaoDau(l,p);
		return;
	}
	NODE *G ;
	for(NODE *k = l.pHead ; k != NULL ; k = k->pNext){
		if(k->data  == q){
			G->pNext = p;
			p->pNext = k;
			return ;
		}
		G = k;
	}
}
int lengNode(LIST l){
	int dem = 0 ;
	for(NODE *k = l.pHead ; k != NULL ; k = k->pNext){
		dem += 1;
	
	}
	return dem;
}
void ThemBatKi(LIST &l,NODE *p, int vt){
	if(l.pHead == NULL){
		ThemVaoDau(l,p);
		return ;
	}
	int length = lengNode(l);
	if(vt >= length + 1){
		ThemVaoCuoi(l,p);
		return;
	}
	NODE *G;
	int dem = 0 ;
	for(NODE *k = l.pHead ; k != NULL ; k = k->pNext){
		dem += 1;
		if(dem == vt){
			G->pNext = p;
			p->pNext =  k;
			return;
		}
		G = k;
	}
}
void XoaNodeDau(LIST &l){
	if(l.pHead == NULL){
		return ;
	}else{
		NODE *G = l.pHead;
		l.pHead = G->pNext;
		delete G;
	}
}
void XoaNodeCuoi(LIST &l){
	if(l.pHead == NULL){
		return ;
	}else{
		for(NODE *k = l.pHead ; k != NULL ; k=k->pNext){
			if(l.pTail == k->pNext){
				NODE *G = k->pNext;
				k->pNext = NULL;
				l.pTail = k;
				delete G;
			}
		}
	}
}

void XoaNodeSauNodeQ(LIST &l,int q){
	NODE *G;
	for(NODE *k = l.pHead ; k != NULL ; k = k->pNext){
		
		if(k->data  == q){
			NODE *Q = k->pNext;
			k->pNext = Q->pNext;
			delete Q;
			return;
		}
	
	}
}
void XoaNodeTruocNodeQ(LIST &l,int q){
	NODE *G;
	for(NODE *k = l.pHead ; k != NULL ; k = k->pNext){
		
		if(k->pNext->data == q){
			NODE *J = k;
			G->pNext = k->pNext;
			delete J;
			return;
		}
		G = k ;
	
	}
}
void XoaBatKi(LIST &l, int x){
		NODE *G;
		for(NODE *k = l.pHead ; k != NULL ; k = k->pNext){
			if(k->data == x){
				NODE *J = k;
				G->pNext = J->pNext;
				delete k ;
				return;
			}
			G  = k;
		}	
}
int main(){

	LIST l;
	KhoiTao(l);

	int n ; 
	printf("Nhap So Luong Node Can Them \n");
	scanf("%d",&n);
	
	for(int i = 1 ; i <= n ;  i++){
		int x ;
		printf("Nhap X ");
		scanf("%d",&x);
		NODE *p = KhoiTaoNODE(x);
		ThemVaoDau(l,p);
		
	}
	printf("-----------\n");
	HamXuatNode(l);
	
	printf("----------- \n");
	//	XoaNodeDau(l);
	//XoaNodeCuoi(l);
	//XoaNodeSauNodeQ(l,3)
	//XoaNodeTruocNodeQ(l,3);
//	XoaBatKi(l,5);
	HamXuatNode(l);

return 0;
}


// 5  + 4 + 3 + 2 +1 

