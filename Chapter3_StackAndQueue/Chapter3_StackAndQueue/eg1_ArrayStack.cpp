#include <cstdio>
#include <cstdlib>

// inline: 함수 작동시 컴파일 과정에서 함수를 저장하고 불러들이는 과정을 해당 부분을 함수 내 코드로 치환하여 작동시키는 함수.
// 메모리에 error 함수 저장, 호출 -> error 함수 호출 부분이 컴파일 과정에서 함수 내 코드로 치환됨.
inline void error(const char* message) { // const char* message <==> const char message[]
	printf("%s\n", message);
	exit(1); // 프로그램 종료
}

/*
	const char* message(혹은, const char message[])는 데이터가 저장된 메모리 시작 주소로 가서
	시작 주소부터 널 문자(\n) 까지의 크기로 문자열의 크기를 알아낸다.

	따라서 널 문자가 없을 경우 런 오버 에러가 발생할 수 있으므로,
	널 문자를 반드시 넣도록 하거나 매개변수를 통해 문자열 크기를 알려줘야 안전하다.
*/

// const char* message: 포인터로 가리키는 데이터를 수정할 수 있다.
// char* message: 포인터로 가리키는 데이터를 수정할 수 없다.

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
		printf("[스택 항목의 수 = %d] ==> ", top + 1);
		for (int i = 0; i <= top; i++)
			printf("<%d>", arr[i]);
		printf("\n");
	}
};

// eg3 테스트용 더미 주석
// (((((((((((((((((
/*[[[[[[[[
	{{{{{{{{{{{{{{{{{{
*/