#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];//数组 
	int top;//指向栈顶的变量 
}SqStack;
void InitStack(SqStack &s){
	s.top = -1;//栈为空
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

bool GetTop(SqStack &s,ElemType &e){
	if(StackEmpty(s)){
		return false; 
	}
	e=s.data[s.top];
	return true;
}

bool Pop(SqStack &s,ElemType &e){
	if(StackEmpty(s)){
		return false; 
	}
	e = s.data[s.top--];
	return true;
}
int main(){
	SqStack s;
	InitStack(s); 
	bool flag;
	flag = StackEmpty(s);
	if(flag){
		printf("stack is empty\n");
	}
	Push(s,3);
	Push(s,4);
	Push(s,5);
	ElemType m;
	flag = GetTop(s,m);
	if(flag){
		printf("找到元素%d\n",m);
	}
	flag=Pop(s,m);
	if(flag){
		printf("弹出元素%d",m);
	}
	return 0; 
}
