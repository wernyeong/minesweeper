#ifndef GLOBALS_INCLUDED

#define GLOBALS_INCLUDED

///////////////////////////////////////////////////////////////////////////
//  Constants
///////////////////////////////////////////////////////////////////////////

//int nRows, nCols, nMines;
//int** minesList;
//const int nRows = 40;             // number of rows in the arena
//const int nCols = 40;             // number of columns in the arena
//const int nMines = 100;           // number of robots allowed
//char gameBoard[nRows][nCols];
//int solvedBoard[nRows][nCols];
//int minesList[nMines][2];

///////////////////////////////////////////////////////////////////////////
//  Auxiliary function declarations
///////////////////////////////////////////////////////////////////////////

int randInt(int min, int max);
void clearScreen();
//void spread(int row, int col);
void spread(int row, int col, char** gameBoard, int** solvedBoard, int nRows,
	    int nCols);
void plant_mines(int first_x, int first_y, int** minesList, int nRows,
		 int nCols, int nMines);
void create_solved_board(int** solvedBoard, int nRows, int nCols, int nMines,
			 int** minesList);

#endif // GLOBALS_INCLUDED
