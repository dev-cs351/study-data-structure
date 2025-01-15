#include "eg1_ArrayList.h"
int main() {
	ArrayList list;

	list.display(); // 
	list.insert(0, 10); // 10
	list.display();
	list.insert(0, 20); // 20 10
	list.insert(1, 30); // 20 30 10
	list.insert(list.size(), 40); // 20 30 10 40
	list.insert(2, 50); // 20 30 50 10 40
	list.display();

	list.remove(2); // 20 30 10 40
	list.remove(list.size() - 1); // 20 30 40
	list.remove(0); // 30 40
	list.replace(1, 90); // 30 90
	list.display();

	list.clear(); // 
	list.display();

}