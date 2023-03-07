#include<stdio.h>
#include<stdlib.h> 
typedef int ElemType;

typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}LinkNode;

typedef struct {
	LinkNode *front,*rear;//链表头、链表尾 
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
	Q.rear->next=pnew;//尾指针的next指向pnew; 
	Q.rear=pnew;
}

bool DeQueue(LinkQueue &Q,ElemType &e){
    if(Q.front==Q.rear){
    	return false;
	}
	LinkNode* q = Q.front->next;//q指向队头第一个节点 
	e=q->data;
	Q.front->next = q->next;//让第一个节点断链 
	if(Q.rear==q){//当只存在最后一个结点 
		Q.rear = Q.front;//尾巴指向头，即是队列为空了 
	}
	free(q);//释放q节点 
	return true;
}

int main(){
	LinkQueue Q;
	bool ret;
	InitQueue(Q);
	EnQueue(Q,3);
	ret = IsEmpty(Q);
		if(ret){
		printf("队列为空\n"); 
	}else{
		printf("队列不为空\n");
	} 
	EnQueue(Q,4);
	ret = IsEmpty(Q);
//	EnQueue(Q,5);
//	EnQueue(Q,6);
//	EnQueue(Q,7);
	ElemType e;
	ret = DeQueue(Q,e);
	if(ret){
		printf("删除成功:%d",e); 
	}else{
		printf("删除失败");
	} 
	return 0;
} 
