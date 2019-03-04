//----------------------------------------------------------------------
// Name        : basevendingmachine.h
// Author      : Mukesh Manirajkumar
// Version     : 1
// Copyright   : SBCC
// CS140, Assignment 8:Vending Machine simulation, Jackie Kuehn
// Description : This C++ header file has the BaseVendingMachine class prototype
//-----------------------------------------------------------------------
#ifndef BASEVENDINGMACHINE_H
#define BASEVENDINGMACHINE_H
#include <string>
class BaseVendingMachine
{
private:
public:
    BaseVendingMachine ()
    {
    }

   ~BaseVendingMachine ()
    {
    }

    enum Money// the possible coin types accepted by the vending machine
   {
      Quater,
      Dime,
      Dollar
   };

    //all these functions will be overridden by the child class which inherits from this class
    //if any base level functionality needs to be added which should be shared by all child classes then they
    // should add the functionality in this class methods and the child class should call these functions
    //from inside the child overriden funtions
    double add_change(int, Money)
    {
        return 0.00;
    }
     double add_customer_change(int, Money)
     {
         return 0.00;
     }

     void release_user_coins()
     {
     }
      void release_vending_machine_coins()
      {

      }

      bool buy_product(string)
      {
          return false;

      }



};

#endif // BASEVENDINGMACHINE_H
