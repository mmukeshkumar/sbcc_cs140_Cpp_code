//----------------------------------------------------------------------
// Name        : customer.cpp
// Author      : Mukesh Manirajkumar
// Version     : 1
// Copyright   : SBCC
// CS140, Assignment 8:Vending Machine simulation, Jackie Kuehn
// Description : This C++ source file which holds the Customer class implementation
//-----------------------------------------------------------------------
#include "customer.h"
#include "vendingmachine.h"

    // Constructor
  Customer::Customer()
  {
      customer_change = 0.00;
  }

 Customer:: ~Customer() // Destructor
    {
    }


 void User::add_dollars(int the_dollar_unit, VendingMachine *vending_machine, VendingMachine::Money money)
   {
      //


       switch(money) {
             // Diamonds, Hearts, Clubs, and Spades do not need explicit
             //  class qualifier.
             case VendingMachine::Dollar:
             vending_machine->add_customer_change(the_dollar_unit, VendingMachine::Dollar);
             break;
             case VendingMachine::Quater:
          vending_machine->add_customer_change(the_dollar_unit, VendingMachine::Quater);
             break;
             case VendingMachine::Dime:
           vending_machine->add_customer_change(the_dollar_unit, VendingMachine::Dime);
             break;

          }

   }

 void User::release_customer_coins(VendingMachine* the_vending_machine)
 {
    the_vending_machine->release_user_coins();

 }

