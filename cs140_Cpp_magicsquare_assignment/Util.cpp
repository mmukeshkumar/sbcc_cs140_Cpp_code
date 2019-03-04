//============================================================================
// Name        : Util.cpp
// Author      : Mukesh Manirajkumar
// Compsc 140 -> C++
// Jackie Kuehn
// Copyright   : SBBC
// Assignment 4
// Description : This C++ program has the Util class definition
//============================================================================
#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Util.h"
using namespace std;
//function implementations
Util::Util() //constructor
{
}

Util::~Util() //destructor
{
  //Destructors does not accept arguments
}

int Util::getInput()
{
  int squareSize = 0;
    // create an 'instance' of the class
    //MagicSquare square(3);
    Util util;
    cout
        << "Enter the square size (n) for generating the n x n maqic square:(enter an odd number from 1 to 15) : "
        << endl;
    cin >> squareSize;
    return squareSize;
}

//This function validates the input to check if its a positive integer and is a even number
bool Util::validateInput(int squareSize)
{
  if (cin.fail())
  {
      cin.clear();
    cerr << "Please enter an integer " << endl;
    return false;
  }
  if (squareSize == 0 || squareSize < 0)
    {
      cerr
                << "Please enter an integer value which is NOT 0 and NOT negative, from 1 to 15, please try again"
                << endl;
      return false;
    }
  else if (squareSize % 2 == 0)
    {
      cerr
                      << "Please enter an integer value which is odd, between 1 to 15, please try again"
                      << endl;
      return false;
    }
  else
    {
      return true;
    }
}

//This function prints the exit message and then exits the program
int Util::exitProgram(int exiter)
{
  cout
      << "Press Control-C or Press any key(other than enter) and hit enter to exit "
      << endl;
  cin >> exiter;
  return 0;
}
