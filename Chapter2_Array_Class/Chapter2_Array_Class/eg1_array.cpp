#include <cstdio> // 파일, 콘솔 입출력 라이브러리
#define MAX_SIZE 10

void sub(int x, int arr[]) {
	x = 10; 
	arr[0] = 10; // 배열이 저장된 메모리에 해당 상수 저장
}
/*
void main() {
	int var;
	int list[MAX_SIZE];

	var = 0;
	list[0] = 0;
	sub(var, list); // var: 변수에 저장된 값을 복사하여 전달. list: 해당 리스트가 저장된 메모리 주소 전달.

	printf("var=%d, list[0]=%d\n", var, list[0]);
}
*/