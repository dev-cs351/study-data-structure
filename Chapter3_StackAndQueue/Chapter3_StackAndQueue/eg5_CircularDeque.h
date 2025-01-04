#include "eg4_CircularQueue.h"

template <typename T>
class CircularDeque : public CircularQueue<T> {
public:
	CircularDeque() {}
	void addFront(T value) {
		if (this->isFull()) error("Deque is full\n");
		else {
			this->data[this->front] = value;
			this->front = (this->front + MAX_QUEUE_SIZE - 1) % MAX_QUEUE_SIZE;
		}
	}
	T deleteFront() {
		return this->dequeue();
	}
	T getFront() {
		return this->peek();
	}
	void addRear(T value) {
		return this->enqueue(value);
	}
	T deleteRear() {
		if (this->isEmpty()) error("Deque is empty\n");
		int tmp = this->rear;
		this->rear = (this->rear + MAX_QUEUE_SIZE - 1) % MAX_QUEUE_SIZE;
		return this->data[tmp];
		
	}
	T getRear() {
		if (this->isEmpty()) error("Deque is empty\n");
		return this->data[this->rear];
	}
	void display() {
		int maxi = (this->front < this->rear) ? this->rear : this->rear + MAX_QUEUE_SIZE;
		printf("덱 내용 :");
		for (int i = this->front + 1; i <= maxi; i++)
			printf("[%2d]", this->data[i % MAX_QUEUE_SIZE]);
		printf("\n");
	}
};

/*
this 포인터는 현재 클래스의 객체를 가리키고, 
그 객체는 부모 클래스의 멤버를 포함하고 있기 때문에, 
this를 사용하면 부모 클래스의 protected 멤버 변수에도 접근할 수 있다.
*/