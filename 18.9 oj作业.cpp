#include<stdio.h>
#include<stdlib.h>

#define MaxSize 5
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];//数组 
	int top;//指向栈顶的变量 
}SqStack;

typedef struct {
	ElemType data[MaxSize];//数组 存放MaxSize-1
	int rear,front;//指向栈顶的变量 
}SqQueue;

void InitStack(SqStack &s){
	s.top = -1;//栈为空
}

bool InitQueue(SqQueue &Q){
	Q.front=Q.rear=0;
}

bool StackEmpty(SqStack &s){
	if(-1==s.top){
		return true;
	}else{
		return false;
	}
}

bool Push(SqStack &s,ElemType e){
	//判断栈是否满
	if(s.top==MaxSize-1){
		return false;
	} 
	s.data[++s.top]=e;
	return true;
}

bool Pop(SqStack &s,ElemType &e){
	if(StackEmpty(s)){
		return false; 
	}
	e = s.data[s.top--];
	return true;
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

bool DeQueue(SqQueue &Q,ElemType &e){
	if(Q.front==Q.rear){
		return false;
	} else{
		e=Q.data[Q.front];
		Q.front=(Q.front+1)%MaxSize;
	}
	return true;
}

int main(){
	SqStack s;
	InitStack(s); 
		ElemType e;
	for(int i=0;i<3;i++){
		scanf("%d",&e);
		Push(s,e);
	}
	bool ret=Pop(s,e);
	while(ret){
		printf("%2d",e);
		ret=Pop(s,e);
	}
	printf("\n",e);
	
	SqQueue Q;
	InitQueue(Q);
	for(int i=0;i<5;i++){
		scanf("%d",&e);
		ret=EnQueue(Q,e);
	
	if(!ret){
		printf("false\n",e);
	}
}
    ret = DeQueue(Q,e);
	while(ret){
		printf("%2d",e);
		ret = DeQueue(Q,e);
	}
}
