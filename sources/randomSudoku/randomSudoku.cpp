#include "randomSudoku.hpp"

/**
 * @brief Construct a new Random Sudoku:: Random Sudoku object
 * 
 */
RandomSudoku::RandomSudoku() {
}

int** RandomSudoku::generateSudoku() {
	this->randomSudoku = allocateSudoku();
	initializeRandomSudoku();

	int** copiedSudoku = allocateSudoku();
	initializeCopiedSudoku(this->randomSudoku, copiedSudoku);

	while (solveSudoku(copiedSudoku, 0, 0) == false) {
		resetSudoku(this->randomSudoku);
		initializeRandomSudoku();
		initializeCopiedSudoku(this->randomSudoku, copiedSudoku);
	}

	deleteSudoku(copiedSudoku);
	return this->randomSudoku;
}

void RandomSudoku::resetSudoku(int** sudoku) {
	for (int row = 0; row < 9; ++row) {
		for (int column = 0; column < 9; ++column) {
			sudoku[row][column] = 0;
		}
	}
}

void RandomSudoku::initializeCopiedSudoku(int** original, int** copy) {
	for (int row = 0; row < 9; ++row) {
		for (int column = 0; column < 9; ++column) {
			copy[row][column] = original[row][column];
		}
	}
}

/**
 * @brief Initializes a sudoku randomly considering the following probability
 * 		-> Empty Cell: 0.66
 * 		-> Filled Cell: 0.33
 */
void RandomSudoku::initializeRandomSudoku() {
	int isFree;

	srand(time(0));
	for (int row = 0; row < 9; ++row) {
		for (int column = 0; column < 9; ++column) {
			isFree = rand() % 3;
			if (isFree == false) {
				this->randomSudoku[row][column] = generateFixedDigit(row, column);
			}
			else {
				this->randomSudoku[row][column] = 0;
			}
		}
	}
}

/**
 * @brief Generates a random digit that meets the following requirements
 * - between 1 and 9
 * - unique in its row
 * - unique in its column
 * - unique in its box
 * 
 * @param row current row in which digit should be unique
 * @param column current column in which digit should be unique
 * @return int - digit that meets the abovementioned requrirements
 */
int RandomSudoku::generateFixedDigit(int row, int column) {
	int digit;

	digit = rand() % 9 + 1;
	while (isValidDigit(this->randomSudoku, digit, row, column) == false) {
		digit = rand() % 9 + 1;
	}
	return digit;
}

/**
 * @brief Checks sudoku digit by digit if every digit is unique in its position
 * 
 * @return true - valid sudoku ()= continue)
 * @return false - invalid sudoku (= termintate)
 */
bool RandomSudoku::checkSudoku() {

	std::cout << std::endl;
	for (int row = 0; row < 9; ++row) {
		for (int column = 0; column < 9; ++column) {
			printWhiteGreenRedSudoku(row, column);
			printReasonableColumnLayout(column + 1);
		}
		printReasonableRowLayout(row + 1);
	}
	printMessage(WHITE, "       Sudoku       ");
	return true;
}

/**
 * @brief Prints current digit in a specific color depending on its meaning
 * 
 * @param isValid is digit unique in its current position
 * @param row current position
 * @param column current position
 */
void RandomSudoku::printWhiteGreenRedSudoku(int row, int column) {
	if (this->randomSudoku[row][column] == 0) {
		std::cout << WHITE << this->randomSudoku[row][column] << " " << ESCAPE;
	}
	else {
		std::cout << GREEN << this->randomSudoku[row][column] << " " << ESCAPE;
	}
}

/**
 * @brief Destroy the Random Sudoku:: Random Sudoku object
 * 
 */
RandomSudoku::~RandomSudoku() {
}