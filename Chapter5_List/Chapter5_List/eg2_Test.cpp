#include "eg2_DbLinkedList.h"
int main() {
	DbLinkedList list;
	list.insert(0, new Node2(10));
	list.insert(0, new Node2(20));
	list.insert(1, new Node2(30));
	list.insert(list.size(), new Node2(40));
	list.insert(2, new Node2(50));
	list.display();
	list.remove(2);
	list.remove(list.size() - 1);
	list.remove(0);
	list.replace(1, new Node2(90));
	list.display();
	list.clear();
	list.display();
}

// ���� ����

// delete_scalar.cpp ??