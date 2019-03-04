//============================================================================
// Name        : SquareElement.h
// Author      : Mukesh Manirajkumar
// Compsc 140 -> C++
// Jackie Kuehn
// Copyright   : SBCC
// Assignment 4
// Description : This C++ header file has the SquareElement class prototype, which defines the blueprint of one elemet of the n*n magic square
//============================================================================
class SquareElement
{
public:
  SquareElement(); // Constructor definition
  ~SquareElement(); // Destructor definition
  void setRowNumber(int);
  void setColumnNumber(int);
  void setValue(int);
  void setOccupied(bool);
  bool isOccupied();
  int getRowNumber();
  int getColumnNumber();
  void printElementInfo();
  void printElementValue();
private:
  int rowNumber;
  int columnNumber;
  int value;
  bool occupied;
};
