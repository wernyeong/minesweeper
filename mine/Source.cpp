#include "globals.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
  bool isAlive = true;
  bool first_click = true;

  //////////////////////////////////////
  // Get parameters from player
  //////////////////////////////////////

  int nRows, nCols, nMines;
  string param;

  cout << "Enter width of board: ";
  getline(cin, param);
  nCols = stoi(param);
  
  cout << "Enter height of board: ";
  getline(cin, param);
  nRows = stoi(param);

  cout << "Enter number of mines: ";
  getline(cin, param);
  nMines = stoi(param);

  int** minesList = new int*[nMines];

  for (int i = 0; i < nMines; i++)
    {
      minesList[i] = new int[2];
    }
  
  //////////////////////////////////////
  // Create gameBoard and solvedBoard
  //////////////////////////////////////
  
  char** gameBoard = new char*[nRows];
  int** solvedBoard = new int*[nRows];

  for (int i = 0; i < nRows; i++)
    {
      gameBoard[i] = new char[nCols];
    }
    
  for (int i = 0; i < nRows; i++)
    {
      for (int j = 0; j < nCols; j++)
	{
	  gameBoard[i][j] = '.';
	}
    }
  
  for (int i = 0; i < nRows; i++)
    {
      solvedBoard[i] = new int[nCols];
    }

  //////////////////////////////////////
  
  while (isAlive)
    {
      clearScreen();

      for (int i = 0; i < nRows; i++)
	{
	  for (int j = 0; j < nCols; j++)
	    {
	      cout << gameBoard[i][j];
	    }
	  cout << endl;
	}

      cout << "Enter row number: ";
      string action1, action2;
      getline(cin, action1);
      cout << "Enter column number: ";
      getline(cin, action2);

      // !!! NEED TO CHECK FOR CORRECT INPUT !!! //
		
      int x = stoi(action1);
      int y = stoi(action2);

      if (first_click)
	{
	  plant_mines(x, y, minesList, nRows, nCols, nMines);
	  create_solved_board(solvedBoard, nRows, nCols, nMines, minesList);
	  first_click = false;
	}
      
      if (solvedBoard[x][y] == 9)
	{
	  isAlive = false;		//unnecessary, or need better transition
	  clearScreen();
	  for (int i = 0; i < nRows; i++)
	    {
	      for (int j = 0; j < nCols; j++)
		if (solvedBoard[i][j] == 9)
		  cout << 'x';
		else
		  cout << solvedBoard[i][j];
	      cout << endl;
	    }
	}
      else if (solvedBoard[x][y] == 0)
	spread(x, y, gameBoard, solvedBoard, nRows, nCols);
      else
	gameBoard[x][y] = solvedBoard[x][y] + '0';

    }
}
