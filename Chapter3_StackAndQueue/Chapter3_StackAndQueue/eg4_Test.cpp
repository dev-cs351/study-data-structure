#include "eg4_CircularQueue.h"

int main(){
	CircularQueue<int> que;
	for (int i = 1; i < 10; i++)
		que.enqueue(i);
	que.display();
	que.dequeue();
	que.dequeue();
	que.peek();
	que.display();
}