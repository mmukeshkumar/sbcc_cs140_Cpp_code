//---------------------------------------------------------------------------------------------------------------------
// Name        : product.h
// Author      : Mukesh Manirajkumar
// Version     : 1
// Copyright   : SBCC
// CS140, Assignment 8:Vending Machine simulation, Jackie Kuehn
// Description : This C++ header file has the Product class prototype, which defines the blueprint of the Product class
//----------------------------------------------------------------------------------------------------------------------

#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;

class Product
{
private:
  string name;
   string description;
  double price;
  int total_units;
  bool sold_out;
public:
  Product(); // Constructor

  ~Product(); // Destructor

  string get_name();
  double get_price();
  int get_total_units();
  string get_description();
  bool get_sold_out();

  void set_name(string);
    void set_description(string);
   void set_price(double);
    void set_total_units(int);
};
#endif // PRODUCT_H
