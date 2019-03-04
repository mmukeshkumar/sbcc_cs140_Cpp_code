//============================================================================
// Name        : Counter.h
// Author      : Mukesh Manirajkumar
// Version     : 1
// Copyright   : SBCC
// CS140, Assignment 5, Jackie Kuehn
// Description : This header C++ file holds the Counter class prototype
//============================================================================
#include <string>
using namespace std;

class Counter
{
private:
  int max_count;
  int current_counter_value;
public:
  Counter(); // default constructor which sets the  max_count to 9999
  Counter(bool); // constructor which sets the max_count to inputted value which is an integer amount less than 9999
  ~Counter(); //Destructor
  int getMaxCount();
  string getKeys();
  bool validateKeys(string keys);
  void count();
  void incrementCounter(char, int);
  void printInvalidInputErrorMessage();
};
