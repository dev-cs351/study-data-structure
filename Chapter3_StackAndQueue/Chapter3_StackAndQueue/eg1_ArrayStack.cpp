#include <cstdio>
#include <cstdlib>

// inline: �Լ� �۵��� ������ �������� �Լ��� �����ϰ� �ҷ����̴� ������ �ش� �κ��� �Լ� �� �ڵ�� ġȯ�Ͽ� �۵���Ű�� �Լ�.
// �޸𸮿� error �Լ� ����, ȣ�� -> error �Լ� ȣ�� �κ��� ������ �������� �Լ� �� �ڵ�� ġȯ��.
inline void error(const char* message) { // const char* message <==> const char message[]
	printf("%s\n", message);
	exit(1); // ���α׷� ����
}

/*
	const char* message(Ȥ��, const char message[])�� �����Ͱ� ����� �޸� ���� �ּҷ� ����
	���� �ּҺ��� �� ����(\n) ������ ũ��� ���ڿ��� ũ�⸦ �˾Ƴ���.

	���� �� ���ڰ� ���� ��� �� ���� ������ �߻��� �� �����Ƿ�,
	�� ���ڸ� �ݵ�� �ֵ��� �ϰų� �Ű������� ���� ���ڿ� ũ�⸦ �˷���� �����ϴ�.
*/

// const char* message: �����ͷ� ����Ű�� �����͸� ������ �� �ִ�.
// char* message: �����ͷ� ����Ű�� �����͸� ������ �� ����.

const int MAX_STACK_SIZE = 20;

template <typename T> 
class ArrayStack
{
private:
	int top;
	T arr[MAX_STACK_SIZE]; // int arr[MAX_STACK_SIZE];
public:
	ArrayStack() { 
		top = -1;
		arr[0] = 0;
	}
	~ArrayStack(){}

	bool isEmpty() {
		return top == -1;
	}
	bool isFull() {
		return top == MAX_STACK_SIZE - 1;
	}

	void push(T value) { // push(int e)
		if (isFull()) error("Stack is full");
		arr[++top] = value; // arr[++top] = e;
	}
	int pop() {
		if (isEmpty()) error("Stack is empty");
		return arr[top--];
	}
	int peek() {
		if (isEmpty()) error("Stack is empty");
		return arr[top];
	}
	void display() {
		printf("[���� �׸��� �� = %d] ==> ", top + 1);
		for (int i = 0; i <= top; i++)
			printf("<%d>", arr[i]);
		printf("\n");
	}
};

// eg3 �׽�Ʈ�� ���� �ּ�
// (((((((((((((((((
/*[[[[[[[[
	{{{{{{{{{{{{{{{{{{
*/