#include <cstdio>

struct NewType {
	int i;
	float f;
};

void foo(int a) {
	printf("foo: %d\n", a);
}

int main() {
	NewType s, * ps;
	ps = &s; // 객체 s의 주소를 가리키는 객체 포인터 ps
	ps->i = 2; // 포인터가 가르키는 객체의 변수 i에 2 대입
	ps->f = 3.14f; // 포인터가 가르키는 객체의 변수 f에 3.14f 대입

	printf("%d, %f\n", s.i, s.f); // 객체 s의 변수 i와 f
	printf("%d, %f\n", ps->i, ps->f); // 포인터가 가르키는 객체의 변수 i와 f
	printf("%d, %f\n", (*ps).i, (*ps).f); // 포인터가 가르키는 객체의 변수 i와 f

	void (*k)(int); // int형 자료형을 저장하는 객체의 포인터 선언 (객체를 초기화 하지 않은 상태)
	k = foo; // 객체 포인터 k를 함수 foo로 초기화
	foo(1); // 객체(함수)에 1 삽입
	k(10); // 포인터가 가르키는 객체에 10 삽입(함수 파라미터에 10 삽입)
	(*k)(100); // 포인터가 가르키는 객체에 10 삽입(함수 파라미터에 100 삽입)
}