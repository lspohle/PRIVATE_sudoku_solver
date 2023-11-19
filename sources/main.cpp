#include "gameSudoku/gameSudoku.hpp"

int main() {
	GameSudoku* game = nullptr;
	game = new GameSudoku();

	game->playSudoku();

	delete game;
	game = nullptr;

	return 0;
}