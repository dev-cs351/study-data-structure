#include <cstdio>

int main(void) {
	char* str; // 포인터 변수 str 선언
	int size = 1000;
	str = new char[size]; // 연산자 new를 사용하여 포인터 변수에 1차원 배열을 동적으로 할당
	if (str == NULL)
		printf("Insufficient memory available\n");
	else {
		printf("Allocated 1000 bytes\n");
		printf("%d\n", str); // 포인터 변수에 할당된 1차원 배열의 메모리 주소 출력
		printf("%d\n", &str); // 포인터 변수의 메모리 주소 출력
		
		delete[] str; // 연산자 delete를 사용하여 할당되었던 메모리 반납
		
		printf("Memory freed\n");
		printf("%d\n", str);  // '33059'로 일정한 주소가 출력됨. 
							  // 메모리가 반납된 후 포인터 변수가 가르키는 객체가 초기화 되는 주소가 있을 것으로 보임.
		printf("%d\n", &str); // 12행과 동일한 주소가 출력됨.
	}
}