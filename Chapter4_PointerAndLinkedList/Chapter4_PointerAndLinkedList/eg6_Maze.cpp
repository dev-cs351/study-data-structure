#include "eg6_Maze.h"

int main() {
	Maze testMaze;
	testMaze.load(R"(C:\Users\Chungsu\Source\Repos\dev-cs351\study-data-structure\Chapter4_PointerAndLinkedList\Chapter4_PointerAndLinkedList\eg6_maze.txt)");
	testMaze.print();
	return 0;
}