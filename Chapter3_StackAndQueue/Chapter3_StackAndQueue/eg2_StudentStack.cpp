#include <cstdio>
#include <cstdlib>
#include <cstring>

inline void error(const char* message) {
	printf("%s\n", message);
	exit(1); 
}

const int MAX_STACK_SIZE = 20;
const int MAX_STRING = 10;

class Student
{
private:
	int id;
	char name[MAX_STRING];
public:
	Student(int i=0, const char* n="�ƹ���") {
		set(i, n);
	}
	~Student() {}
	void set(int i, const char* n){
		id = i;
		strcpy_s(name, n);
	}
	void display() {
		printf("�й�: %d, �̸�:%-10s", id, name);
	}
};

class StudentStack
{
private:
	int top;
	Student arr[MAX_STACK_SIZE];
public:
	StudentStack() {
		top = -1;
		arr[0] = Student(); //  Student(): �ӽð�ü, �迭�� ���簡 �� �� �ٷ� �Ҹ�ȴ�.
	}
	~StudentStack() {}

	bool isEmpty() {
		return top == -1;
	}
	bool isFull() {
		return top == MAX_STACK_SIZE - 1;
	}

	void push(Student e) {
		if (isFull()) error("Stack is full");
		arr[++top] = e;
	}
	Student pop() {
		if (isEmpty()) error("Stack is empty");
		return arr[top--];
	}
	Student peek() {
		if (isEmpty()) error("Stack is empty");
		return arr[top];
	}
	void display() {
		printf("[���� �׸��� �� = %d] ==> ", top + 1);
		for (int i = 0; i <= top; i++)
			arr[i].display();
		printf("\n");
	}
};