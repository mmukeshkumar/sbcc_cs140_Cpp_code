//============================================================================
// Name        : Util.cpp
// Author      : Mukesh Manirajkumar
// Version     : 1
// Copyright   : SBCC
// CS140, Assignment 7:Word Frequency counter, Jackie Kuehn
// Description : This C++ program has the Util class definition
//============================================================================
//#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <cstring>
# include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // for exit function
#include <algorithm>// for the transform function
#include "WordFrequencyCounter.h"
using namespace std;
//function implementations
WordFrequencyCounter::WordFrequencyCounter() //constructor definition
{
}

WordFrequencyCounter::~WordFrequencyCounter() //destructor
{
  //Destructors does not accept arguments
}

//This function will count the frequency of each word in the passed in file
void WordFrequencyCounter::count(string file_path)
{
  map<string, int>::iterator it;
  pair<map<string, int>::iterator,bool> insert_return_pair; //A pair, of which the first element is an iterator that points to the possibly inserted pair, and the second is
                                                            // a bool that is true if the pair was actually inserted.
  ifstream input_file;
  string word;
// convert string to char
  char *char_file_path = new char[file_path.size() + 1];
  strcpy(char_file_path, file_path.c_str());

  input_file.open(char_file_path);
  if (!input_file)
    {
      cerr << "Error: file could not be opened" << endl;
      exit(1);
    }
  input_file >> word;
  while (input_file.eof() == false)
    {
      cout << "The next word is: " << word << endl;
      transform(word.begin(), word.end(), word.begin(), ::tolower);
      cout << "The word in lowercase is: " << word << endl;
      cout << "The last letter of the word is: " << word[word.length() - 1]
          << endl;
      word = removePunctuations(word);
      insert_return_pair = words_and_count_map.insert(
          pair<string, int>(word, 1));

      if (insert_return_pair.second == false)
        {
          cout << "word: " << insert_return_pair.first->first
              << " already exists";
          cout << " with a value of " << insert_return_pair.first->second
              << endl;
          // get the word count
          int count = insert_return_pair.first->second;
          count = count + 1;
          //put the updated word count in the map
          insert_return_pair.first->second = count;
          cout << " value of count: " << count << endl;
        }
      input_file >> word; // sets EOF flag if no value found
    }
  input_file.close();
}

//This function will display the the frequency of each word in the passed in file
void WordFrequencyCounter::displayCount()
{
  map<string, int>::iterator it;
  cout << "\nThe listing of the words and their counts are as follows:\n";
  for (it = words_and_count_map.begin(); it != words_and_count_map.end(); it++)
    cout << "Word: " << (*it).first << " ; Count: " << (*it).second << endl;
}

//This function will remove punctuations
string WordFrequencyCounter::removePunctuations(string word)
{
  char dot = '.';
  char comma = ',';
  char semicolon = ';';

  char last_letter = word[word.length() - 1];
  if (last_letter == dot || last_letter == comma || last_letter == semicolon)
    {
      word.erase(word.length() - 1, 1);
      cout << "The word after removing punctuations: " << word << endl;
    }
  return word;
}

