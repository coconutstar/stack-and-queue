#include<stdio.h>
#include<stdlib.h> 
typedef int ElemType;

typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}LinkNode;

typedef struct {
	LinkNode *front,*rear;//����ͷ������β 
}LinkQueue;

void InitQueue(LinkQueue &Q){	
	Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next=NULL;
}

bool IsEmpty(LinkQueue &Q){
	if(Q.front==Q.rear){
		return true;
	}else
	return false;
}

void EnQueue(LinkQueue &Q,ElemType e){
	LinkNode *pnew = (LinkNode*)malloc(sizeof(LinkNode));
	pnew->next=NULL;
	pnew->data=e;
	Q.rear->next=pnew;//βָ���nextָ��pnew; 
	Q.rear=pnew;
}

bool DeQueue(LinkQueue &Q,ElemType &e){
    if(Q.front==Q.rear){
    	return false;
	}
	LinkNode* q = Q.front->next;//qָ���ͷ��һ���ڵ� 
	e=q->data;
	Q.front->next = q->next;//�õ�һ���ڵ���� 
	if(Q.rear==q){//��ֻ�������һ����� 
		Q.rear = Q.front;//β��ָ��ͷ�����Ƕ���Ϊ���� 
	}
	free(q);//�ͷ�q�ڵ� 
	return true;
}

int main(){
	LinkQueue Q;
	bool ret;
	InitQueue(Q);
	EnQueue(Q,3);
	ret = IsEmpty(Q);
		if(ret){
		printf("����Ϊ��\n"); 
	}else{
		printf("���в�Ϊ��\n");
	} 
	EnQueue(Q,4);
	ret = IsEmpty(Q);
//	EnQueue(Q,5);
//	EnQueue(Q,6);
//	EnQueue(Q,7);
	ElemType e;
	ret = DeQueue(Q,e);
	if(ret){
		printf("ɾ���ɹ�:%d",e); 
	}else{
		printf("ɾ��ʧ��");
	} 
	return 0;
} 
