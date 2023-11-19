#ifndef SELECTEDSUDOKU_HPP
#define SELECTEDSUDOKU_HPP

#include "../gameSudoku/gameSudoku.hpp"

class SelectedSudoku : public GameSudoku {
private:
    int** selectedSudoku;
    FILE* file;
public:
	SelectedSudoku();
	~SelectedSudoku();
    int** readSudoku();
    bool checkSudoku();
private:
	bool openSudoku();
    void initializeSudoku();
    bool isValidAmountOfCharacters();
    void printWhiteGreenRedSudoku(bool* isValid, int row, int column);
    bool isValidCharacter(int row, int column);
	bool isValidDigitOccurrance(int row, int column);
};

#endif