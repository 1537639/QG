#include <iostream>
#include "qg.h"

typedef int ElemType;
	QGForwardList::QGForwardList() {
		head = new Node;
		head->next = NULL;
	}

	QGForwardList::~QGForwardList(){
		Node* p = head;
		while (p) {
			Node* q = p->next;
			delete p;
			p = q;
		}
	}
	
	ElemType& QGForwardList::front() {
		if (head->next != NULL) {
			QGForwardList::ElemType& a = QGForwardList::head->next->data;
			return a;
		}
		else
		{
			int q = 0; ElemType& b = q;
			return b;
		}
	}

	ElemType& QGForwardList::back() {
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

	bool QGForwardList::push_front(ElemType& e) {
		Node* p = new Node;
		p->data = e;
		p->next = head->next;
		head->next = p;
		return 0;
	}

	bool QGForwardList::pop_front() {
		Node* p = head->next;
		if (head->next != NULL) {
			head->next = head->next->next;
			delete p;
			return 0;
		}
		else
			return 0;
	}

	bool QGForwardList::pop_back() {
		Node* p=head;
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

	bool QGForwardList::insert(unsigned int index, ElemType& e) {
		Node* p = new Node;
		p->data = e;
		tail = head->next;
		
		for (int i = 1; i < index; i++) {
			if (tail) {
				tail = tail->next;
			}
			else
				return 0;
		}

		p->next = tail->next;
		tail->next = p;
		return 0;
	}

	bool QGForwardList::erase(unsigned int index) {
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
			for (int i = 1; i < index-1; i++) {
				tail = tail->next;
				if (!(tail->next))
					return 0;
			}
			tail->next = tail->next->next;
			return 1;
		}
	}

	bool QGForwardList::clear() {
		Node* p = head->next;
		while (p) {
			Node* q = p->next;
			delete p;
			p = q;
		}
		head->next = NULL;
		return 0;
	}

	bool QGForwardList::contain(ElemType& e) {
		tail = head->next;
		while (tail) {
			if (tail->data == e)
				return 1;
			tail = tail->next;
		}
		return 0;
	}

	unsigned int QGForwardList::size() {
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

	bool  QGForwardList::traverse(void (*visit)(ElemType& e)) {
		tail = head->next;
		while (tail)
		{
			(*visit)(tail->data);
			tail = tail->next;
		}
		return 0;
	}

	bool  QGForwardList::reverse() {//·ÇµÝ¹éËã·¨
		Node* pre = head->next;
		if (head->next) {
			Node* cur = head->next->next;
			pre->next = NULL;

			while (cur) {
				tail = cur->next;
				cur->next = pre;
				pre = cur;
				cur = tail;
			}
			cur = new Node;
			head = cur;
			head->next = pre;
			return 0;
		}
	}

	bool  QGForwardList::isLoop() {
		Node* fast, * slow;
		fast = head->next;
		slow = head;
		if (head->next) {
			while (!(fast == slow)) {
				fast = fast->next->next;
				slow = slow->next;
				if (fast == NULL) return 0;
			}
		}
		return 1;
	}

	ElemType& QGForwardList::middleElem() {
		Node* fast, * slow;
		
		fast = slow = head->next;
		if (head->next) {
			while (fast->next) {
				fast = fast->next->next;
				slow = slow->next;
			}
		}

		if (head->next)
		{
			ElemType& a = slow->data; return a;
		}
		else
		{
			int q = 0; ElemType& b = q;
			return b;
		}
	}
	
	bool  QGForwardList::reverseEven() {
		Node* pre = head;
		Node* cur = head->next;
		while (cur) {
			tail = cur->next;
			cur->next = pre;
			pre->next = tail->next;
			pre = tail;
			if (pre == NULL) {
				return 0;
			}
			cur = tail->next;
		}
		return 0;
	}
		
	bool QGForwardList::push_back(ElemType& e) {
		
		Node* p = new Node;
		p->data = e;
		tail = head;
		while (tail->next) {
			tail = tail->next;
		}
		tail->next = p;
		p->next = NULL;
		return 0;
	}
	
	

