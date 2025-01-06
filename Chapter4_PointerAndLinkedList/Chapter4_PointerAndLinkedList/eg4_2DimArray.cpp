#include <cstdio>
#include <cstdlib>

// int�� 2���� �迭 ���� �Ҵ� �Լ�
int** alloc2DInt(int rows, int cols) {
	if (rows <= 0 || cols <= 0) return NULL;
	int** mat = new int* [rows]; // ������ ������ ������ �迭 (���� �����Ϳ� ����)
	for (int i = 0; i < rows; i++)
		mat[i] = new int[cols]; // ���� �� ���� �����͸� ������ �迭�� ���� �����Ϳ� ����
	return mat;
}

// int�� 2���� �迭 ���� ���� �Լ�
void free2DInt(int** mat, int rows, int cols = 0) {
	if (mat != NULL) {
		for (int i = 0; i < rows; i++)
			delete[] mat[i]; // ���� �����Ϳ� ����� ������ �迭�� �޸� ��ȯ
		delete[] mat; // ���� ������ �޸� ��ȯ
	}
}

// �������� ������ 2���� �迭�� �������� �ʱ�ȭ �ϴ� �Լ�
void set2DRandom(int** mat, int rows, int cols) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			mat[i][j] = rand() % 100;
}

// 2���� �迭�� ȭ�鿡 ����ϴ� �Լ�
void print2DInt(int** mat, int rows, int cols) {
	printf("���� �� = %d, ���� �� = %d\n", rows, cols);
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

	printf("��� ���� ũ�⸦ �Է��ϼ���.");
	scanf_s("%d%d", &rows, &cols); // scanf: ������ �Ҵ�� �޸𸮿� �ش� ���� ����.

	mat = alloc2DInt(rows, cols);
	set2DRandom(mat, rows, cols);
	print2DInt(mat, rows, cols);
	free2DInt(mat, rows, cols);
	// print2DInt(mat, rows, cols); // ������ ����. ��� �޸� ������ ����ϴ��� �� �� ����, ���������� ������.
}
*/