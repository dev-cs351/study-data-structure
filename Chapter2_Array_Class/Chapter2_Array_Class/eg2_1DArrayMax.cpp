#include <cstdio>

int findMaxValue(int a[], int len) { // 배열의 주소만으로 크기를 알 수 없으므로 크기를 전달받는 인자가 반드시 필요하다.
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
	int maxVal = findMaxValue(arr, 10); // 배열의 주소와 크기 전달
	printf("%d\n", maxVal);
}
*/