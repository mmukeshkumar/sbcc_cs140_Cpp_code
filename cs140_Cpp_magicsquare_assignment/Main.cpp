//============================================================================
// Name        : Main.cpp
// Author      : Mukesh Manirajkumar
// Version     : 1.1
// Copyright   : SBCC
// Description : This C++ program has the main method for runnung and testing the MagicSquare program
// CS140, Assignment 4, Jackie Kuehn
//============================================================================
#include "stdafx.h"
#include <iostream>
#include "MagicSquare.h"
#include "Util.h"
#include <ctime>
using namespace std;

int main()
{
  int exiter = 0;
  int squareSize ;
  // create an 'instance' of the class
  //MagicSquare square(3);
  Util util;
  squareSize = util.getInput();
  if(util.validateInput(squareSize))
  {
  MagicSquare square(squareSize);// this would call the contructor to initiaze the square elements with default values
  cout << "square size :" << squareSize << endl;
  square.fillSquare();
  square.displaySquare();
  }   
  return util.exitProgram(exiter);
}
