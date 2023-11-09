#include "sudoku.hpp"

/**
 * @brief Construct a new Sudoku:: Sudoku object
 * 
 */
Sudoku::Sudoku() {
}

/**
 * @brief Heart of the program calls various funtions to solve the Sudoku
 * 
 */
void Sudoku::playSudoku() {
	if (createSudoku() == true
		&& solveSudoku(0, 0) == true
		&& isValidSolution() == true) {
		std::cout << "╔════════════════════╗\n";
		std::cout << "║" << GREEN << " Success: Solution  " << ESCAPE << "║\n";
		std::cout << "╚════════════════════╝\n";
		//printSudoku();
	}
	else {
		std::cout << "╔════════════════════╗\n";
		std::cout << "║" << RED << "Failure: No Solution" << ESCAPE << "║\n";
		std::cout << "╚════════════════════╝\n";
	}
	deleteSudoku();
}

/**
 * @brief Destroy the Sudoku:: Sudoku object
 * 
 */
Sudoku::~Sudoku() {
}