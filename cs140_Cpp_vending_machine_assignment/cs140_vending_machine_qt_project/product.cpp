//----------------------------------------------------------------------------
// Name        : product.cpp
// Author      : Mukesh Manirajkumar
// Version     : 1
// Copyright   : SBCC
// CS140, Assignment 8:Vending Machine simulation, Jackie Kuehn
// Description : This C++ source file, which holds the Product class implementation
//-----------------------------------------------------------------------------
#include <string>
#include "product.h"

using namespace std;
 // Constructor
Product:: Product()
{
    name = "";
    price = 0.00;
    total_units = 0;
    description = "";
    sold_out = false;
}
   // Destructor
 Product:: ~Product()
 {
 }
  string Product:: get_name()
{
      return name;
  }
  string Product:: get_description()
{
      return name;
  }
  double Product::get_price()
{
      return price;
  }

  int Product::get_total_units()
{
      return total_units;
  }

   void  Product::set_name(string the_product_name)
   {
       name = the_product_name;

   }

    void Product::set_price(double the_price)
    {
        price = the_price;

    }

     void Product::set_total_units(int the_count)
     {
           total_units = the_count;

     }

      bool Product:: get_sold_out()
      {
          return sold_out;
      }



