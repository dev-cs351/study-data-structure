#include <cstdio>
#include <cstdlib>

// int형 2차원 배열 동적 할당 함수
int** alloc2DInt(int rows, int cols) {
	if (rows <= 0 || cols <= 0) return NULL;
	int** mat = new int* [rows]; // 포인터 변수를 저장할 배열 (이중 포인터에 선언)
	for (int i = 0; i < rows; i++)
		mat[i] = new int[cols]; // 실제 각 행의 데이터를 저장할 배열을 이중 포인터에 삽입
	return mat;
}

// int형 2차원 배열 동적 해제 함수
void free2DInt(int** mat, int rows, int cols = 0) {
	if (mat != NULL) {
		for (int i = 0; i < rows; i++)
			delete[] mat[i]; // 이중 포인터에 저장된 포인터 배열의 메모리 반환
		delete[] mat; // 이중 포인터 메모리 반환
	}
}

// 동적으로 생성된 2차원 배열을 랜덤으로 초기화 하는 함수
void set2DRandom(int** mat, int rows, int cols) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			mat[i][j] = rand() % 100;
}

// 2차원 배열을 화면에 출력하는 함수
void print2DInt(int** mat, int rows, int cols) {
	printf("행의 수 = %d, 열의 수 = %d\n", rows, cols);
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++)
			printf("%4d", mat[i][j]);
		printf("\n");
	}
	printf("\n");
}
/*
int main() {
	int** mat;
	int rows, cols;

	printf("행과 열의 크기를 입력하세요.");
	scanf_s("%d%d", &rows, &cols); // scanf: 변수에 할당된 메모리에 해당 값을 저장.

	mat = alloc2DInt(rows, cols);
	set2DRandom(mat, rows, cols);
	print2DInt(mat, rows, cols);
	free2DInt(mat, rows, cols);
	// print2DInt(mat, rows, cols); // 엑세스 위반. 어느 메모리 구역을 출력하는지 알 수 없고, 보안적으로 위험함.
}
*/