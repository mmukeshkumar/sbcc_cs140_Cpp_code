//============================================================================
// Name        : WordFrequencyCounter.cpp
// Author      : Mukesh Manirajkumar
// Version     : 1
// Copyright   : SBCC
// CS140, Assignment 8: VendingMachine, Jackie Kuehn
// Description : This C++ program has the VendingMachine class definition
//============================================================================
//#include "stdafx.h"

#include <string>
#include <map>
#include "vendingmachine.h"

using namespace std;


//function implementations
VendingMachine::VendingMachine() //constructor definition
{
    //initialize variables
    sold_out = true;
    change = 0.0;
}

VendingMachine::~VendingMachine() //destructor
{
  //Destructors does not accept arguments
}

bool VendingMachine::is_sold_out()
{
    return sold_out;
}

map<string, Product> VendingMachine::display_products()
{
    return products;
}

void VendingMachine::add_product(Product the_product)
{
    if(sold_out == false)
    {
        sold_out = false;
    }

    pair<map<string, Product>::iterator,bool> insert_return_pair; //A pair, of which the first element is an iterator that points to the possibly inserted pair, and the second is
                                                               // a bool that is true if the pair was actually inserted.
string product_name = the_product.getName();
    insert_return_pair = products.insert( pair<string, Product>(product_name, the_product));
}

 double VendingMachine::getChange()
  {
      return change;
  }

