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
	queue<Location2D> locQueue; // Location2D ��ü �ڷ����� ť ����
	Location2D entry(1, 0); // �̷� ���� �κ��� Location2D ��ü�� ����
	locQueue.push(entry);

	while (locQueue.empty() == false) { // �̷��� ��� ������ Ž�� �Ϸ� �� �� ���� �ݺ�
		Location2D here = locQueue.front(); // �̷� Ž�� �κ��� ��ü�� ����
		locQueue.pop(); // Queue���� ertry ��ü ����

		int r = here.row;
		int c = here.col;
		printf("(%d,%d) ", r, c);
		if (map[r][c] == 'x') {
			printf("�̷� ����\n");
			return 0;
		}
		else {
			map[r][c] = '.';
			// �̷� ��Ž�� ������ locQueue�� ����.
			if (isValidLoc(r - 1, c)) locQueue.push(Location2D(r - 1, c)); 
			if (isValidLoc(r + 1, c)) locQueue.push(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1)) locQueue.push(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1)) locQueue.push(Location2D(r, c + 1));
		}
	}
	printf("�̷� Ž�� ����\n");
}
*/