//============================================================================
// Name        : SquareElement.cpp
// Author      : Mukesh Manirajkumar
// Compsc 140 -> C++
// Jackie Kuehn
// Copyright   : SBBC
// Assignment 4
// Description : This C++ program has the SquareElement class definition
//============================================================================
#include "stdafx.h"
#include <iostream>
#include "SquareElement.h"
#include <vector>
using namespace std;
//function implementations
SquareElement::SquareElement()
{
  //any thing which needs to be initialized will go here

}
SquareElement::~SquareElement()
{
  //Destructors does not accept arguments
}
//this function displays the square

void SquareElement::setRowNumber(int i)
{
  rowNumber = i;

}

void SquareElement::setColumnNumber(int i)
{
  columnNumber = i;
}

void SquareElement::setValue(int i)
{
  value = i;
}

void SquareElement::setOccupied(bool b)
{
  occupied = b;
}

bool SquareElement::isOccupied()
{
  return occupied;
}

int SquareElement::getRowNumber()
{
  return rowNumber;
}

int SquareElement::getColumnNumber()
{
  return columnNumber;
}

void SquareElement::printElementValue()
{
  cout << value << " | ";
}

void SquareElement::printElementInfo()
{
  if (occupied)
    {
      cout << "Occupied       : " << "YES" << endl;
    }
  else
    {
      cout << "Occupied       : " << "NO" << endl;
    }
  cout << "Row            : " << rowNumber << endl;
  cout << "Column         : " << columnNumber << endl;
  cout << "Value          : " << value << endl << endl;
}
