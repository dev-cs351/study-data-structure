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