#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];//���� 
	int top;//ָ��ջ���ı��� 
}SqStack;
void InitStack(SqStack &s){
	s.top = -1;//ջΪ��
}

bool StackEmpty(SqStack &s){
	if(-1==s.top){
		return true;
	}else{
		return false;
	}
}

bool Push(SqStack &s,ElemType e){
	//�ж�ջ�Ƿ���
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
		printf("�ҵ�Ԫ��%d\n",m);
	}
	flag=Pop(s,m);
	if(flag){
		printf("����Ԫ��%d",m);
	}
	return 0; 
}
