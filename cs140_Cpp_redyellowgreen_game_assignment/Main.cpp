//============================================================================
// Name        : Main.cpp
// Author      : Mukesh Manirajkumar
// Version     :
// Copyright   : SBBC
// Description : This C++ program has the main method for runnung the RedYellowGreenGame
// CS140, Assignment 3, Jackie Kuehn
//============================================================================
//#include "stdafx.h"
#include <iostream>
#include "RedYellowGreenGame.h"
#include <ctime>

using namespace std;
int
main()
{
  int exiter = 0;
  int randomNumber = 0;
  // create an 'instance' of the class
  RedYellowGreenGame game;
  //start the game
  game.start();
  // unit testing code
  for (int i = game.lowest; i <= game.highest; i++)
    { // generate the random number
      randomNumber = game.generateRandomNumber(time(0) + i);
      cout << randomNumber << endl;
      if (randomNumber < game.lowest || randomNumber > game.highest)
        {
          cerr << "The randomNumber is not in range " << endl;
        }

    }
  return game.exitProgram(exiter);
}
