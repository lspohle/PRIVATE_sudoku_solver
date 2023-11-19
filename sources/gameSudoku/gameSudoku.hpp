#ifndef GAMESUDOKU_HPP
#define GAMESUDOKU_HPP

#define GREEN "\033[0;32;1m"
#define RED "\e[38;5;196;1m"
#define WHITE "\033[0;37;0m"
#define ESCAPE "\033[0m"

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

class GameSudoku {
private:
	int** sudoku;
public:
	// gameSudoku.cpp
	GameSudoku();
	void playSudoku();
	bool chooseSudoku();
	~GameSudoku();

	// utils.cpp
	int** allocateSudoku();
	void deleteSudoku(int** sudoku);
	char printOptionsSudoku();
	void printMessage(std::string color, std::string msg);
	void printReasonableColumnLayout(int indexColumn);
	void printReasonableRowLayout(int indexRow);
	
	// solveSudoku.cpp
	bool solveSudoku(int** sudoku, int row, int column);
	bool isValidDigit(int** sudoku, int digit, int row, int column);
	bool isNotInRow(int** sudoku, int digit, int row, int column);
	bool isNotInColumn(int** sudoku, int digit, int row, int column);
	bool isNotInBox(int** sudoku, int digit, int row, int column);
	bool checkSolution();
};

#endif