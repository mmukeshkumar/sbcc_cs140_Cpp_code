//============================================================================
// Name        : Util.h
// Author      : Mukesh Manirajkumar
// Version     : 1
// Copyright   : SBCC
// CS140, Assignment 5, Jackie Kuehn
// Description : This C++ header file has the Util class prototype, which defines the blueprint of thsome util functions
//============================================================================

#include <string>
using namespace std;
class Util
{
public:
  Util(); // Constructor
  ~Util(); // Destructor
  int exitProgram(int);
  bool validateInput(string);
  string convertIntToString(int input);
  int convertDimesToCents(int);
  int convertDollarsToCents(int);
};
