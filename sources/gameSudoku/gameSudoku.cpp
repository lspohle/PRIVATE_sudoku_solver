#include "gameSudoku.hpp"
#include "../selectedSudoku/selectedSudoku.hpp"
#include "../randomSudoku/randomSudoku.hpp"

/**
 * @brief Constructs a new Sudoku:: Sudoku object
 * 
 */
GameSudoku::GameSudoku() {
}

/**
 * @brief Heart of the program calls various funtions to solve the Sudoku
 * 
 */
void GameSudoku::playSudoku() {
	if (chooseSudoku() == true
		&& solveSudoku(this->sudoku, 0, 0) == true
		&& checkSolution() == true) {
		printMessage(GREEN, " Success: Solution  ");
	}
	else {
		printMessage(RED, "Failure: No Solution");
	}

	if (this->sudoku != nullptr) {
		deleteSudoku(this->sudoku);
	}
}

bool GameSudoku::chooseSudoku() {
	char sudokuChoice = printOptionsSudoku();

	if (sudokuChoice == '1') {
		SelectedSudoku chosenSudoku;
		this->sudoku = chosenSudoku.readSudoku();
		if (this->sudoku != nullptr) {
			return chosenSudoku.checkSudoku();
		}
	}
	else if (sudokuChoice == '2') {
		RandomSudoku chosenSudoku;
		this->sudoku = chosenSudoku.generateSudoku();
		if (this->sudoku != nullptr) {
			return chosenSudoku.checkSudoku();
		}
	}
	return false;	
}

/**
 * @brief Destroies the Sudoku:: Sudoku object
 * 
 */
GameSudoku::~GameSudoku() {
}