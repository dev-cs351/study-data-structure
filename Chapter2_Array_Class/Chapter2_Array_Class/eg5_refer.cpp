#include <cstdio>
// int x�� �Ű������� ������ �Էµ� ������ ����� ���� ������ ���� ���޵ȴ�.
// �ݸ鿡, int& x�� �Ű������� ������ �Էµ� ������ ����� �޸� �ּҸ� ������ ���� ���޵ȴ�.
void swap(int& x, int& y) { 
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}
/*
int main() {
	int a = 1, b = 2;
	printf("ȣ����: %d %d\n", a, b);
	swap(a, b);
	printf("ȣ����: %d %d\n", a, b);
}
*/