#include <iostream>
#include"SqStack.h"

Status initStack(SqStack* s, int sizes) 
{
	if (sizes == 0) {
		std::cout << "\n不能定义长度为0的栈\n";
		return ERROR;
	}
	s->size = sizes;
	s->top = -1;
	s->elem = new int[sizes];
	return SUCCESS;
}

Status isEmptyStack(SqStack* s)
{
	if (s->top == -1) {
		std::cout << "\n没有栈头\n";
		return ERROR;
	}
	else {
		std::cout << "\n有栈头\n";
		return SUCCESS;
	}
}
Status getTopStack(SqStack* s, ElemType* e) 
{
	if (s->top == -1) {
		std::cout << "\n没有栈头\n";
		return ERROR;
	}
	*e = s->elem[s->top];
	return SUCCESS;
	
}

Status clearStack(SqStack* s)
{
	for (int i = 0; i < s->size; i++)
	{
		s->elem[i] = 0;
	}
	s->top = -1;
	return SUCCESS;
}

Status destroyStack(SqStack* s) {
	delete []s->elem;
	s->top = -1;
	s->size = 0;
	std::cout << "已销毁\n";
	return SUCCESS;
}

Status stackLength(SqStack* s, int* length)
{
	*length = s->size;
	return SUCCESS;
}

Status pushStack(SqStack* s, ElemType data) {
	if (s->top != s->size)
	{
		s->elem[s->top + 1] = data;
		s->top++;
		return SUCCESS;
	}
	else {
		std::cout << "\n栈已经满了\n";
		return ERROR;
	}
}

Status popStack(SqStack* s, ElemType* data) {
	if (s->top == -1) {
		std::cout << "\n没有栈头\n";
		return ERROR;
	}
	*data = s->elem[s->top];
	s->elem[s->top] = 0;
	s->top--;
	return SUCCESS;
}