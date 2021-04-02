#include <iostream>
#include <math.h>
/*
TODO: 
1. Generate Maze
	[done] 1.1 create the sides (That's a given)
	1.2 get a randomized path that  would start on one side and exit on another side (the path is a max of (dependent on the size the user gives) squares)
	1.3 randomize the walls around the path


*/

int getMazeSize();
void generateSidesAndCorners(char* maze, int length);
void drawMaze(char* maze, int length);

char* maze;

int main() {

	//get user input for size
	int MazeSize = getMazeSize();

	maze = new char[MazeSize * MazeSize];

	generateSidesAndCorners(maze, MazeSize);

	drawMaze(maze, MazeSize);

	//create the maze with 

	return EXIT_SUCCESS;
}

int getMazeSize() {
	//TODO make userinput size dynamic
	std::cout << "Enter the size of the maze: \n1. 25 x 25 \n2. 30 x 30 \n" << std::endl;
	int MazeSize = 0;
	std::cout << "What is the maze size: ";
	std::cin >> MazeSize;

	if (MazeSize == 1) {
		return 25;
	}
	else {
		return 30;
	}


}

void generateSidesAndCorners(char* maze, int length) {

	for (int i = 0; i < length; ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < length; ++j) {

				if (j % 2 == 0) {
					maze[i * length + j] = '+';
				}
				else {
					maze[i * length + j] = ' ';
				}

			}
		}
		else {
			
			for (int j = 0; j < length; ++j) {
				maze[i * length + j] = ' ';
			}
		}
		
	}
	

}

void drawMaze(char* maze, int length) {

	for (int i = 0; i < length; i++) {

		for (int j = 0; j < length; j++) {

			std::cout << maze[i * length + j];

		}
		std::cout << std::endl;
	}
	


}