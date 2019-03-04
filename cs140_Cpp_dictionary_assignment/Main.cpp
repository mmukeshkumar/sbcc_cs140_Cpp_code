//============================================================================
// Name        : Main.cpp
// Author      : Mukesh Manirajkumar
// Compsc 140 -> C++
// Jackie Kuehn
// Copyright   : SBCC
// Assignment 5
// Description : This C++ program is sued for testing the Dictionary class
//============================================================================
#include "Dictionary.h"
#include "Util.h"
#include <iostream>
using namespace std;

int main()
{
  char* input_file = (char*) "C:/dictionary.txt";
  Dictionary dictionary(input_file);
  dictionary.printContentsOfDictionary();
  //now get the input from the user
  Util util;

  while (true)
    {
      int input = util.getInput();
      if (util.validateInput(input))
        {
          cin.clear();
          //string word = util.getWord();
          if (input == 1)
            {
              dictionary.addWord();
            }
          else if (input == 2)
            {
              dictionary.deleteWord();
            }
          else
            {
              string new_word;
              cout << "Please enter the word to look up in the dictionary: "
                  << endl;
              cin >> new_word;
              if (dictionary.doesWordExist(util.toLowerCase(new_word)) == -1)
                {
                  cout << "The word inputted," << new_word
                      << " does NOT exist in the dictionary" << endl;
                }
              else
                {
                  cout << "The word inputted," << new_word
                      << " does exist in the dictionary" << endl;
                }
            }
        }
    }
  return 0;
}

