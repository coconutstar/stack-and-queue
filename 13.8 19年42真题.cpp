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

void CircleQueue(LinkQueue &Q){
	Q.front =(LinkNode*)malloc(sizeof(LinkNode));
	Q.rear=Q.front;
	Q.rear->next=Q.front;//����ѭ������ 
	//���
	EnQueue(Q,3);
	EnQueue(Q,4); 
	EnQueue(Q,5);
	//����
	ElemType e;
	bool ret; 
	ret = DeQueue(Q,e);
		if(ret){
		printf("ɾ���ɹ�:%d",e); 
	}else{
		printf("ɾ��ʧ��");
	} 
}
int main(){
	LinkQueue Q;
	CircleQueue(Q);
}
