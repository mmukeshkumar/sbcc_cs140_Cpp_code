//============================================================================
// Name        : Main.cpp
// Author      : Mukesh Manirajkumar
// Compsc 140 -> C++
// Jackie Kuehn
// Version     : 1.0
// Copyright   : SBCC
// Description : This cpp program which tests the WordFrequencyCounter C++ class
//============================================================================
//#include "stdafx.h"
#include <iostream>
#include "WordFrequencyCounter.h"
using namespace std;

int main()
{
  WordFrequencyCounter frequeny_counter;
  frequeny_counter.count("C:/quotes.txt");
  frequeny_counter.displayCount();
  char c;
  cin >> c;
  return 0;
}
