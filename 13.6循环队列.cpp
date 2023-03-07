#include<stdio.h>
#include<stdlib.h> 

#define MaxSize 5
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];//数组 存放MaxSize-1
	int rear,front;//指向栈顶的变量 
}SqQueue;

bool InitQueue(SqQueue &Q){
	Q.front=Q.rear=0;
}

bool isEmpty(SqQueue &Q){
		return Q.front==Q.rear; 
}

bool EnQueue(SqQueue &Q,ElemType e){
	if((Q.rear+1)%MaxSize==Q.front){
		return false;
	}
	Q.data[Q.rear]=e;
	Q.rear=(Q.rear+1)%MaxSize;
	return true;
}

bool DeQueue(SqQueue &Q,ElemType e){
	if(Q.front==Q.rear){
		return false;
	} else{
		e=Q.data[Q.front];
		Q.front=(Q.front+1)%MaxSize;
	}
	return true;
}
int main(){
	SqQueue Q;
	InitQueue(Q);
	bool ret; 
	ret = isEmpty(Q);
	if(ret){
		printf("空\n"); 
	}
	EnQueue(Q,3);
	EnQueue(Q,4);
	EnQueue(Q,5);
	EnQueue(Q,6);
	ret = EnQueue(Q,7);
	if(ret){
		printf("EnQueue success\n");
	}else{
		printf("EnQueue failure\n");
	}
	ElemType element;
	ret = DeQueue(Q,element);
		if(ret){
		printf("DeQueue success\n");
	}else{
		printf("DeQueue failure\n");
	}
	ret = EnQueue(Q,7);
	if(ret){
		printf("EnQueue success\n");
	}else{
		printf("EnQueue failure\n");
	}
	return 0;
}
