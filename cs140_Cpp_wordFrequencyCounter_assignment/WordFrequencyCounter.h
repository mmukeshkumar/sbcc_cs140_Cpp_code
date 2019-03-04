//============================================================================
// Name        : Util.h
// Author      : Mukesh Manirajkumar
// Version     : 1
// Copyright   : SBCC
// CS140, Assignment 7:Word Frequency counter, Jackie Kuehn
// Description : This C++ header file has the Util class prototype, which defines the blueprint of the util functions
//============================================================================

#include <string>
# include <map>
using namespace std;
class WordFrequencyCounter
{
private:
  map<string, int> words_and_count_map;// I am storing the word as the key and the count i.e. frequency of the words as the value
public:
  WordFrequencyCounter(); // Constructor
  ~WordFrequencyCounter(); // Destructor
  //This function will remove punctuations
  string removePunctuations(string);
  //This function will count the frequency of each word in the passed in file
  void count(string);
  //This function will display the the frequency of each word in the passed in file
  void displayCount();
};
