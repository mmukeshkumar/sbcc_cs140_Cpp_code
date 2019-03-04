//============================================================================
// Name        : Counter.cpp
// Author      : Mukesh Manirajkumar
// Version     : 1
// Copyright   : SBCC
// CS140, Assignment 5, Jackie Kuehn
// Description : This Counter .cpp file holds the Counter class definition
//============================================================================
#include <iostream>
#include <cstdlib>
//#include <stdio.h>
#include "Counter.h"
#include "Util.h"
using namespace std;

// default constructor which sets the  max_count to 9999
Counter::Counter()
{
  max_count = 9999;
  current_counter_value = 0;
  cout << "Maximum value of counter is: " << max_count << endl;
  cout << "Current value of counter is: " << current_counter_value << endl;
  count(); // start counting
}

// constructor which sets the max_count to inputted value which is an integer amount less than 9999
Counter::Counter(bool determineMaxCount)
{
  if (determineMaxCount)
    {
      max_count = getMaxCount();
      current_counter_value = 0;
      cout << "Maximum value of counter is: " << max_count << endl;
      cout << "Current value of counter is: " << current_counter_value << endl;
    }
  else
    {
      Counter(); // call the default constructor
    }
  count(); // start counting
}

Counter::~Counter() //Destructor
{
}

//function to get the max count from the user
int Counter::getMaxCount()
{
  int input = 0;
  bool validation_success = false;
  while (validation_success == false)
    {
      cout
          << "Please enter an integer amount which is less than 9999 to initialize the counter, "
          << endl;
      cin >> input;
      if (cin.fail())
        {
          cerr << "Please enter an integer" << endl;
          cout << "Sorry, try again, program has stopped " << endl;
          exit(1);
        }
      else
        {
          if (input > 9999)
            {
              cerr
                  << "Integer amount entered is greater than 9999, please try again"
                  << endl;
            }
          else
            {
              validation_success = true;
            }
        }
    }
  return input;
}

//function to get the keys from the user
string Counter::getKeys()
{
  string keys = "";
  bool valid = false;
  while (valid == false)
    {
      cout
          << "Enter a key, either a, s, d, f, followed by 1-9. or o for overflow"
          << endl;
      cin >> keys;
      if (cin.fail())
        {
          cerr << "Not valid input, program has exited, please try again"
              << endl;
          exit(1);
        }
      valid = validateKeys(keys);
    }
  return keys;
}

//function to validate the inputted keys
bool Counter::validateKeys(string keys)
{
  bool valid = false;
  if (keys.length() == 1)
    {
      char firstChar = keys[0];
      if (firstChar == 'o')
        {
          //cout << "valid input : " << endl;
          valid = true;
        }
      else
        {
          printInvalidInputErrorMessage();
        }
    }
  else
    {
      if (keys.length() == 2 && isalpha(keys[0]) && isdigit(keys[1])
          && keys[1] != '0')
        {
          char firstChar = keys[0];
          if (firstChar == 'a' || firstChar == 's' || firstChar == 'd'
              || firstChar == 'f' || firstChar == 'o')
            {
              //cout << "valid input : " << endl;
              valid = true;
            }
          else
            {
              printInvalidInputErrorMessage();
            }
        }
      else
        {
          printInvalidInputErrorMessage();
        }
    }

  return valid;
}

//function to count money
void Counter::count()
{
  string keys = "";
  // int exiter = 0;
  keys = getKeys();
  if (keys.length() == 1 && keys[0] == 'o') // check for overflow
    {
      if (current_counter_value > max_count)
        {
          cout << "You have gone over the limit" << endl;
        }
      else
        {
          cout << "There is no overflow " << endl;
        }
    }
  else
    {
      char firstChar = keys[0];
      int counter = keys[1] - '0'; // convert string to int
      incrementCounter(firstChar, counter);
    }
  count(); // keep counting until user shuts down the console using Ctrl + C
}

//function to increment the counter
void Counter::incrementCounter(char firstChar, int num)
{
  Util util;
  if (firstChar == 'a') // cents
    {
      current_counter_value += num;
    }
  else if (firstChar == 's') //dimes
    {
      current_counter_value += util.convertDimesToCents(num);
    }
  else if (firstChar == 'd') //dollars
    {
      current_counter_value += util.convertDollarsToCents(num);
    }
  else if (firstChar == 'f') //tens of dollars
    {
      current_counter_value += 10 * util.convertDollarsToCents(num);
    }
}

//function to output error message
void Counter::printInvalidInputErrorMessage()
{
  cerr << "Invalid input, please try again" << endl;
}
