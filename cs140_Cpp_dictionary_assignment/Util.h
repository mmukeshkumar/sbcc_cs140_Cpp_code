//============================================================================
// Name        : Util.h
// Author      : Mukesh Manirajkumar
// Compsc 140 -> C++
// Jackie Kuehn
// Copyright   : SBBC
// Assignment 5: Dictionary Project
// Description : This C++ header file has the Util class prototype, which defines the blueprint of thsome util functions
//============================================================================
#include <string>
using namespace std;

class Util
{
public:
  Util(); // Constructor definition
  ~Util(); // Destructor definition
  int exitProgram(int);
  bool validateInput(int);
  int getInput();
  string getWord();
  string toLowerCase(string);
};
