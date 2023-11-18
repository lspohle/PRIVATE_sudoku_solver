#include "sudoku.hpp"

/**
 * @brief Offers user to choose between a manual (provided by file) and random sudoku (generated)
 * 
 * @return char - choice of sudoku
 */
char Sudoku::printOptionsSudoku() {
	std::cout << GREEN << "Please choose from the following:\n" << ESCAPE;
	std::cout << "1) Manual sudoku\n2) Random sudoku\n\n";
	std::cout << GREEN << "Enter 1 or 2: " ESCAPE; 

	char sudokuChoice;
	std::cin >> sudokuChoice;
	return sudokuChoice;
}

/**
 * @brief Prints message provided as an argument
 * 
 * @param color color in which the message shall be printed
 * @param msg message to be printed
 */
void Sudoku::printMessage(std::string color, std::string msg) {
	std::cout << "╔════════════════════╗\n";
	std::cout << "║" << color << msg << ESCAPE << "║\n";
	std::cout << "╚════════════════════╝\n";
}

/**
 * @brief Prints current digit in a specific color depending on its meaning
 * 
 * @param isValid is digit unique in its current position
 * @param row current position
 * @param column current position
 */
void Sudoku::printWhiteGreenRedSudoku(bool* isValid, int row, int column) {
	if (this->sudoku[row][column] == 0) {
		std::cout << WHITE << this->sudoku[row][column] << " " << ESCAPE;
	}
	else if (isValidCharacter(row, column) == false || isValidDigitOccurrance(row, column) == false) {
		*isValid = false;
	}
	else {
		std::cout << GREEN << this->sudoku[row][column] << " " << ESCAPE;
	}
}

/**
 * @brief Ensures a reasonable layout (as transparant as possible)
 * 
 * @param indexColumn column between 1 and 9 to determine current box
 */
void Sudoku::printReasonableColumnLayout(int indexColumn) {
	if (indexColumn % 3 == 0) {
		std::cout << "	";
	}
}

/**
 * @brief Ensures a reasonable layout (as transparant as possible)
 * 
 * @param indexRow row between 1 and 9 to determine current box
 */
void Sudoku::printReasonableRowLayout(int indexRow) {
	if (indexRow % 3 == 0) {
		std::cout << std::endl;
	}
	std::cout << std::endl;
}