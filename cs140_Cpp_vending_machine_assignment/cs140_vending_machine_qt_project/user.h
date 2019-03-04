//============================================================================
// Name        : user.h
// Author      : Mukesh Manirajkumar
// Version     : 1
// Copyright   : SBCC
// CS140, Assignment 8:Vending Machine simulation, Jackie Kuehn
// Description : This C++ header file has the User class prototype, which defines the blueprint of the User class
//============================================================================

#ifndef USER_H
#define USER_H

#include <string>
#include <map>
#include "vendingmachine.h"
using namespace std;

class User
{
private:
protected:

public:
  User()
  {
      }// Constructor
  ~User()// Destructor
  {
  }
  string name;

   void release_customer_coins();
  void buy_product(int);
  void add_quaters(int);
  void add_dollars(int);
   void add_cents(int);
   void add_dimes(int);
  double add_change(int);
  //void add_dollars(int);

  void add_dollars(int the_dollar_unit,VendingMachine* vending_machine, VendingMachine::Money money);
   void release_customer_coins(VendingMachine*);
};
#endif // USER_H
