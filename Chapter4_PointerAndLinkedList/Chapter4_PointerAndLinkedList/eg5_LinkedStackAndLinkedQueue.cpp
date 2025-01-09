#include "eg5_Node.h"

class LinkedStack {
	Node* top; // 헤드 포인터
public:
	LinkedStack() { top = NULL; }
	~LinkedStack() { while (!isEmpty()) delete pop(); } // delete pop() ??
	bool isEmpty(void) { return top == NULL; }
	void push(Node* p){
		if (isEmpty()) top = p;
		else {
			p->setLink(top); // p.setLink(top)
			top = p;
		}
	}
	Node* pop(void){
		if (isEmpty()) return NULL;
		Node* p = top;
		top = top->getLink();
		return p;
	}
	Node* peek(void){
		return top;
	}
	void display(void) {
		printf("[LinkedStack]\n");
		for (Node* p = top; p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}
};

class LinkedQueue {
	Node* front;
	Node* rear;
public:
	LinkedQueue(): front(NULL), rear(NULL) {}
	~LinkedQueue() { while (!isEmpty()) delete dequeue(); }
	bool isEmpty() { return front == NULL; }
	void enqueue(Node* p) {
		if (isEmpty()) front = rear = p;
		else {
			rear->setLink(p); // rear가 가르키는 노드가 p를 가르키도록 한다.
			rear = p; // rear가 p를 가르키도록 한다.
		}
	}
	Node* dequeue() {
		if (isEmpty()) return NULL;
		else {
			Node* p = front;
			front = front->getLink();
			if (front == NULL) rear = NULL;
			return p;
		}
	}
	Node* peek() { return front; }
	void display() {
		printf("[LinkedQueue]\n");
		for (Node* p = front; p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}
};

int main() {
	LinkedStack testStack;
	testStack.push(new Node(20191, "A"));
	testStack.push(new Node(20192, "B"));
	testStack.push(new Node(20193, "C"));
	testStack.display();

	Node* node = testStack.pop();
	printf("[pop 항목]\n");
	node->display();
	printf("\n");
	delete node;
	testStack.display();

	LinkedQueue testQueue;
	testQueue.enqueue(new Node(20191, "A"));
	testQueue.enqueue(new Node(20192, "B"));
	testQueue.enqueue(new Node(20193, "C"));
	testQueue.display();
	testQueue.dequeue();
	testQueue.dequeue();
	testQueue.display();
}