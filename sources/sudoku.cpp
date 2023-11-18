#include "sudoku.hpp"

/**
 * @brief Constructs a new Sudoku:: Sudoku object
 * 
 */
Sudoku::Sudoku() {
}

/**
 * @brief Heart of the program calls various funtions to solve the Sudoku
 * 
 */
void Sudoku::playSudoku() {
	if (generateSudoku() == true
		&& solveSudoku(0, 0) == true
		&& checkSolution() == true) {
		printMessage(GREEN, " Success: Solution  ");
	}
	else {
		printMessage(RED, "Failure: No Solution");
	}

	if (this->sudoku != nullptr) {
		deleteSudoku();
	}
}

/**
 * @brief Destroies the Sudoku:: Sudoku object
 * 
 */
Sudoku::~Sudoku() {
}