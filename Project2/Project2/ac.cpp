#include <iostream>
#include "qglist.h"

typedef int ElemType;

QGList::QGList() {
	head = new Node;
	head->next = NULL;
	head->prior = NULL;
}

QGList::~QGList() {
	Node* p = head;
	while (p) {
		Node* q = p->next;
		delete p;
		p = q;
	}
}

bool QGList::clear() {
	Node* p = head->next;
	while (p) {
		Node* q = p->next;
		delete p;
		p = q;
	}
	head->next = NULL;
	return 0;
}

ElemType& QGList::front() {
	if (head->next != NULL) {
		QGList::ElemType& a = QGList::head->next->data;
		return a;
	}
	else
	{
		int q = 0; ElemType& b = q;
		return b;
	}
}

ElemType& QGList::back() {
	Node* p;
	p = head->next;
	if (head->next != NULL) {
		while (p->next) {
			p = p->next;
		}
		ElemType& a = p->data;
		return a;
	}
	else
	{
		int q = 0; ElemType& b = q;
		return b;
	}
}

bool QGList::push_front(ElemType& e) {
	Node* p = new Node;
	p->data = e;
	p->next = head->next;
	head->next = p;
	p->prior = head;
	return 0;
}

bool QGList::pop_front() {
	Node* p = head->next;
	if (head->next != NULL) {
		head->next = head->next->next;
		delete p;
		head->next->prior = head->next;
		return 0;
	}
	else
		return 0;
}

bool QGList::pop_back() {
	Node* p = head;
	if (head->next != NULL) {
		while (p->next->next) {
			p = p->next;
		}
		Node* q = p;
		delete p->next;
		q->next = NULL;
		return 0;
	}
	else
		return 0;

}

bool QGList::insert(unsigned int index, ElemType& e) {
	Node* p = new Node;
	p->data = e;
	tail = head->next;

	for (int i = 1; i < index; i++) {
		tail = tail->next;
	}

	p->next = tail->next;
	p->prior = tail;
	tail->next->prior = p;
	tail->next = p;
	return 0;
}

bool QGList::erase(unsigned int index) {
	tail = head->next;
	if (index == 1) {
		if (head->next) {
			head->next = head->next->next;
			delete tail;
			return 1;
		}
		else
			return 0;
	}
	else {
		for (int i = 1; i < index - 1; i++) {
			tail = tail->next;
			if (!(tail->next))
				return 0;
		}
		tail->next = tail->next->next;
		tail->next->prior = tail;
		return 1;
	}
}

bool QGList::contain(ElemType& e) {
	tail = head->next;
	while (tail) {
		if (tail->data == e)
			return 1;
		tail = tail->next;
	}
	return 0;
}

unsigned int QGList::size() {
	tail = head->next;
	if (head->next) {
		unsigned int i;
		for (i = 1; tail->next; i++) {
			tail = tail->next;
		}
		return i;
	}
	else
		return 0;
}

bool  QGList::traverse(void (*visit)(ElemType& e)) {
	tail = head->next;
	while (tail)
	{
		(*visit)(tail->data);
		tail = tail->next;
	}
	return 0;
}

bool QGList::push_back(ElemType& e) {

	Node* p = new Node;
	p->data = e;
	tail = head;
	while (tail->next) {
		tail = tail->next;
	}
	tail->next = p;
	p->next = NULL;
	p->prior = tail;
	return 0;
}