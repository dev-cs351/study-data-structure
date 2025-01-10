#include <cstdio>
#include <cstdlib>
#include <cstring>

inline void error(const char* message) {
	printf("%s\n", message);
	exit(1);
}

struct Location2D {
	int row, col;
	// 생성자
	Location2D(int r = 0, int c = 0) { row = r; col = c; }
	// 객체 주변
	bool isNeighbor(Location2D& p) {
		return((row == p.row && (col == p.col - 1 || col == p.col + 1))
			|| (col == p.col && (row == p.row - 1 || row == p.row + 1)));
	}
	bool operator==(Location2D& p) { return row == p.row && col == p.col; }
};

class Maze {
	int width, height;
	int** map;
	Location2D exitLoc;
public:
	Maze() { init(0, 0); }
	~Maze() { reset(); }
	void init(int w, int h) { 
		reset();
		width = w;
		height = h;
		if (w > 0 && h > 0) {
			map = new int* [h];
			for (int i = 0; i < h; i++)
				map[i] = new int[w];
		}
	}
	void reset() { 
		if (map != nullptr){
			for (int i = 0; i < height; i++)
				delete[] map[i];
			delete[] map;
			map = nullptr;
		}
		width = height = 0;
	}
	void load(const char* fname) {
		FILE* fp = nullptr;
		errno_t err = fopen_s(&fp, fname, "r");
		if (err != 0 || fp == nullptr) {
			error("Error: 파일이 존재하지 않습니다.\n");
		}

		Location2D startLoc, exitLoc;

		// 파일에서 크기 정보 읽기
		if (fscanf_s(fp, "%d %d", &width, &height) != 2 || width <= 0 || height <= 0) {
			fclose(fp);
			error("Error: 잘못된 맵 크기\n");
		}

		printf("파일 크기: width = %d, height = %d\n", width, height);

		// 맵 초기화
		init(width, height);

		// 맵 데이터 읽기
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (fscanf_s(fp, "%d", &map[i][j]) != 1) {
					fclose(fp);
					reset(); // 메모리 해제
					error("Error: 잘못된 파일 데이터\n");
				}
				if (map[i][j] == 5)
					startLoc = Location2D(i, j);
				if (map[i][j] == 9)
					exitLoc = Location2D(i, j);
			}
		}

		fclose(fp);
	}
	void print() {
		if (map = nullptr) {
			error("Error: 맵이 초기화되지 않았습니다.\n");
			return;
		}
		for (int i = 0; i < height; i++){
			for (int j = 0; j < width; j++){
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
	}
};