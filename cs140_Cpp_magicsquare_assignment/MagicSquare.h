//============================================================================
// Name        : MagicSquare.h
// Author      : Mukesh Manirajkumar
// Compsc 140 -> C++
// Jackie Kuehn
// Copyright   : SBBC
// Assignment 4
// Description : This C++ header file has the MagicSquare class prototype, which defines the blueprint of the MagicSquare program

//============================================================================
//definition of the class

#include "SquareElement.h"
#include <vector>
using namespace std;

class MagicSquare
{
public:
        vector<SquareElement> square;
        int squareSize ;
        int totalSize;
        int squareRowSize;
        int squareColumnSize;
  MagicSquare(int); // Constructor definition
  ~MagicSquare(); // Destructor definition
  // various function declarations
 void initializeSquare(int);
  void
  fillSquare();
  void
    displaySquare();

  int getCenter(int);
  int getNextRow(int);
  int getNextColumn(int);
  //SquareElement getSquareElement(int position);
  int getNextElementVectorPosition(int, int, int);
  string convertIntToString(int);
// constant declarations
  //protected:
};
