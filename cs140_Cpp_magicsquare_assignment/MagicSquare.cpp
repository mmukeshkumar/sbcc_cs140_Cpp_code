//============================================================================
// Name        : MagicSquare.cpp
// Author      : Mukesh Manirajkumar
// Compsc 140 -> C++
// Jackie Kuehn
// Copyright   : SBCC
// Assignment 4
// Description : This C++ program has the MagicSquare class definition
//============================================================================
#include "stdafx.h"
#include <iostream>
#include <vector>
#include "MagicSquare.h"
using namespace std;
//function implementations

MagicSquare::MagicSquare(int size)
{
  squareSize = size;
  //any thing which needs to be initialized will go here
   initializeSquare(squareSize);
}

MagicSquare::~MagicSquare()
{
  //Destructors does not accept arguments
}

//this function fills the square with elements which have their default values set
void MagicSquare::initializeSquare(int size)
{
  totalSize = size * size;
  SquareElement *element;
  int row = 1;
  int column = 1;
  for (int i = 1; i <= totalSize; i++)
    {
      element = new SquareElement;
      element->setOccupied(false);
      element->setRowNumber(row);
      element->setColumnNumber(column);
      element->setValue(0); //setting default values of zero
      square.push_back(*element);
      // square[i-1] = *element;   //Comment added just for learning purposes: this line of code blows up with a STATUS_ACCESS_VIOLATION, so I commented it out and used the push_back method instead
      column += 1;
      if (column > size)
        { // reset column and increment row
          column = 1;
          row += 1;
        }
    }
  // display square elements values, just for testing
  /*vector<SquareElement>::iterator it;
  cout << "square vector size is: " << square.size() << endl;
  int counter = 1;
  for (it = square.begin(); it != square.end(); ++it)
    { // For each element, print out their info
      cout << "square element #: " << counter << endl;
      it->printElementInfo();
      counter++;
    }*/
}

//this function fills the square with magic numbers,I have used a vector to hold the square implementation
void MagicSquare::fillSquare()
{
  int currentRow = 1;
  int currentColumn = 1;
  SquareElement *element;
  int vectorPosition = 0;
  for (int i = 1; i <= totalSize; i++)
    {
      element = new SquareElement;
      if (i == 1)
        {
          //put the i value in the middle of the first row
          element->setRowNumber(1);
          int column = getCenter(squareSize);
          element->setColumnNumber(column + 1);
          element->setValue(i);
          element->setOccupied(true);
          square[column] = *element;
          currentColumn = column + 1;
          vectorPosition = column;
        }
      else
        {
          SquareElement existingElement;
          // move up one row and to the right one column
          int nextRow = getNextRow(currentRow);
          if (nextRow == 0)
            {
              nextRow = squareSize;
            }
          int nextColumn = getNextColumn(currentColumn);

          if (nextColumn > squareSize)
            {
              nextColumn = 1;
            }
          int nextElementVectorPosition = getNextElementVectorPosition(nextRow,
              nextColumn, squareSize);
          existingElement = square[nextElementVectorPosition];
          //existingElement.printElementInfo();
          if (existingElement.isOccupied() == true)
            {
             /* cout << "The square element at row # "
                  << existingElement.getRowNumber() << " , and column#"
                  << existingElement.getColumnNumber() << " , is occupied"
                  << endl;*/
              nextColumn = currentColumn;
              nextRow = currentRow + 1;
              element->setRowNumber(nextRow);
              element->setColumnNumber(nextColumn);
              element->setValue(i);
              element->setOccupied(true);
              nextElementVectorPosition = getNextElementVectorPosition(nextRow,
                  nextColumn, squareSize);
              square[nextElementVectorPosition] = *element;

            }
          else // there is no element there
            {
              element->setRowNumber(nextRow);
              element->setColumnNumber(nextColumn);
              element->setValue(i);
              element->setOccupied(true);
              square[nextElementVectorPosition] = *element;
            }
          currentColumn = nextColumn;
          currentRow = nextRow;
        }
    }
}

//this function displays the magic square
void MagicSquare::displaySquare()
{
  vector<SquareElement>::iterator it;
  // cout << "square vector size is after filling square: " << square.size()
  //<< endl;
  int counter = 1;
  cout << "Displaying square of size: " << squareSize << "x" << squareSize
      << endl;
  for (it = square.begin(); it != square.end(); ++it)
    { // For each element, print out their info
      //cout << "square element #: " << counter << endl;
      it->printElementValue();
      if (counter == squareSize)
        {
          cout << endl;
          cout << "-------------------------------------" << endl;
          counter = 1;
        }
      else
        {
          counter++;
        }
      //  it->printElementInfo();
    }
}

int MagicSquare::getCenter(int size)
{
  // odd number
  return (size / 2);

}

int MagicSquare::getNextRow(int currentRow)
{  // move up one row
  return currentRow - 1;

}

int MagicSquare::getNextColumn(int currentColumn)
{  // go right one position
  return currentColumn + 1;

}

int MagicSquare::getNextElementVectorPosition(int nextRow, int nextColumn,
    int squareSize)
{
  if (nextRow == 1)
    {
      return nextColumn - 1;
    }
  else
    {
      int positionOfLastElementOfRow = (nextRow * squareSize) - 1;

      if (nextColumn == squareSize)
        {
          return positionOfLastElementOfRow;
        }
      else
        {
          return positionOfLastElementOfRow - (squareSize - nextColumn);

        }

    }
}
