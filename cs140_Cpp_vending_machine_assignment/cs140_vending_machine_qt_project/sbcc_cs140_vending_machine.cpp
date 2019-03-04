//============================================================================
// Name        : sbcc_cs140_vending_machine.cpp
// Author      : Mukesh Manirajkumar
// Version     : 1
// Copyright   : SBCC
// CS140, Assignment 8:Vending Machine simulation, Jackie Kuehn
// Description : This C++ source file which holds the VendingMachine class implementation
//---------------------------------------------------------------------------------------------------
#include <string>
#include <map>
#include "vendingmachine.h"

using namespace std;

VendingMachine:: VendingMachine ()
{
    //initialize variables
    sold_out_empty = true;
    vending_machine_change = 0.00;
    customer_change = 0.00;
     total_item_count = 0;
     admin_logged_in = false;
     product_count = 0;
}
 VendingMachine::~ VendingMachine ()
 {

 }

 double VendingMachine::add_change(int units, Money money)
 {
     switch(money) {
           // Diamonds, Hearts, Clubs, and Spades do not need explicit
           //  class qualifier.
           case Dollar:         
           vending_machine_change = vending_machine_change + units * 1.00;
           break;
           case Quater:
           vending_machine_change = vending_machine_change + units * 0.25;
           break;
           case Dime:
          vending_machine_change = vending_machine_change + units * 0.10;
           break;

        }
     return vending_machine_change;
 }

 double VendingMachine::add_customer_change(int units, Money money)
 {
     switch(money) {
           // Diamonds, Hearts, Clubs, and Spades do not need explicit
           //  class qualifier.
           case Dollar:
           customer_change = customer_change + units * 1.00;
           break;
           case Quater:
           customer_change = customer_change + units * 0.25;
           break;
           case Dime:
          customer_change = customer_change + units * 0.10;
           break;

        }
     return customer_change;
 }

 void VendingMachine::set_admin_logged_in(bool the_admin_logged_in)
 {
     admin_logged_in = the_admin_logged_in;
}


 bool VendingMachine::is_sold_out_empty()
 {
     return sold_out_empty;
 }

 const map<string, Product*> VendingMachine::display_products()
 {
     return products;
 }

 void VendingMachine::add_product(Product *the_product)
 {
     if(sold_out_empty == false)
     {
         sold_out_empty = false;
     }

     pair<map<string, Product*>::iterator,bool> insert_return_pair; //A pair, of which the first element is an iterator that points to the possibly inserted pair, and the second is
                                                                // a bool that is true if the pair was actually inserted.
 string product_name = the_product->get_name();
     insert_return_pair = products.insert( pair<string, Product*>(product_name, the_product));
 }

  double VendingMachine::get_vending_machine_change()
   {
       return vending_machine_change;
   }

  double VendingMachine::get_customer_change()
   {
       return customer_change;
   }


  bool VendingMachine::get_admin_logged_in()
   {
       return  admin_logged_in ;
   }

  bool VendingMachine::bump_product_count()
  {
      if(product_count <= MAX_PRODUCT_COUNT)
      {
      product_count++;
      return true;
      }
      else
      {
         return false;
      }

  }

  int VendingMachine::get_product_count()
  {
      return product_count;
  }
  int VendingMachine:: get_max_product_count()
  {
       return MAX_PRODUCT_COUNT;

  }

    bool VendingMachine::buy_product(string the_product_key)
    {
       Product* product = products[the_product_key];
        if(product->get_price()<= customer_change && product->get_total_units() > 0)
        {
           int current_units = product->get_total_units();
           double price =  product->get_price();
           product->set_total_units(current_units -1);
           customer_change = customer_change - price;
            return true;
        }
        else
        {
            return false;
        }

    }
    void VendingMachine::release_vending_machine_coins()
    {
        vending_machine_change = 0.00;

    }

    void VendingMachine::release_user_coins()
    {
       customer_change  = 0.00;

    }
