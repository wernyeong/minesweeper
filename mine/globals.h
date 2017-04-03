#ifndef GLOBALS_INCLUDED

#define GLOBALS_INCLUDED

///////////////////////////////////////////////////////////////////////////
//  Constants
///////////////////////////////////////////////////////////////////////////

const int nRows = 40;             // number of rows in the arena
const int nCols = 40;            // number of columns in the arena
const int nMines = 100;            // number of robots allowed
char gameBoard[nRows][nCols];
int solvedBoard[nRows][nCols];
int minesList[nMines][2];

///////////////////////////////////////////////////////////////////////////
//  Auxiliary function declarations
///////////////////////////////////////////////////////////////////////////

int randInt(int min, int max);
void clearScreen();
void spread(int row, int col);

#endif // GLOBALS_INCLUDED
