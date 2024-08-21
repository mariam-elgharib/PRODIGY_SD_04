#include <iostream>
using namespace std;

bool isvalid(int grid[9][9], int row, int col, int num) {
	//current row
	for (int x = 0; x < 9; x++)
		if (grid[row][x] == num)
			return false;
	//current coloumn
	for (int x = 0; x < 9; x++)
		if (grid[x][col] == num)
			return false;

	//current 3x3 subgrid
	int startRow = row - row % 3, startCol = col - col % 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (grid[i + startRow][j + startCol] == num)
				return false;

	return true;
}

bool solve(int grid[9][9],int row, int col) {
	if (row == 9 - 1 && col == 9)
		return true;
	if (col == 9) {
		row++;
		col = 0;
	}
	if (grid[row][col] != 0)
		return solve(grid, row, col + 1);

	for (int num = 1; num <= 9; num++) {
		if (isvalid(grid, row, col, num)) {
			grid[row][col] = num;

			if (solve(grid, row, col + 1))
				return true;
		}
		grid[row][col] = 0;
	}
	return false;
}

int main() {
	int grid[9][9];
	cout << "Enter grid: (Enter 0 if position is empty)" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> grid[i][j];
		}
	}

	if (solve(grid,0,0)){
		cout << endl;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "Solution isnt available." << endl;
	}
	return 0;
}