#include <cstdio>

// (열) 크기가 5인 배열(자료형)의 메모리 주소 전달. 메모리 할당에 필요한 요소.
int findMaxPixel(int a[][5], int h, int w) { 
	int maxVal = 0;
	for(int i=0 ; i<h ; i++)
		for (int j = 0; j < w; j++) {
			if (maxVal < a[i][j])
				maxVal = a[i][j];
		}
	return maxVal;
}
/*
void main() {
	int img[4][5] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{22, 21, 21, 21, 14}
	};
	int maxVal = findMaxPixel(img, 4, 5);
	printf("%d\n", maxVal);
}
*/