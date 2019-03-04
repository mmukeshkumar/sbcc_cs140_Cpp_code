//---------------------------------------------------------------------------------------------------------------
// Name        : product.h
// Author      : Mukesh Manirajkumar
// Version     : 1
// Copyright   : SBCC
// CS140, Assignment 8:Vending Machine simulation, Jackie Kuehn
// Description : This C++ header file has the Product class prototype, which defines the blueprint of the vending machine product functions
//--------------------------------------------------------------------------------------------------------------

#include <string>
#include <map>
#include "user.h"
class Customer : public User
{
private:
    double customer_change;
public:
     // Constructor
  Customer();

 // Destructor
  ~Customer();

};
