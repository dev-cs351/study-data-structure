#include <cstdio>

void swap(int* px, int* py) {
	int tmp;
	tmp = *px;
	*px = *py;
	*py = tmp;
}
/*
void main() {
	int a = 1, b = 2;
	printf("%d, %d\n", a, b);
	swap(&a, &b);
	printf("%d, %d\n", a, b);
}
*/
// 변수의 포인터를 매개변수로 받는 함수 swap
// 값을 반환하는 함수가 아니고, 실제 메모리에 저장된 변수 값을 바꿔준다.
// 이렇게 포인터를 매개변수로 받는 경우 매개변수에 저장된 값을 복사하는 과정이 없어 오버헤드를 줄일 수 있다.