#include <QApplication>
#include "vendingmachinewidget.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    VendingMachineWidget *vending_machine = new VendingMachineWidget;
    vending_machine->show();
//  //  cout << "Hello" << endl;
//    double x = 12.0;
//       cout.precision(2);              // Precision 2
//       cout << " By default:   " << x << endl;
//       cout << " showpoint:  " << showpoint  << x << endl;
//       cout << " fixed:      " << fixed      << x << endl;
//       cout << " scientific: " << scientific << x << endl;
//
    return app.exec();
}

