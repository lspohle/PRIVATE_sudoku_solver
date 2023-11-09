#include "sudoku.hpp"

/**
 * @brief Allocates and initializes the two dimensional array sudoku[9][9]
 * 
 * @return true - successful allocation/initialization of a valid sudoku
 * @return false - failed opening the file or file contains an invalid Sudoku
 */
bool Sudoku::createSudoku() {
	if (openSudoku() == false) {
		return false;
	}
	allocateSudoku();
	initializeSudoku();
	return isValidSudoku();
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
 * @brief Initializes Sudoku as specified in the file 
 * 
 */
void Sudoku::initializeSudoku() {
	int digit;

	for (int row = 0; row < 9; ++row) {
		for (int column = 0; column < 9; ++column) {
			digit = std::getc(file) - '0';
			if (digit < 0 || digit > 9) {
				digit = std::getc(file) - '0';
			}
			this->sudoku[row][column] = digit;
		}
	}
	digit = std::getc(file) - '0';
}

/**
 * @brief Checks if the Sudoku specified in the file is a valid sudoku
 * 		  (taking its layout and characters into account)
 * 
 * @return true - the specified Sudoku is valid
 * @return false - the specified Sudoku is not valid
 * 		   -> will not be processed further
 */
bool Sudoku::isValidSudoku() {
	int isEndOfFile;
	isEndOfFile = feof(file);
	fclose(file);

	if (!isEndOfFile) {
		std::cerr << RED << "Error: Invalid layout\n" << ESCAPE;
		return false;
	}
	for (int row = 0; row < 9; ++row) {
		for (int column = 0; column < 9; ++column) {
			if (this->sudoku[row][column] < 0 || this->sudoku[row][column] > 9) {
				std::cerr << RED << "Error: Invalid characters\n" << ESCAPE;
				return false;
			}
		}
	}
	return true;
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