#include "Location2D.h"
#include <queue>
/*
using namespace std;
const int MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};
bool isValidLoc(int r, int c) {
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] == 'x';
}

int main() {
	queue<Location2D> locQueue; // Location2D 객체 자료형의 큐 생성
	Location2D entry(1, 0); // 미로 시작 부분을 Location2D 객체로 생성
	locQueue.push(entry);

	while (locQueue.empty() == false) { // 미로의 모든 구간을 탐색 완료 할 때 까지 반복
		Location2D here = locQueue.front(); // 미로 탐색 부분을 객체로 생성
		locQueue.pop(); // Queue에서 ertry 객체 제거

		int r = here.row;
		int c = here.col;
		printf("(%d,%d) ", r, c);
		if (map[r][c] == 'x') {
			printf("미로 성공\n");
			return 0;
		}
		else {
			map[r][c] = '.';
			// 미로 미탐색 구역을 locQueue에 삽입.
			if (isValidLoc(r - 1, c)) locQueue.push(Location2D(r - 1, c)); 
			if (isValidLoc(r + 1, c)) locQueue.push(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1)) locQueue.push(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1)) locQueue.push(Location2D(r, c + 1));
		}
	}
	printf("미로 탐색 실패\n");
}
*/