#include <iostream>
#include <vector>
using namespace std;

const int GRID_SIZE = 9;

void printGrid(const vector<vector<int>>& grid) {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

bool isSafe(const vector<vector<int>>& grid, int row, int col, int num) {
   
    for (int x = 0; x < GRID_SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>>& grid) {
    int row, col;
    bool emptySpot = false;

    for (row = 0; row < GRID_SIZE; row++) {
        for (col = 0; col < GRID_SIZE; col++) {
            if (grid[row][col] == 0) {
                emptySpot = true;
                break;
            }
        }
        if (emptySpot) break;
    }

    if (!emptySpot) return true;

    for (int num = 1; num <= GRID_SIZE; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) return true;

            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Original Sudoku Puzzle:" << endl;
    printGrid(grid);

    if (solveSudoku(grid)) {
        cout << "\nSolved Sudoku Puzzle:" << endl;
        printGrid(grid);
    } else {
        cout << "\nNo solution exists!" << endl;
    }

    return 0;
}