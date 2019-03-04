//============================================================================
// Name        : Dictionary.cpp
// Author      : Mukesh Manirajkumar
// Compsc 140 -> C++
// Jackie Kuehn
// Copyright   : SBCC
// Assignment 5
// Description : This C++ program has the Dictionary class implementation
//============================================================================
#include "Dictionary.h"
#include "Util.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib> // for exit function
#include <set>
#include <vector>
using namespace std;

//constructor implementation which initializes the dictionary
Dictionary::Dictionary(char* file_path)
{
  ifstream input_file;
  set<string> unique_sorted_dictionary; //I am  using a set container so that I keep the dictionary an ordered set of unique elements, its also sorts the data as it is stored.
  string word;
  input_file.open(file_path);
  if (!input_file)
    {
      cerr << "Error: file could not be opened" << endl;
      exit(1);
    }
  input_file >> word;
  while (input_file.eof()== false)
    {
      //cout << "The next word is: " << word << endl;
      transform(word.begin(), word.end(), word.begin(), ::tolower);
      //cout << "The word in lowercase is: " << word << endl;
      unique_sorted_dictionary.insert(word);
      input_file >> word; // sets EOF flag if no value found
    }
  input_file.close();
  set<string>::iterator iter;
  for (iter = unique_sorted_dictionary.begin();
      iter != unique_sorted_dictionary.end(); iter++)
    { // I am putting the contents of the set to a vector because this assignment is supposed to be done using the vector container
      cout << *iter << endl;
      dictionary.push_back(*iter);
    }
}

bool Dictionary::addWord()
{
  bool result = false;
  string new_word;
  Util util;
  cout << "Please enter the word to add: " << endl;
  cin >> new_word;
  if (cin.fail() == false)
    {
      if(doesWordExist(util.toLowerCase(new_word)) == -1)
        {
          dictionary.push_back(util.toLowerCase(new_word));
          cout << "The word " << new_word << " was successfully added" << endl;
          result = true;
        }
      else
        {
          cout << "The word " << new_word << " is already present in the dictionary" << endl;
          result = false;
        }
    }

  return result;
}

int Dictionary::doesWordExist(string word)
{
  int index = -1;
  unsigned int postion = find(dictionary.begin(), dictionary.end(), word)
      - dictionary.begin();

  if (postion < dictionary.size())
    {
      return (int) postion;
    }
  else
    {
      return index;
    } 
}

void Dictionary::printContentsOfDictionary()
{
  vector<string>::iterator iter;
  for (iter = dictionary.begin(); iter != dictionary.end(); iter++)
    {
      cout << *iter << endl;
    }
}

bool Dictionary::deleteWord()
{
  string word;
  Util util;
  cout << "Please enter the word to delete: " << endl;

  cin >> word;
  int index = doesWordExist(util.toLowerCase(word));
  if (index >= 0)
    {
      dictionary.erase(dictionary.begin() + index);
      cout << "The word " << word << " was successfully deleted" << endl;
      return true;
    }
  else
    {
      cout << "The word " << word << " does not exist in the dictionary"
          << endl;
      return false;
    }
}

//default constructor implementation
Dictionary::~Dictionary()
{
}
//destructor
Dictionary::Dictionary()
{
}
