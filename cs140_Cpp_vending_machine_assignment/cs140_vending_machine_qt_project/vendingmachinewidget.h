//#ifndef VendingMachineWidget_H
//#define VendingMachineWidget_H

#include "ui_vendingmachine.h"

class VendingMachineWidget : public QWidget, private Ui::my_vending_machine_widget
{
	Q_OBJECT

public:
    VendingMachineWidget(QWidget *parent = 0);

public slots:

	void doSomething();
	void clear();
	void about();
   void on_pushButton_insert_dime_click();
    void on_pushButton_admin_show_click();
    void on_pushButton_insert_dollar_click();
    void on_pushButton_insert_quater_click();
    void on_pushButton_product_1_click();
     void on_pushButton_product_2_click();
     void on_pushButton_product_3_click();
     void on_pushButton_product_4_click();
     void on_pushButton_product_5_click();
    void on_pushButton_product_6_click();
    void on_pushButton_product_7_click();
    void on_pushButton_product_8_click();
    void on_pushButton_release_coins_click();
    void on_pushButton_add_product_click();


    void display_buying_result(bool, QPushButton*);

};


//#endif
