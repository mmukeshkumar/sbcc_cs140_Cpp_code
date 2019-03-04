//----------------------------------------------------------------------------
// Name        : my_vending_machine_widget.cpp
// Author      : Mukesh Manirajkumar
// Version     : 1
// Copyright   : SBCC
// CS140, Assignment 8:Vending Machine simulation, Jackie Kuehn
// Description : This VendingMachineWidget C++ class implementation
//-----------------------------------------------------------------------------
#include <QtGui> 
#include "vendingmachinewidget.h"
#include "vendingmachine.h"
#include "customer.h"
#include "admin.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// including <QtGui> saves us to include every class user, <QString>, <QFileDialog>,...
VendingMachine * sbcc_vending_machine = new VendingMachine;
Customer * customer = new Customer;
Admin * admin = new Admin;

VendingMachineWidget::VendingMachineWidget(QWidget *parent)
{
	setupUi(this); // this sets up GUI

    this->setWindowTitle("Welcome, to SBCC Cs140 Vending Machine");

	// signals/slots mechanism in action
    //connect( pushButton_browse, SIGNAL( clicked() ), this, SLOT( getPath() ) );
	connect( pushButton_do, SIGNAL( clicked() ), this, SLOT( doSomething() ) ); 
	connect( pushButton_clear, SIGNAL( clicked() ), this, SLOT( clear() ) ); 
    connect( pushButton_about, SIGNAL( clicked() ), this, SLOT( about() ) );
   // connect( comboBox, SIGNAL( activated(QString) ), this, SLOT(on_combo_box_change() ) );
    connect( pushButton_admin_show, SIGNAL(  clicked()  ), this, SLOT(on_pushButton_admin_show_click() ) );
    connect( pushButton_insert_dollar, SIGNAL(  clicked()  ), this, SLOT(on_pushButton_insert_dollar_click() ) );
     connect( pushButton_insert_quater, SIGNAL(  clicked()  ), this, SLOT(on_pushButton_insert_quater_click() ) );
  connect( pushButton_insert_dime, SIGNAL(  clicked()  ), this, SLOT(on_pushButton_insert_dime_click() ) );
     //connect( pushButton_insert_dime, SIGNAL(  clicked()  ), this, SLOT(on_toolButton_product_1_click()  ) );
   connect( pushButton_product_1, SIGNAL(  clicked()  ), this, SLOT(on_pushButton_product_1_click() ) );

   connect( pushButton_product_2, SIGNAL(  clicked()  ), this, SLOT(on_pushButton_product_2_click() ) );


   connect( pushButton_release_coins, SIGNAL(  clicked()  ), this, SLOT(on_pushButton_release_coins_click() ) );

   connect( pushButton_add_product, SIGNAL(  clicked()  ), this, SLOT(on_pushButton_add_product_click() ) );


//  checkBox_yes_no->hide();
//  label_number_1->hide();
//  label_2_number_2->hide();
//  comboBox->hide();
//  spinBox1->hide();
//  spinBox2->hide();

  label_product_name->hide();
  label_Product_Price->hide();
  label_product_quantity->hide();
  lineEdit_product_name->hide();
  doubleSpinBox_product_price->hide();
  spinBox_product_quantity->hide();
  pushButton_add_product->hide();
  // hide the products
  pushButton_product_1->hide();
  pushButton_product_2->hide();
pushButton_product_3->hide();
pushButton_product_4->hide();
pushButton_product_5->hide();
pushButton_product_6->hide();
pushButton_product_7->hide();
pushButton_product_8->hide();

  textEdit->append( "The vending machine change is: " + QString::number(sbcc_vending_machine->get_vending_machine_change()));

}

void VendingMachineWidget::doSomething()
{
   // VendingMachine *sbcc_vending_machine = new VendingMachine;

//	int value1, value2;
//	Qt::CheckState state;
//	QString str;

    textEdit->clear();

    textEdit->hide();

     textEdit->show();

     textEdit->setReadOnly(true);
     map<string, Product*> m = sbcc_vending_machine->display_products();

     int size = m.size();
     textEdit->append( "Product count is : " + QString::number(size)) ;

    if(sbcc_vending_machine->is_sold_out_empty() == false)
    {
        textEdit->append( "The vending machine is not SOLD out: ") ;
    }
    if(sbcc_vending_machine->get_vending_machine_change() == 0.00)
    {
        textEdit->append( "The vending machine change is : zero") ;
    }
    else
    {
         textEdit->append( "The vending machine change is $:" + QString::number(sbcc_vending_machine->get_vending_machine_change())) ;

    }

    if(sbcc_vending_machine->get_customer_change() == 0.00)
    {
        textEdit->append( "The customer has zero change") ;
    }
    else
    {
         textEdit->append( "The customer has : $" + QString::number(sbcc_vending_machine->get_customer_change())) ;

    }


    //textEdit->append( "Path to file: " + lineEdit->text() );

//	value1 = spinBox1->value();
//	value2 = spinBox2->value();

//	textEdit->append( "Number 1 value: " + QString::number(value1) );
//	textEdit->append( "Number 2 value: " + QString::number(value2) );

//    state = checkBox_yes_no->checkState();

//	str = "Checkbox says: ";
//	if ( state == Qt::Checked ) str += "yes";
//	else str += "no";
//	textEdit->append( str );

//	textEdit->append( "ComboBox current text: " + comboBox->currentText() );
//    textEdit->append( "ComboBox current item: " + QString::number(comboBox->currentIndex()));
}


