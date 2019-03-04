//============================================================================
// Name        : Dictionary.h
// Author      : Mukesh Manirajkumar
// Compsc 140 -> C++
// Jackie Kuehn
// Copyright   : SBCC
// Assignment 5: Dictionary Project
// Description : This C++ header file has the Dictionary class prototype, which defines the blueprint of thsome util functions
//============================================================================
#include <vector>
#include <string>
using namespace std;

class Dictionary
{
private:
  vector<string> dictionary;
public:
  Dictionary(); // Default constructor definition
  Dictionary(char*); // definition for constructor which initializes dictionary from the input file
  ~Dictionary(); // Destructor definition
  int exitProgram(int exiter);
  bool validateInput();
  vector<string> getDictionary();
  int doesWordExist(string);
  bool addWord();
  bool deleteWord();
  bool sortDictionary();
  void printContentsOfDictionary();
};
