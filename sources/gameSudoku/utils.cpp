#include "gameSudoku.hpp"

int** GameSudoku::allocateSudoku() {
	int** sudoku;

	sudoku = new int*[9];
	for (int i = 0; i < 9; ++i) {
		sudoku[i] = new int[9];
	}
	return sudoku;
}

/**
 * @brief Frees the allocated memory that sudoku is stored in
 * 
 */
void GameSudoku::deleteSudoku(int** sudoku) {
	for (int i = 0; i < 9; ++i) {
		delete[] sudoku[i];
	}
	delete[] sudoku;
}

/**
 * @brief Offers user to choose between a manual (provided by file) and random sudoku (generated)
 * 
 * @return char - choice of sudoku
 */
char GameSudoku::printOptionsSudoku() {
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
void GameSudoku::printMessage(std::string color, std::string msg) {
	std::cout << "╔════════════════════╗\n";
	std::cout << "║" << color << msg << ESCAPE << "║\n";
	std::cout << "╚════════════════════╝\n";
}

/**
 * @brief Ensures a reasonable layout (as transparant as possible)
 * 
 * @param indexColumn column between 1 and 9 to determine current box
 */
void GameSudoku::printReasonableColumnLayout(int indexColumn) {
	if (indexColumn % 3 == 0) {
		std::cout << "	";
	}
}

/**
 * @brief Ensures a reasonable layout (as transparant as possible)
 * 
 * @param indexRow row between 1 and 9 to determine current box
 */
void GameSudoku::printReasonableRowLayout(int indexRow) {
	if (indexRow % 3 == 0) {
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
