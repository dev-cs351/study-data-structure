#include "eg2_Node2.h"
class DbLinkedList {
	Node2 org; // ��� ���
public:
	DbLinkedList(): org(0) {}
	~DbLinkedList() { while (!isEmpty()) delete remove(0); }
	Node2* getHead() { return org.getNext(); }
	bool isEmpty() { return getHead() == NULL; }

	Node2* getEntry(int pos) { // pos ��° ��� ��ȯ
		Node2* n = &org; // ��� ��� ���� ����

		// for (int i = 0; i < pos; i++, n = n->getNext()) ���� ��ȣ �ϳ� �߰�. ��ȣ�� ���� �� ������ �� �����?
		for (int i = 0; i <= pos; i++, n = n->getNext()) // pos ��° ������ �̵�
			if (n == NULL) break;
		return n;
	}
	void insert(int pos, Node2* n) { // a, c -> a, n, c
		Node2* prev = getEntry(pos - 1); // a
		if (prev != NULL)
			prev->insertNext(n); // a.insertNext(n) => a, n, c
	}
	Node2* remove(int pos) {
		Node2* n = getEntry(pos); // pos��° ��� n
		return n->remove(); // n.remove()
	}
	Node2* find(int val) {
		for (Node2* p = getHead(); p != NULL; p = p->getNext())
			if (p->hasData(val)) return p;
		return NULL;
	}
	void replace(int pos, Node2* n) { // a, b -> a, n 
		Node2* prev = getEntry(pos - 1); // a
		if (prev != NULL && prev->getNext() != NULL) {
			delete prev->getNext()->remove(); // a.next.remove() => b.remove()
			prev->insertNext(n); // a.insertNext(n)
		}
	}
	int size() {
		int count = 0;
		for (Node2* p = getHead(); p != NULL; p = p->getNext())
			count++;
		return count;
	}
	void clear() {
		for (Node2* p = getHead(); p != NULL; p = p->getNext())
			p->remove();
	}
	void display() {
		printf("[���� ���� ����Ʈ �׸� �� = %2d] : ", size());
		for (Node2* p = getHead(); p != NULL; p = p->getNext())
			p->display(); // Node2 Ŭ������ display()
		printf("\n");
	}
};