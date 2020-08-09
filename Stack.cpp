#include<stdio.h>

// Nhap danh sach stack chua cac so nguyen , sau do xuat ra man hinh gia tri cac so nguyen do
struct node{
	int data;
	struct node *pnext;
};
typedef node NODE;
struct stack{
	NODE *ptop; // dung con tro dau de quan ly
};
typedef struct stack STACK;

void KhoiTaoStack(STACK &s){
	s.ptop = NULL;
}
NODE *KhoiTaoNode(int x){
	NODE *p = new NODE();
	if(p == NULL){
		printf("Khong Du Bo Nho");
		return NULL;
	}
	p->data = x;
		p->pnext = NULL;
		return p;
}

bool isEmpty(STACK s){ // kiem tra xem stack co rong hay khong.
	if(s.ptop == NULL){
		return true;
	}
	return false;
}
void push(STACK &s,NODE *p){ // them 1 phan tu vao dau stack theo co che cua stack LIFO.
	
	bool check = isEmpty(s);
	if(check){
		s.ptop = p;
	}else{
		p->pnext =s.ptop;
		s.ptop = p;
		return;
	}
	
}
bool pop(STACK &s, int &x){ // lay phan tu dau stack va tra ve gia tri dau stack dong thoi huy no di.
	if(isEmpty(s)){
		return false;
	}else{
		NODE *p = s.ptop ;
		x = p->data;
		s.ptop = p->pnext;
		delete p;
		
	}
	return true;
}
bool top(STACK &s, int &x){ //xem thong tin cua stack dau danh sach va khong huy no di 
	if(isEmpty(s)){
		return false;
	}else{
		x = s.ptop->data;
	}
	return true;
}

void xuat(STACK s){
	for(NODE *k = s.ptop ;  k != NULL ; k = k->pnext){
		printf("%d ",k->data);
	}
}
void ChuyenDoi(STACK &s,int soDoi){
	
	while(soDoi != 0 ){
		int x = soDoi % 2 ;
		NODE *p = KhoiTaoNode(x);
		push(s,p);
		soDoi /=  2;
	}
	
}
int main(){
	
	STACK s;
	KhoiTaoStack(s);
//	int x ;
//	for(int i = 0 ; i < 5 ; i++){
//		printf("Nhap Gia Tri X ! \n");
//		scanf("%d",&x);
//		NODE *p = KhoiTaoNode(x);
//		push(s,p);
//		
//	}
//	printf("Gia tri ban dau \n");
//	
//	xuat(s);
//	printf("------- \n");
//	int t = 0 ;
//	pop(s,t);
//	printf("Pop Duoc: %d",t);
//	printf("\n");
//	xuat(s);
//	top(s,t);
//	printf("top Duoc: %d",t);
//	printf("\n");

    ChuyenDoi(s,35); // neu dung mang ta can phai duyet tu sau ve truoc de lay chinh xac
    // nhung neu dung statck thi no dung voi co che LIFO last in first out
	xuat(s);
	
	return 0;
}