void VendingMachineWidget::clear()
{
	textEdit->clear();
}


void VendingMachineWidget::about()
{
    QMessageBox::about(this, "About Cs140 Vending Machine",
                             "This app was coded using Qt Creator, a C++ GUI toolkit, pronounced as Cute Creator.\n");
}


void VendingMachineWidget::on_pushButton_admin_show_click()
{

    if( pushButton_admin_show->text() == QString("Admin Logout") )
    {
        sbcc_vending_machine->set_admin_logged_in(false);
          textEdit->append( "Logged out as admin") ;
          pushButton_admin_show->setText(QString("Admin Login"));
          label_product_name->hide();
          label_Product_Price->hide();
          label_product_quantity->hide();
          lineEdit_product_name->hide();
          doubleSpinBox_product_price->hide();
          spinBox_product_quantity->hide();
           pushButton_add_product->hide();
    }
    else if(pushButton_admin_show->text() == QString("Admin Login"))
    {
        sbcc_vending_machine->set_admin_logged_in(true);
          textEdit->append( "Logged in as admin") ;
          pushButton_admin_show->setText(QString("Admin Logout"));
          label_product_name->show();
          label_Product_Price->show();
          label_product_quantity->show();
          lineEdit_product_name->show();
          doubleSpinBox_product_price->show();
          spinBox_product_quantity->show();
           pushButton_add_product->show();

    }
}

void VendingMachineWidget::on_pushButton_insert_dollar_click()
{
    textEdit->clear();
    if(sbcc_vending_machine->get_admin_logged_in() == true)
    {
           admin->add_dollars_to_vending_machine(1, sbcc_vending_machine, VendingMachine::Dollar);
            textEdit->append( "The vending machine now has: $" + QString::number(sbcc_vending_machine->get_vending_machine_change()));
    }
    else
    {
  customer->add_dollars(1, sbcc_vending_machine, VendingMachine::Dollar);
   textEdit->append( "The customer/user now has: $" + QString::number(sbcc_vending_machine->get_customer_change()));
    }  
   // QSound *sound = new QSound("C:\\Users\\coin.wav");
     QSound *sound = new QSound("coin.wav");
    sound->play();
}

void VendingMachineWidget::on_pushButton_insert_quater_click()
{
    textEdit->clear();
    if(sbcc_vending_machine->get_admin_logged_in() == true)
    {
           admin->add_dollars_to_vending_machine(1, sbcc_vending_machine, VendingMachine::Quater);
            textEdit->append( "The vending machine now has: $" + QString::number(sbcc_vending_machine->get_vending_machine_change()));
    }
    else
    {
  customer->add_dollars(1, sbcc_vending_machine, VendingMachine::Quater);
   textEdit->append( "The customer/user now has: $" + QString::number(sbcc_vending_machine->get_customer_change()));
    } 
   // QSound *sound = new QSound("C:\\Users\\coin.wav");
    QSound *sound = new QSound("coin.wav");
    sound->play();
}

void VendingMachineWidget::on_pushButton_insert_dime_click()
{
    textEdit->clear();
    if(sbcc_vending_machine->get_admin_logged_in() == true)
    {
           admin->add_dollars_to_vending_machine(1, sbcc_vending_machine, VendingMachine::Dime);
            textEdit->append( "The vending machine now has: $" + QString::number(sbcc_vending_machine->get_vending_machine_change()));
    }
    else
    {
  customer->add_dollars(1, sbcc_vending_machine, VendingMachine::Dime);
   textEdit->append( "The customer/user now has: $" + QString::number(sbcc_vending_machine->get_customer_change()));
    }
    QSound *sound = new QSound("C:\\Users\\coin.wav");
    sound->play();
}

void VendingMachineWidget::on_pushButton_product_1_click()
{
//    textEdit->clear();
//   // sbcc_vending_machine->add_change(1,VendingMachine::Quater);
//bool result = sbcc_vending_machine->buy_product(pushButton_product_1->text().toStdString());

//    if(result == true )
//    {
//        QSound *sound = new QSound("C:\\Users\\bang_5.wav");
//        sound->play();

//        textEdit->append( "Here is your "+pushButton_product_1->text() +", enjoy!");
//        textEdit->append( "Here is your change "+ QString::number(sbcc_vending_machine->get_customer_change()));
//    }
//    else
//    {
//        textEdit->append( "Sorry, either the product is sold out or you do not have enough money");

//    }
    textEdit->clear();

bool result = sbcc_vending_machine->buy_product(pushButton_product_1->text().toStdString());
display_buying_result(result,pushButton_product_1 );
}

