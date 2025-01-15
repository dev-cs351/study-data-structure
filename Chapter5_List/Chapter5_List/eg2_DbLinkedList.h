#include "eg2_Node2.h"
class DbLinkedList {
	Node2 org; // 헤드 노드
public:
	DbLinkedList(): org(0) {}
	~DbLinkedList() { while (!isEmpty()) delete remove(0); }
	Node2* getHead() { return org.getNext(); }
	bool isEmpty() { return getHead() == NULL; }

	Node2* getEntry(int pos) { // pos 번째 노드 반환
		Node2* n = &org; // 헤드 노드 부터 시작
		for (int i = 0; i < pos; i++, n = n->getNext()) // pos 번째 노드까지 이동
			if (n == NULL) break;
		return n;
	}
	void insert(int pos, Node2* n) { // a, c -> a, n, c
		Node2* prev = getEntry(pos - 1); // a
		if (prev != NULL)
			prev->insertNext(n); // a.insertNext(n) => a, n, c
	}
	Node2* remove(int pos) {
		Node2* n = getEntry(pos); // pos번째 노드 n
		return n->remove(); // n.remove()
	}
	Node2* find(int val) {
		for (Node2* p = getHead(); p != NULL; p = p->getNext())
			if (p->hasData(val)) return p;
		return NULL;
	}
	void replace(int pos, Node2* n) { // a, b -> a, n 
		Node2* prev = getEntry(pos - 1); // a
		if (prev != NULL) {
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
		Node2* p = getHead();
		if(p!=NULL)
			p->remove();
	}
	void display() {
		printf("[이중 연결 리스트 항목 수 = %2d] : ", size());
		for (Node2* p = getHead(); p != NULL; p = p->getNext())
			p->display(); // Node2 클래스의 display()
		printf("\n");
	}
};