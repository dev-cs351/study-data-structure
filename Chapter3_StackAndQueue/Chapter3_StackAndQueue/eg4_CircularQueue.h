#include <cstdlib>
#include <cstdio>
#define MAX_QUEUE_SIZE 100

inline void error(const char* message) {
	printf("%s\n", message);
	exit(1);
}

template <typename T>
class CircularQueue
{
private:
	int front, rear;
	T data[MAX_QUEUE_SIZE];
public:
	CircularQueue() { front = rear = 0; }
	~CircularQueue() {}
	bool isEmpty() {
		return front == rear;
	}
	bool isFull() {
		return (rear + 1) % MAX_QUEUE_SIZE == front;
	}
	void enqueue(T value) {
		if (isFull()) error("Queue is full\n");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = value;
		}
	}
	T dequeue() {
		if (isEmpty()) error("Queue is emptry\n");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}		
	}
	T peek() {
		if (isEmpty()) error("Queue is emptry\n");
		else
			return data[(front + 1) % MAX_QUEUE_SIZE];
	}
	void display() {
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		printf("Å¥ ³»¿ë :");
		for (int i = front + 1 ; i <= maxi ; i++)
			printf("[%2d]", data[i%MAX_QUEUE_SIZE]);
		printf("\n");
	}
};