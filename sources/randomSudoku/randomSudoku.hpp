#ifndef RANDOMSUDOKU_HPP
#define RANDOMSUDOKU_HPP

#include "../gameSudoku/gameSudoku.hpp"

class RandomSudoku : public GameSudoku {
private:
	int** randomSudoku;
public:
	RandomSudoku();
	~RandomSudoku();
	int** generateSudoku();
	bool checkSudoku();
private:
	void initializeRandomSudoku();
	void initializeCopiedSudoku(int** sudoku, int** copy);
	void resetSudoku(int** sudoku);
	int generateFixedDigit(int row, int column);
	void printWhiteGreenRedSudoku(int row, int column);
};

#endif