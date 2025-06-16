struct Location2D {
	int row;
	int col;
	Location2D(int r = 0, int c = 0) { row = r; col = c; }

	bool isNeighbor(Location2D& p) {
		return ((row == p.row && (col == p.col - 1 || col == p.col + 1)) || (col == p.col && (row == p.row - 1 || row == p.row + 1)));
	}

	bool operator ==(Location2D& p) {
		return row == p.row && col == p.col;
	}
};

int main() {

	Location2D loc;
	loc.col;

	loc.isNeighbor(Location2D p(1, 3));

	Location2D loc1(1, 2);
	Location2D loc2(3, 2);

	loc1 == loc2;

	return 0;
}