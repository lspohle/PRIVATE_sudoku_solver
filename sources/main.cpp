#include "sudoku.hpp"

int main() {
	Sudoku* sudoku = nullptr;
	sudoku = new Sudoku();

	sudoku->playSudoku();

	delete sudoku;
	sudoku = nullptr;
	
	return 0;
}