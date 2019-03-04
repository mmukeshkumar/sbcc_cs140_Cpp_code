//----------------------------------------------------------------------
// Name        : admin.h
// Author      : Mukesh Manirajkumar
// Version     : 1
// Copyright   : SBCC
// CS140, Assignment 8:Vending Machine simulation, Jackie Kuehn
// Description : This C++ header file has the Admin class prototype
//-----------------------------------------------------------------------
#include "user.h"
#include "vendingmachine.h"

class Admin : public User
{
private:    
    //This function will add a new product
    void add_product(Product);
    void add_vending_machine_change(double);
public:
    // Constructor
  Admin();

  ~Admin() ;// Destructor
 void add_dollars_to_vending_machine(int,VendingMachine*, VendingMachine::Money);
 void release_vending_machine_coins(VendingMachine*);
  void add_product(Product*, VendingMachine*);

};
