//============================================================================
// Name        : Util.cpp
// Author      : Mukesh Manirajkumar
// Compsc 140 -> C++
// Jackie Kuehn
// Copyright   : SBBC
// Assignment 5: Dictionary Project
// Description : This C++ program has the Util class definition
//============================================================================
//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
  int input = 0;

  cout
      << "Please enter 1 for adding a word, or 2 for deleting a word or 3 for verifying if a word exists in the dictionary: "
      << endl;
  cin >> input;
  return input;
}

string Util::getWord()
{
  string word;
  cout << "Please enter the word: " << endl;

  cin >> word;
  return word;
}

string Util::toLowerCase(string word)
{
  transform(word.begin(), word.end(), word.begin(), ::tolower);
  return word;
}

//This function validates the input to check if its a positive integer and is a even number
bool Util::validateInput(int input)
{
  if (cin.fail())
    {
      cin.clear();
      cerr << "Please enter an integer " << endl;
      return false;
    }
  if (input < 1 || input > 3)
    {
      cerr
          << "Please enter an integer value which is 1(for adding a word), 2(for deleting a word),3(for verifying if a word exists in the dictionary), please try again"
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
