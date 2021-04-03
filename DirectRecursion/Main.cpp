#include <iostream>
#include <math.h>
#include <ctime>
/*		exit	0x00007ff787ee7414 {DirectRecursion.exe!exit}	void *

TODO: 
1. Generate Maze
	[done] 1.1 create the sides (That's a given)
		1.1.1 create grid of pluses and spaces
		1.1.2 fill the sides with - and | for the walls
	1.2 get a randomized path that  would start on one side and exit on another side (the path is a max of (dependent on the size the user gives) squares)
		[done] 1.2.1 hardcode start position (and end position?) and create a path array to store the index of the path in the maze
		1.2.2 use recursion to generate the correct path for the maze
			1.2.2.1 picks the next direction without backtracking
			1.2.2.2 checks if there's a plus sign
				1.2.2.2.1 if so, pick a new direction
				1.2.2.2.2 if not, go in that direction
			1.2.2.3 add the index of the next position into the path array
			1.2.2.4 repeat until we reach the edge
	1.3 randomize the walls around the path
		1.3.1 

*/

int getMazeSize();
void generateSidesAndCorners(char* maze, int length);
void drawMaze(char* maze, int length);
void getStartingPosition(char* maze, int length, int* path);
int getRandomRange(int min, int max);
void nextPosition(char* maze, int length, int* path, int lastPosition);
void generateMaze(char* maze, int length);

int main() {
	srand(time(0));
	{
		int* path = new int();
		//get user input for size
		int MazeSize = getMazeSize();
		int MaxSize = MazeSize * MazeSize;
		char* maze = new char[MaxSize];

		generateSidesAndCorners(maze, MazeSize);
		
		getStartingPosition(maze, MazeSize, path);

		generateMaze(maze, MazeSize);
		//maze[(MazeSize * MazeSize) - MazeSize - 2] = '#';
		drawMaze(maze, MazeSize);

		delete[] maze;
		delete path;
	}
	return EXIT_SUCCESS;
}

int getRandomRange(int min, int max) {
	return min + rand() % ((max + 1) - min);
}

void getStartingPosition(char* maze, int length, int* path) {

	int startPos = getRandomRange(length+1, (length+1) + (length-3));
	path[0] = startPos;
	maze[startPos] = '#';

	//call next position
	nextPosition(maze, length, path, 0);

}

void nextPosition(char* maze, int length, int* path, int lastPosition) {
	//recursive function for getting the next position and adding it to the array

	//locate last value in the array
	
	//get the values adjacent to that postion
	{
		int adj[3];
		//left
		adj[0] = path[lastPosition] - 1;
		//right
		adj[1] = path[lastPosition] + 1;
		//down
		adj[2] = path[lastPosition] + length;

		do {
			int pos = getRandomRange(0, 2);

			if (maze[adj[pos]] == ' ') {
				path[lastPosition + 1] = adj[pos];
				maze[adj[pos]] = '#';
				break;
			}

		} while (true);
	
	}

	//length**2 - length-2
	//base case
	if (path[lastPosition + 1] > (length * length) - length * 2 && path[lastPosition + 1] < (length*length) - length-1) {
		//stops recursion
		return;
	}
	else {
		//std::cout << path[lastPosition + 1] << std::endl;

		return nextPosition(maze, length, path, ++lastPosition);
	}

}

void generateMaze(char* maze, int length)
{

	for (int i = 0; i < length; i++) {
		//odd rows for walls
		if (i % 2 != 0) {
			for (int j = 0; j < length; j++) {
				if (maze[i * length + j] != '#' && j % 2 == 0) {

					if (rand() % 3 == 1) {

						maze[i * length + j] = '|';

					}
				}
				
			}
		}
		else {
			for (int j = 0; j < length; j++) {
				if (maze[i * length + j] != '#' && j % 2 != 0) {

					if (rand() % 3 == 1) {

						maze[i * length + j] = '-';

					}
				}
			}
		}
	}


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
		return 31;
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
	
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {

			if (!(i % 2 == 0)) {
				if (j == 0 || j == length - 1) {
					maze[i * length + j] = '|';
				}
			}
			if (i == 0 || i == length - 1) {
				if (!(j % 2 == 0)) {
					maze[i * length + j] = '-';
				}
				
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