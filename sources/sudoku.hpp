#include <iostream>
#include <fstream>
#include <string>

#define GREEN "\033[0;32;1m"
#define RED "\e[38;5;196;1m"
#define ESCAPE "\033[0m"

class Sudoku {
private:
	FILE* file;
	int** sudoku;
public:
	// sudoku.cpp
	Sudoku();
	void playSudoku();
	~Sudoku();

	// createSudoku.cpp
	bool openSudoku();
	void allocateSudoku();
	void deleteSudoku();
	bool createSudoku();
	void initializeSudoku();
	bool isValidSudoku();
	
	// solveSudoku.cpp
	bool solveSudoku(int row, int column);
	bool isValidDigit(int digit, int row, int column);
	bool isNotInRow(int digit, int row, int column);
	bool isNotInColumn(int digit, int row, int column);
	bool isNotInBox(int digit, int row, int column);
	bool isValidSolution();
	void printReasonableColumnLayout(int indexColumn);
	void printReasonableRowLayout(int indexRow);
};