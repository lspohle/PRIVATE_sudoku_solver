#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

#define GREEN "\033[0;32;1m"
#define RED "\e[38;5;196;1m"
#define WHITE "\033[0;37;0m"
#define ESCAPE "\033[0m"

class Sudoku {
private:
	int** sudoku;
	FILE* file;
public:
	// sudoku.cpp
	Sudoku();
	void playSudoku();
	~Sudoku();

	// generateSudoku.cpp
	bool generateSudoku();
	bool openSudoku();
	void allocateSudoku();
	void deleteSudoku();
	void initializeSudoku();
	void initializeRandomSudoku();
	int generateFixedDigit(int row, int column);

	// checkSudoku.cpp
	bool checkSudoku(char sudokuChoice);
	bool isValidAmountOfCharacters();
	bool isValidCharacter(int row, int column);
	bool isValidDigitOccurrance(int row, int column);
	
	// solveSudoku.cpp
	bool solveSudoku(int row, int column);
	bool isValidDigit(int digit, int row, int column);
	bool isNotInRow(int digit, int row, int column);
	bool isNotInColumn(int digit, int row, int column);
	bool isNotInBox(int digit, int row, int column);
	bool checkSolution();

	// printSudoku.cpp
	char printOptionsSudoku();
	void printMessage(std::string color, std::string msg);
	void printWhiteGreenRedSudoku(bool* isValid, int row, int column);
	void printReasonableColumnLayout(int indexColumn);
	void printReasonableRowLayout(int indexRow);
};