#include <cstdio>
// int x를 매개변수로 받으면 입력된 변수에 저장된 값을 복사한 값이 전달된다.
// 반면에, int& x를 매개변수로 받으면 입력된 변수가 저장된 메모리 주소를 복사한 값이 전달된다.
void swap(int& x, int& y) { 
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}
/*
int main() {
	int a = 1, b = 2;
	printf("호출전: %d %d\n", a, b);
	swap(a, b);
	printf("호출후: %d %d\n", a, b);
}
*/