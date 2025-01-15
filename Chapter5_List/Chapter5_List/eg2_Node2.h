#include <cstdio>

class Node2 {
	Node2* prev;
	Node2* next;
	int data;
public:
	Node2(int val=0) : data(val), prev(NULL), next(NULL) {}
	Node2* getPrev() { return prev; }
	Node2* getNext() { return next; }
	void setPrev(Node2* p) { prev = p; }
	void setNext(Node2* n) { prev = n; }
	void display() { printf("<%2d>", data); }
	bool hasData(int val) { return data == val; }
	void insertNext(Node2* n) { // a, c -> a, n, c
		if (n != NULL) { 
			n->prev = this; // n.prev = a
			n->next = next; // n.next = a.next => n.next = c
			if (next != NULL) next->prev = n; // if(a.next = c !=NULL) a.next.prev = n => c.prev = n
			next = n; //a.next = n
		}
	}
	Node2* remove() { // a, r, b
		if (prev != NULL) prev->next = next; // r.prev.next = r.next => a.next = b
		if (next != NULL) next->prev = prev; // r.next.prev = r. prev => b.prev = a
		return this; // return r
	}
};
