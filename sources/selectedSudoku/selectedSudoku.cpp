#include "selectedSudoku.hpp"

/**
 * @brief Construct a new Selected Sudoku:: Selected Sudoku object
 * 
 */
SelectedSudoku::SelectedSudoku() {
}

void print(int** array) {
	for (int row = 0; row < 9; ++row) {
		for (int column = 0; column < 9; ++column) {
			std::cout << array[row][column];
		}
	}
}

int** SelectedSudoku::selectSudoku() {
    if (openSudoku() == false) {
		return nullptr;
	}
	this->selectedSudoku = allocateSudoku();
	initializeSudoku();
	return this->selectedSudoku;
}

/**
 * @brief Opens the file in reading mode which contains Sudoku that shall be solved
 * 
 * @return true - opened file successfully 
 * @return false - failed opening the file
 */
bool SelectedSudoku::openSudoku() {
	const char* filename = "sudoku.txt";

	this->file = fopen(filename, "r");
	if(this->file == nullptr) {
		std::cerr << "Error: Opening the file failed\n";
		return false;
	}
	return true;
}

/**
 * @brief Initializes Sudoku as specified in the file 
 * 
 */
void SelectedSudoku::initializeSudoku() {
	char digit;

	for (int row = 0; row < 9; ++row) {
		for (int column = 0; column < 9; ++column) {
			digit = std::getc(file);
			if (digit == '\n') {
				digit = std::getc(file);
			}
			this->selectedSudoku[row][column] = digit - '0';
		}
	}
	digit = std::getc(file);
}

/**
 * @brief Checks sudoku digit by digit if every digit is unique in its position
 * 
 * @return true - valid sudoku ()= continue)
 * @return false - invalid sudoku (= termintate)
 */
bool SelectedSudoku::checkSudoku() {
	if (isValidAmountOfCharacters() == false) {
		return false;
	}

	bool isValid = true;
	std::cout << std::endl;
	for (int row = 0; row < 9; ++row) {
		for (int column = 0; column < 9; ++column) {
			printWhiteGreenRedSudoku(&isValid, row, column);
			printReasonableColumnLayout(column + 1);
		}
		printReasonableRowLayout(row + 1);
	}
	printMessage(WHITE, "       Sudoku       ");
	return isValid;
}

/**
 * @brief Checks if sudoku provided in file contains proper amount of characters
 * 
 * @return true - correct size of sudoku
 * @return false - incorrect size of sudoku
 */
bool SelectedSudoku::isValidAmountOfCharacters() {
	int isEndOfFile;
	isEndOfFile = feof(file);
	fclose(file);

	if (!isEndOfFile) {
		std::cerr << RED << "Error: Invalid layout\n" << ESCAPE;
		return false;
	}
	return true;
}

/**
 * @brief Prints current digit in a specific color depending on its meaning
 * 
 * @param isValid is digit unique in its current position
 * @param row current position
 * @param column current position
 */
void SelectedSudoku::printWhiteGreenRedSudoku(bool* isValid, int row, int column) {
	if (this->selectedSudoku[row][column] == 0) {
		std::cout << WHITE << this->selectedSudoku[row][column] << " " << ESCAPE;
	}
	else if (isValidCharacter(row, column) == false || isValidDigitOccurrance(row, column) == false) {
		*isValid = false;
	}
	else {
		std::cout << GREEN << this->selectedSudoku[row][column] << " " << ESCAPE;
	}
}

/**
 * @brief Manual Sudoku - Checks if sudoku provided in file contains non-digits
 * 
 * @param row - current position
 * @param column - current position
 * @return true - only digits
 * @return false - not only digits
 */
bool SelectedSudoku::isValidCharacter(int row, int column) {
	if (this->selectedSudoku[row][column] < 0 || this->selectedSudoku[row][column] > 9) {
		char c = this->selectedSudoku[row][column] + '0';
		std::cout << RED << c << " " << ESCAPE;
		return false;
	}
	return true;
}

bool SelectedSudoku::isValidDigitOccurrance(int row, int column) {
	if (isValidDigit(this->selectedSudoku, this->selectedSudoku[row][column], row, column) == false) {
		std::cout << RED << this->selectedSudoku[row][column] << " " << ESCAPE;
		return false;
	}
	return true;
}

/**
 * @brief Destroy the Selected Sudoku:: Selected Sudoku object
 * 
 */
SelectedSudoku::~SelectedSudoku() {
}