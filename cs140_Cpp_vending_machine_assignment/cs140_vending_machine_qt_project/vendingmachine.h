//--------------------------------------------------------------------------------------------------------------
// Name        : vendingmachine.h
// Author      : Mukesh Manirajkumar
// Version     : 1
// Copyright   : SBCC
// CS140, Assignment 8:Vending Machine simulation, Jackie Kuehn
// Description : This C++ header file has the VendingMachine class prototype, which defines the blueprint of the VendingMachine class
//--------------------------------------------------------------------------------------------------------------
#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <string>
#include <map>
#include "product.h"
#include "basevendingmachine.h"
using namespace std;
class VendingMachine: public BaseVendingMachine
{
private:
    static const int MAX_PRODUCT_COUNT = 8;
    bool admin_logged_in;
  map<string, Product*> products;// I am storing the product code as the key and the product object as the value
  bool sold_out_empty;
  double vending_machine_change;
  double customer_change;
  int total_item_count;
  int product_count;
  //This function will add a new product

protected:
public:
  VendingMachine();
  ~VendingMachine();

  //This function will display the the frequency of each word in the passed in file
const map<string, Product*> display_products();
   double add_change(int, Money);
    double add_customer_change(int, Money);
   void release_user_coins();
    void release_vending_machine_coins();
   bool is_sold_out_empty();
   double get_vending_machine_change();
   double get_customer_change();
   void set_admin_logged_in(bool);
   void reboot();
      bool get_admin_logged_in();
      bool bump_product_count();
      int get_product_count();
      void add_product(Product*);

      int get_max_product_count();
      bool buy_product(string);


};
#endif // VENDINGMACHINE_H
