#include "eg5_CircularDeque.h"

int main() {
	CircularDeque<int> deque;
	for (int i = 0; i < 10; i++)
		deque.addFront(i);
	deque.display();
	deque.deleteFront();
	deque.deleteFront();
	deque.deleteRear();
	deque.deleteRear();
	deque.deleteRear();
	deque.display();
}