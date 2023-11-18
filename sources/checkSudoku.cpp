#include "sudoku.hpp"

/**
 * @brief Checks sudoku digit by digit if every digit is unique in its position
 * 
 * @param sudokuChoice - manual (1) or random (2)
 * @return true - valid sudoku ()= continue)
 * @return false - invalid sudoku (= termintate)
 */
bool Sudoku::checkSudoku(char sudokuChoice) {
	if (sudokuChoice == '1' && isValidAmountOfCharacters() == false) {
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
 * @brief Manual Sudoku - Checks if sudoku provided in file contains proper amount of characters
 * 
 * @return true - correct size of sudoku
 * @return false - incorrect size of sudoku
 */
bool Sudoku::isValidAmountOfCharacters() {
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
 * @brief Manual Sudoku - Checks if sudoku provided in file contains non-digits
 * 
 * @param row - current position
 * @param column - current position
 * @return true - only digits
 * @return false - not only digits
 */
bool Sudoku::isValidCharacter(int row, int column) {
	if (this->sudoku[row][column] < 0 || this->sudoku[row][column] > 9) {
		char c = this->sudoku[row][column] + '0';
		std::cout << RED << c << " " << ESCAPE;
		return false;
	}
	return true;
}

bool Sudoku::isValidDigitOccurrance(int row, int column) {
	if (isValidDigit(this->sudoku[row][column], row, column) == false) {
		std::cout << RED << this->sudoku[row][column] << " " << ESCAPE;
		return false;
	}
	return true;
}