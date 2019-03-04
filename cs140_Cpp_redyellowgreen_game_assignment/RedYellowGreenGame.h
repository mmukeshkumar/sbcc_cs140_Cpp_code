//============================================================================
// Name        : RedYellowGreenGame.h
// Author      : Mukesh Manirajkumar
// Version     :
// Copyright   : SBBC
// Description : This C++ header file has the RedYellowGreenGame class prototype, which is a number guessing game
// CS140, Assignment 3, Jackie Kuehn
//============================================================================
//definition of the class
#include <string>
using namespace std;

class RedYellowGreenGame
{
public:
  RedYellowGreenGame(); // Constructor definition
  ~RedYellowGreenGame(); // Destructor definition
  // various function declarations
  int
  generateRandomNumber(int seed);
  void
  compare(string guessNumberString, string randomNumberString);
  bool
  match(char guessNumberCharacter, string randomNumberString);
  int
  start();
  bool
  play(int randomNumber);
  string
  convertIntToString(int guess);
  int
  exitProgram(int exiter);
// constant declarations
  const static int lowest = 100;
  const static int highest = 999;
//protected:
};
