//============================================================================
// Name        : RedYellowGreenGame.cpp
// Author      : Mukesh Manirajkumar
// Version     :
// Copyright   : SBBC
// Description : This C++ program has the RedYellowGreenGame class definition, which is a number guessing game
// CS140, Assignment 3, Jackie Kuehn
//============================================================================
//#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iostream>
#include "RedYellowGreenGame.h"
using namespace std;

//function implementations
RedYellowGreenGame::RedYellowGreenGame()
{
  //any thing which needs to be initialized will go here
}

RedYellowGreenGame::~RedYellowGreenGame()
{
  //Destructors does not accept arguments
}
//this function starts the game and controls the flow of the game
int
RedYellowGreenGame::start()
{
  int exiter = 0;
  int randomNumber = 0;
  bool hit = false;
  string randomNumberString = "";
  cout
      << "****************************************************************************"
      << endl;
  cout
      << "Welcome to the RedYellowGreen Game!!!, this game lets you play guess the number"
      << endl;
  cout << "Lets play!!!!!" << endl;
  cout
      << "****************************************************************************"
      << endl;
  randomNumber = generateRandomNumber(time(0)); // time(0) will generate system time in seconds
  hit = play(randomNumber);
  while (hit == false)
    {
      hit = play(randomNumber);
    }
  cout << "would you like to continue playing ?, enter 1 for continuing, "
      << endl;
  cin >> exiter;
  if (exiter == 1)
    {
      start();
    }
  return exitProgram(exiter);
}

//this function holds the high level comparison logic for the game
bool
RedYellowGreenGame::play(int randomNumber)
{
  int guess;
  string guessNumberString = "";
  string randomNumberString = convertIntToString(randomNumber);
  cout << "please enter a guess(in the range 100 - 999): " << endl;
  cin >> guess;
  if (cin.fail())
    {
      cerr << "Input was not an integer" << endl;
      cout << "Please try again, goodbye" << endl;
      return false;
    }
  guessNumberString = convertIntToString(guess);
  if (guess < lowest || guess > highest)
    {
      cerr << "Input was an integer, but its not in the range 100 - 999"
          << endl;
      cout << "Please try again," << endl;
      return false;
    }
  if (guess == randomNumber)
    {
      cout << "CONGRATULATIONS YOU ARE CORRECT !!!!!!!!! " << endl;
      cout << "The random number generated was : " << randomNumber << endl;
      cout << "Your guess was : " << guess << endl;
      return true;
    }
  else
    {
      compare(guessNumberString, randomNumberString);
      return false;
    }
}

//This function will generate a random number in the range specified in the contants lowest and highest
// the input seed is used to initialiaze the random generator
int
RedYellowGreenGame::generateRandomNumber(int seed)
{ //Initialize random number generator
  srand(seed);
  // generate and return the random number
  return rand() % (highest - lowest) + 1 + lowest; //will be in the range lowest to highest
}

//This function will check to see if the input single character is present in the randomNumberString
bool
RedYellowGreenGame::match(char guessNumberCharacter, string randomNumberString)
{
  int randomNumberSize = randomNumberString.length();
  for (int i = 0; i < randomNumberSize; i++)
    {
      if (guessNumberCharacter == randomNumberString[i])
        {
          return true;
        }
    }
  return false;
}

//This function will do the comparision between two equal sized strings and print out the no of reds, yellows and greens
// The algorithm used is linear time (O(n)-> Linear time)as opposed to the quadratic time -> O(n2) i.e. O(n power 2) of the normal brute-force string searching algorithm
// Note: If in the below coe you have put one for loop inide of a for loop then it would become quadratic time
void
RedYellowGreenGame::compare(string guessNumberString, string randomNumberString)
{
  int reds = 0;
  int greens = 0;
  int yellows = 0;
  int guessNumberLength = guessNumberString.length();
  // check for greens
  for (int i = 0; i < guessNumberLength; i++)
    { // check for exact position match
      if (guessNumberString[i] == randomNumberString[i])
        {
          greens++;
          guessNumberString[i] = -1;
          randomNumberString[i] = -1;
        }

    }
  // now check for yellows
  for (int i = 0; i < guessNumberLength; i++)
    { // now check if the number is present in other positions, except the positions which have -1, which already matched as greem
      if (guessNumberString[i] != -1)
        {
          if (match(guessNumberString[i], randomNumberString))
            {
              yellows++;
            }
          else
            {
              reds++;
            }
        }
    }
  cout << "you have: " << reds << " Red" << endl;
  cout << "you have: " << greens << " Green" << endl;
  cout << "you have: " << yellows << " Yellow" << endl;
}

//This function will convert the input int to string
string
RedYellowGreenGame::convertIntToString(int input)
{
  stringstream out;
  out << input;
  return out.str();
}

//This function prints the exit message and then exits the program
int
RedYellowGreenGame::exitProgram(int exiter)
{
  cout
      << "Press Control-C or Press any key(other than enter) and hit enter to exit "
      << endl;
  cin >> exiter;
  return 0;
}
