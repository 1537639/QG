#include <iostream>
#include"LinkStack.h"

Status initLStack(LinkStack* s) 
{
	s->top = new StackNode;
	s->top = NULL;
	s->count = 0;
	std::cout << "\n创建成功\n";
	return SUCCESS;
}

Status isEmptyLStack(LinkStack* s)
{
	if (s->count == 0) {
		std::cout << "\n栈为空\n";
		return SUCCESS;
	}
	else {
		std::cout << "\n栈不为空\n";
		return ERROR;
	}

}

Status getTopLStack(LinkStack* s, ElemType* e) 
{
	if (s->count == 0) {
		std::cout << "\n栈为空\n";
		return ERROR;
	}
	else {
		*e = s->top->data;
		return SUCCESS;
	}
}

Status destroyLStack(LinkStack* s) 
{
		StackNode* p = s->top;
		while (p) {
			StackNode* q = p->next;
			delete p;
			p = q;
		}
		s->count = 0;
		std::cout << "\n栈已销毁\n";
		return SUCCESS; 
	
}

Status clearLStack(LinkStack* s) 
{

	if (s->top != NULL)
	{
		StackNode* p = s->top;
		while (p) {
			StackNode* q = p->next;
			delete p;
			p = q;
		}
		s->top = NULL;
		s->count = 0;
		std::cout << "\n栈已清空\n";
		return SUCCESS;
	}
	else {
		return ERROR;
	}
}

Status LStackLength(LinkStack* s, int* length)
{
	*length = s->count;
	return SUCCESS;
}

Status pushLStack(LinkStack* s, ElemType data)
{
	StackNode* p = new StackNode;
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack* s, ElemType* data)
{
	if (s->top != NULL)
	{
		*data = s->top->data;
		s->top = s->top->next;
		s->count--;
		return SUCCESS;
	}
	else
	{
		std::cout << "\n栈里没有元素\n"; return ERROR;
	}
}