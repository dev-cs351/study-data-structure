#include <cstdio>

int findMaxValue(int a[], int len) { // �迭�� �ּҸ����� ũ�⸦ �� �� �����Ƿ� ũ�⸦ ���޹޴� ���ڰ� �ݵ�� �ʿ��ϴ�.
	int maxVal = a[0];
	for (int i = 1; i < len; i++) {
		if (maxVal < a[i])
			maxVal = a[i];
	}
	return maxVal;
}
/*
void main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int maxVal = findMaxValue(arr, 10); // �迭�� �ּҿ� ũ�� ����
	printf("%d\n", maxVal);
}
*/