#include "globals.h"
#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////////////
//  Spread function implementations
///////////////////////////////////////////////////////////////////////////

void spread(int row, int col, char** gameBoard, int** solvedBoard, int nRows,
	    int nCols)
{
  // display itself 
  gameBoard[row][col] = solvedBoard[row][col] + '0';

  // display 8 cells around
  for (int i = row - 1; i < row + 2; i++)
    for (int j = col - 1; j < col + 2; j++)
      {
	if (i < 0 || i >= nRows || j < 0 || j >= nCols)
	  continue;

	if (solvedBoard[i][j] > 0 || gameBoard[i][j] != '.')
	  {
	    gameBoard[i][j] = solvedBoard[i][j] + '0';
	    continue;
	  }
	else
	  spread(i, j, gameBoard, solvedBoard, nRows, nCols);

      }
}

///////////////////////////////////////////////////////////////////////////
//  plant_mines function implementations
///////////////////////////////////////////////////////////////////////////

void plant_mines(int first_x, int first_y, int** minesList, int nRows,
		 int nCols, int nMines)
{
  // Populate with mines
  for (int i = 0; i < nMines; i++)
    {
      bool isRepeated = true; // change variable name, somewhat misleading
      int r, c;
      while (isRepeated)
	{
	  isRepeated = false;
	  r = randInt(0, nRows - 1);
	  c = randInt(0, nCols - 1);
	  for (int j = 0; j < i; j++)
	    {
	      if ((r == minesList[j][0] && c == minesList[j][1]) || (r == first_x && c == first_y))
		isRepeated = true;
	      //if (r == first_x && c == first_y)
	      //cout << "CLICK" << endl;
	    }
	}

      minesList[i][0] = r;
      minesList[i][1] = c;
    }

  // Display list of mines
  /*
  for (int i = 0; i < nMines; i++)
    {
      cout << "Mine #" << i+1 << ": " << minesList[i][0] << ", " << minesList[i][1]<< endl;
    }
  */
}

///////////////////////////////////////////////////////////////////////////
//  create_solved_board function implementations
///////////////////////////////////////////////////////////////////////////

void create_solved_board(int** solvedBoard, int nRows, int nCols, int nMines,
			 int** minesList)
{
  // Create solved board
  for (int i = 0; i < nRows; i++)
    {
      for (int j = 0; j < nCols; j++)
	{
	  solvedBoard[i][j] = 0;

	  // Check if the tile is a mine
	  for (int k = 0; k < nMines; k++)
	    if (i == minesList[k][0] && j == minesList[k][1])
	      {
		solvedBoard[i][j] = 9;
		break;
	      }
			
	  if (solvedBoard[i][j] == 9)
	    continue;

	  // Count number of mines around
	  for (int k = i - 1; k < i + 2; k++)
	    {
	      for (int l = j - 1; l < j + 2; l++)
		{
		  for (int m = 0; m < nMines; m++)
		    if (k == minesList[m][0] && l == minesList[m][1])
		      solvedBoard[i][j]++;
		}
	    }
	}
    }

  // Display solved board
  /*
    for (int i = 0; i < nRows; i++)
    {
      for (int j = 0; j < nCols; j++)
	{
	  cout << solvedBoard[i][j];
	}
	  cout << endl;
    }
  */
}
