#include "gameSudoku.hpp"

/**
 * @brief Solves the sudoku - BACKTRACKING using RECURSION
 * 
 * @param row current position to fill
 * @param column current position to fill
 * @return true - successful in finding a solution
 * @return false - failed in finding a solution
 */
bool GameSudoku::solveSudoku(int** sudoku, int row, int column) {
	// Finished
	if (row == 9) {
		return true;
	}
	// Next row
	else if (column == 9) {
		return solveSudoku(sudoku, row + 1, 0);
	}
	// Skip fixed digit
	else if (sudoku[row][column] != 0) {
		return solveSudoku(sudoku, row, column + 1);
	}
	// Trial and error
	else {
		for (int digit = 1; digit <= 9; ++digit) {
			if (isValidDigit(sudoku, digit, row, column) == true) {
				sudoku[row][column] = digit;
				if (solveSudoku(sudoku, row, column + 1) == true) {
					return true;
				}
				sudoku[row][column] = 0;
			}
		}
		return false;
	}
}

/**
 * @brief Checks if a digit is unique in current position
 * 
 * @param digit potential digit between 1 and 9 to fill current position
 * @param row current position to fill
 * @param column current position to fill
 * @return true - digit is unique in current position
 * @return false - digit is not unique in current position
 */
bool GameSudoku::isValidDigit(int** sudoku, int digit, int row, int column) {
	if (isNotInRow(sudoku, digit, row, column) == false
		|| isNotInColumn(sudoku, digit, row, column) == false
		|| isNotInBox(sudoku, digit, row, column) == false) {
		return false;
	}
	return true;
}

/**
 * @brief Checks if a digit is unique in current row
 * 
 * @param digit potential digit between 1 and 9 to fill current position
 * @param row current row in which digit should be unique
 * @param column current position (to check that digit is only represented once)
 * @return true - digit is unique in current row
 * @return false - digit is already represented in current row
 */
bool GameSudoku::isNotInRow(int** sudoku, int digit, int row, int column) {
	for (int c = 0; c < 9; ++c) {
		if (digit == sudoku[row][c] && c != column) {
			return false;
		}
	}
	return true;
}

/**
 * @brief Checks if a digit is unique in current row
 * 
 * @param digit potential digit between 1 and 9 to fill current position
 * @param row specify current position (to check that digit is only represented once)
 * @param column current column in which digit should be unique
 * @return true - digit is unique in current column
 * @return false - digit is already represented in current column
 */
bool GameSudoku::isNotInColumn(int** sudoku, int digit, int row, int column) {
	for (int r = 0; r < 9; ++r) {
		if (digit == sudoku[r][column] && r != row) {
			return false;
		}
	}
	return true;
}

/**
 * @brief Checks if a digit is unique in current box (3x3)
 * 
 * @param digit potential digit between 1 and 9 to fill current position
 * @param row current row in which digit should be unique (within current box)
 * @param column current column in which digit should be unique (within current box)
 * @return true - digit is unique in current box
 * @return false - digit is already represented in current box
 */
bool GameSudoku::isNotInBox(int** sudoku, int digit, int row, int column) {
	int r = row - row % 3;
	int c = column - column % 3;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; j++) {
			if (digit == sudoku[r][c] && r != row && c != column) {
				return false;
			}
			c++;
		}
		r++;
		c -= 3;
	}
	return true;
}

/**
 * @brief Checks if the solution is correct and prints the final outcome
 * 
 * @return true - solution is correct
 * @return false - solution is incorrect
 */
bool GameSudoku::checkSolution() {
	bool isValid = true;

	std::cout << std::endl;
	for (int row = 0; row < 9; ++row) {
		for (int column = 0; column < 9; ++column) {
			if (isValidDigit(this->sudoku, this->sudoku[row][column], row, column) == false) {
				if (this->sudoku[row][column] != 0) {
					std::cout << RED;
				}
				std::cout << this->sudoku[row][column] << " " <<ESCAPE;
				isValid = false;
			}
			else {
				std::cout << GREEN << this->sudoku[row][column] << " " << ESCAPE;
			}
			printReasonableColumnLayout(column + 1);
		}
		printReasonableRowLayout(row + 1);
	}
	return isValid;
}