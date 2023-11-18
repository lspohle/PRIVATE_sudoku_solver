#include "sudoku.hpp"

/**
 * @brief Generates, allocates and initializes the two dimensional array sudoku[9][9]
 * 
 * @return true - successful allocation/initialization of a valid sudoku
 * @return false - invalid sudoku/invalid user's input/failed opening the file
 */
bool Sudoku::generateSudoku() {
	char sudokuChoice;
	sudokuChoice = printOptionsSudoku();

	if (sudokuChoice == '1') {
		if (openSudoku() == false) {
			return false;
		}
		allocateSudoku();
		initializeSudoku();
		return checkSudoku(sudokuChoice);
	}
	else if (sudokuChoice == '2') {
		allocateSudoku();
		initializeRandomSudoku();
		return checkSudoku(sudokuChoice);
	}
	return false;
}

/**
 * @brief Opens the file in reading mode which contains Sudoku that shall be solved
 * 
 * @return true - opened file successfully 
 * @return false - failed opening the file
 */
bool Sudoku::openSudoku() {
	const char* filename = "sudoku.txt";

	this->file = fopen(filename, "r");
	if(this->file == nullptr) {
		std::cerr << "Error: Opening the file failed\n";
		return false;
	}
	return true;
}

/**
 * @brief Allocates the given Sudoku from the file onto the heap
 * 
 */
void Sudoku::allocateSudoku() {
	this->sudoku = new int*[9];
	for (int i = 0; i < 9; ++i) {
		this->sudoku[i] = new int[9];
	}
}

/**
 * @brief Frees the allocated memory that sudoku is stored in
 * 
 */
void Sudoku::deleteSudoku() {
	for (int i = 0; i < 9; ++i) {
		delete[] this->sudoku[i];
	}
	delete[] this->sudoku;
}

/**
 * @brief Initializes Sudoku as specified in the file 
 * 
 */
void Sudoku::initializeSudoku() {
	char digit;

	for (int row = 0; row < 9; ++row) {
		for (int column = 0; column < 9; ++column) {
			digit = std::getc(file);
			if (digit == '\n') {
				digit = std::getc(file);
			}
			this->sudoku[row][column] = digit - '0';
		}
	}
	digit = std::getc(file);
}

/**
 * @brief Initializes a sudoku randomly considering the following probability
 * 		-> Empty Cell: 0.66
 * 		-> Filled Cell: 0.33
 */
void Sudoku::initializeRandomSudoku() {
	int isFree;

	srand(time(0));
	for (int row = 0; row < 9; ++row) {
		for (int column = 0; column < 9; ++column) {
			isFree = rand() % 3;
			if (isFree == false) {
				this->sudoku[row][column] = generateFixedDigit(row, column);
			}
			else {
				this->sudoku[row][column] = 0;
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
int Sudoku::generateFixedDigit(int row, int column) {
	int digit;

	digit = rand() % 9 + 1;
	while (isValidDigit(digit, row, column) == false) {
		digit = rand() % 9 + 1;
	}
	return digit;
}
