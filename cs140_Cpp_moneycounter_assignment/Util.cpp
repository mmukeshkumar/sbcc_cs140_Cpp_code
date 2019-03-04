//============================================================================
// Name        : Util.cpp
// Author      : Mukesh Manirajkumar
// Version     : 1
// Copyright   : SBCC
// CS140, Assignment 5, Jackie Kuehn
// Description : This C++ program has the Util class definition
//============================================================================
//#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "Util.h"
using namespace std;
//function implementations
Util::Util() //constructor definition
{
}

Util::~Util() //destructor
{
  //Destructors does not accept arguments
}

//This function validates the input to check if its a positive integer and is a even number
bool Util::validateInput(string input)
{
  return true;
}

int Util::convertDimesToCents(int dimes)
{
  return dimes * 10; //10 cents = 1 Dime
}

int Util::convertDollarsToCents(int dollars)
{
  return dollars * 100; //100 cents = 1 Dollar
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

//This function will convert the input int to string
string
Util::convertIntToString(int input)
{
  stringstream out;
  out << input;
  return out.str();
}
