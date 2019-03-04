//----------------------------------------------------------------------
// Name        : admin.cpp
// Author      : Mukesh Manirajkumar
// Version     : 1
// Copyright   : SBCC
// CS140, Assignment 8:Vending Machine simulation, Jackie Kuehn
// Description : This C++ source file which has the Admin class implementation,
//-----------------------------------------------------------------------
#include "admin.h"
#include "vendingmachine.h"

    // Constructor
  Admin::Admin()
  {
  }

 Admin:: ~Admin() // Destructor
    {
    }

void Admin::add_dollars_to_vending_machine(int the_dollar_unit,  VendingMachine* vending_machine, VendingMachine::Money money)
  {
     //

    switch(money) {
          // Diamonds, Hearts, Clubs, and Spades do not need explicit
          //  class qualifier.
          case VendingMachine::Dollar:
           vending_machine->add_change(the_dollar_unit, VendingMachine::Dollar);
          break;
          case VendingMachine::Quater:
         vending_machine->add_change(the_dollar_unit, VendingMachine::Quater);
          break;
          case VendingMachine::Dime:
        vending_machine->add_change(the_dollar_unit, VendingMachine::Dime);
          break;

       }

  }

  void Admin::add_product(Product* the_product, VendingMachine* the_vending_machine)
  {

  }

  void Admin:: release_vending_machine_coins(VendingMachine* the_vending_machine)
 {
      the_vending_machine->release_vending_machine_coins();

 }