void VendingMachineWidget::on_pushButton_product_2_click()
{
    textEdit->clear();

bool result = sbcc_vending_machine->buy_product(pushButton_product_2->text().toStdString());
display_buying_result(result,pushButton_product_2 );
}

void VendingMachineWidget::on_pushButton_product_3_click()
{
    textEdit->clear();
bool result = sbcc_vending_machine->buy_product(pushButton_product_3->text().toStdString());
display_buying_result(result,pushButton_product_3 );

}


void VendingMachineWidget::on_pushButton_product_4_click()
{
    textEdit->clear();
bool result = sbcc_vending_machine->buy_product(pushButton_product_4->text().toStdString());
display_buying_result(result,pushButton_product_4 );

}


void VendingMachineWidget::on_pushButton_product_5_click()
{
    textEdit->clear();
bool result = sbcc_vending_machine->buy_product(pushButton_product_5->text().toStdString());
display_buying_result(result,pushButton_product_5 );

}


void VendingMachineWidget::on_pushButton_product_6_click()
{
    textEdit->clear();
bool result = sbcc_vending_machine->buy_product(pushButton_product_6->text().toStdString());
display_buying_result(result,pushButton_product_6 );

}


void VendingMachineWidget::on_pushButton_product_7_click()
{
    textEdit->clear();
bool result = sbcc_vending_machine->buy_product(pushButton_product_7->text().toStdString());
display_buying_result(result,pushButton_product_7 );

}


void VendingMachineWidget::on_pushButton_product_8_click()
{
    textEdit->clear();
bool result = sbcc_vending_machine->buy_product(pushButton_product_8->text().toStdString());
display_buying_result(result,pushButton_product_8 );

}


void VendingMachineWidget::display_buying_result(bool the_result, QPushButton* the_product_button)
{
    if(the_result == true )
    {
        //QSound *sound = new QSound("C:\\Users\\bang_5.wav");
        QSound *sound = new QSound("bang_5.wav");
        sound->play();

        textEdit->append( "Here is your "+the_product_button->text() +", enjoy!");
        textEdit->append( "Here is your change $"+ QString::number(sbcc_vending_machine->get_customer_change()));
    }
    else
    {
        textEdit->append( "Sorry, either the product is sold out or you do not have enough money");

    }
}

void VendingMachineWidget::on_pushButton_release_coins_click()
{
    textEdit->clear();
   // sbcc_vending_machine->add_change(1,VendingMachine::Quater);

    if(sbcc_vending_machine->get_admin_logged_in() == true)
    {
           admin->release_vending_machine_coins(sbcc_vending_machine);
            textEdit->append( "The vending machine now has: $" + QString::number(sbcc_vending_machine->get_vending_machine_change()));
    }
    else
    {
        customer->release_customer_coins(sbcc_vending_machine);
         textEdit->append( "The customer/user now has: $" + QString::number(sbcc_vending_machine->get_customer_change()));

    }

   // QSound *sound = new QSound("C:\\Users\\release_coins.wav");
     QSound *sound = new QSound("release_coins.wav");
    sound->play();
sbcc_vending_machine->release_user_coins();
    textEdit->append( "The vending machine now has: $0.00");

}



void VendingMachineWidget::on_pushButton_add_product_click()
{

    if(sbcc_vending_machine->get_product_count()>= sbcc_vending_machine->get_max_product_count())
    {
        textEdit->append( "ERROR: Cannot add more than, " + QString::number(sbcc_vending_machine->get_max_product_count()) + " products");
    }
    else
    {

        sbcc_vending_machine->bump_product_count();
           QString product_name = lineEdit_product_name->text();
           int product_item_count = spinBox_product_quantity->value();

            double product_price = doubleSpinBox_product_price->value();
            textEdit->append( "The product name is : $" + product_name);
            textEdit->append( "The product price is : $" + QString::number(product_price));
             textEdit->append( "The product items count is : " + QString::number(product_item_count));

             Product *new_product = new Product;
             new_product->set_name(product_name.toStdString());
              new_product->set_price(product_price);
                new_product->set_total_units(product_item_count);

                sbcc_vending_machine->add_product(new_product);
       int counter = sbcc_vending_machine->get_product_count();
       switch(counter)
       {
             case 1:
           pushButton_product_1->setText(product_name);
             pushButton_product_1->show();
             break;
             case 2:
              pushButton_product_2->setText(product_name);
             pushButton_product_2->show();
             break;
             case 3:
              pushButton_product_3->setText(product_name);
            pushButton_product_3->show();
              break;
            case 4:
            pushButton_product_4->setText(product_name);
             pushButton_product_4->show();
             break;
             case 5:
            pushButton_product_5->setText(product_name);
             pushButton_product_5->show();
             break;
             case 6:
            pushButton_product_6->setText(product_name);
             pushButton_product_6->show();
             break;
            case 7:
             pushButton_product_7->setText(product_name);
            pushButton_product_7->show();
             break;
             case 8:
            pushButton_product_8->setText(product_name);
             pushButton_product_8->show();
             break;

          }
                textEdit->append( "The product name is : " + product_name + " was added");

    }

}
