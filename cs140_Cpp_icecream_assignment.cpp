//============================================================================
// Name        : Cs140IceCreamAssignment.cpp
// Author      : Mukesh Manirajkumar
// Version     : 1.0
// Copyright   : SBCC 2012
// Description : Ice vendor simulation program in C++, Ansi-style
//Class: CS140, Jackie Kuehn, Program Assignment 2
//============================================================================
// #include "stdafx.h"
#include <iostream>
#include <string>
//#include <cctype>
using namespace std;

//function declarations
void
printWelcome(int maxCones);
bool
validateFlavor(string flavor);
bool
validateNumberOfCones(int numberOfCones, int maxCones);
bool
validateNumberOfScoops(int numberOfScoops, int maxScoops);
bool
printASCIIRepresentationOfCone(int numberOfScoops, int coneNumber,
                               string scoopFlavors[]);
float
calculateTotalCharge(int numberOfCones, int noOfScoops[]);
float
calculateChargeForOneCone(int numberOfScoops);
void
printTotalCharge(int numberOfCones, int numberOfScoops[]);
int
exitProgram(int exiter);

int
main()
{
    // constants declarations
    const int MAXSCOOPS = 5;
    const int MAXCONES = 10;
    //variable declarations
    int exiter = 0;
    string userInput = "";
    int numberOfCones;
    int numberOfScoops;
    //array variable declarations
    string scoopFlavors[MAXSCOOPS]; // array to hold the flavors inputted
    int noOfScoopsForEachCone[MAXCONES]; // array to hold the number of scoops entered for each cone

    printWelcome(MAXCONES);
    cin >> numberOfCones;

    if (validateNumberOfCones(numberOfCones, MAXCONES))
    {
        for (int i = 1; i <= numberOfCones; i++)
        {
            cout << "Total cones inputted is : " << numberOfCones << endl;

            cout << "Enter the number of scoops you like for cone #" << i
                 << " , (limit " << MAXSCOOPS << " scoops per cone): " << endl;
            cin >> numberOfScoops;
            if (validateNumberOfScoops(numberOfScoops, MAXSCOOPS))
            {
                noOfScoopsForEachCone[i - 1] = numberOfScoops;
                if (printASCIIRepresentationOfCone(numberOfScoops, i,
                                                   scoopFlavors) == false)
                {
                    // inputted flavor was more than 0ne character long, so program will exit
                    return exitProgram(exiter);
                }
            }
            else
            {
                //Invalid numberOfScoops entered so exit the program
                return exitProgram(exiter);
            }
        }
// now finally calculate and print the total charge
        printTotalCharge(numberOfCones, noOfScoopsForEachCone);
        return exitProgram(exiter);
    }
    else
    {
        //Invalid numberOfCones entered, so exit the program
        return exitProgram(exiter);
    }
}

//This function validates the number of cones inputted by the user
bool
validateNumberOfCones(int numberOfCones, int maxCones)
{
    if (cin.fail())
    {
        cerr << "Input was not an integer" << endl;
        cout << "Please try again, goodbye" << endl;
        return false;
    }
    if (numberOfCones < 1)
    {
        cerr << "Error message: The number of cones should be atleast 1, "
             << endl;
        cout << "Please try again, goodbye" << endl;
        return false;
    }
    else if (numberOfCones > maxCones)
    {
        cerr
                << "Error message: The number of cones you entered is greater than the maximum allowed cones, which is : "
                << maxCones << endl;
        cout << "Please try again, goodbye" << endl;
        return false;
    }

    return true;
}

//This function validates the number of scoops inputted by the user
bool
validateNumberOfScoops(int numberOfScoops, int maxScoops)
{
    if (cin.fail())
    {
        cerr << "Input was not an integer" << endl;
        cout << "Please try again, goodbye" << endl;
        return false;
    }
    else
    {
        cout << "Input was: " << numberOfScoops << endl;
    }

    if (numberOfScoops < 1)
    {
        cerr << "Error message: The number of scoops should be atleast 1, "
             << endl;
        cout << "Please try again, goodbye" << endl;
        return false;
    }
    else if (numberOfScoops > maxScoops)
    {
        cerr
                << "Error message: The number of scoops you entered is greater than the maximum allowed scoops, which is : "
                << maxScoops << endl;
        cout << "Please try again, goodbye" << endl;
        return false;
    }

    return true;
}

//This function prints the ASCII representation of the cone
bool
printASCIIRepresentationOfCone(int numberOfScoops, int coneNumber,
                               string scoopFlavors[])
{
    string flavor;
    for (int i = 1; i <= numberOfScoops; i++)
    {
        cout << "Specify the flavor for scoop #" << i
             << " (max 1 character in length): " << endl;
        cin >> flavor;
        if (validateFlavor(flavor) == false)
        {
            return false;
        }
        scoopFlavors[i - 1] = flavor;
    }
    cout << "Here is your yummy cone#" << coneNumber << " , Enjoy!!!" << endl;
    for (int j = 0; j < numberOfScoops; j++)
    {
        cout << " ( " << scoopFlavors[j] << " )" << endl;
    }
    cout << "  \\ /" << endl;
    cout << "   |" << endl;
    return true;
}

//This function calculates the total charge of the cones
float
calculateTotalCharge(int numberOfCones, int noOfScoops[])
{
    float totalCharge;
    for (int j = 0; j < numberOfCones; j++)
    {
        totalCharge += calculateChargeForOneCone(noOfScoops[j]);
    }

    return totalCharge;
}

//This function calculates the total charge of 1 icecream cone
float
calculateChargeForOneCone(int numberOfScoops)
{
    if (numberOfScoops == 1)
    {
        return 2;
    }
    else if (numberOfScoops == 2)
    {
        return 3;
    }
    else
    {
        // logic to calculate total charge = (no of extra scoops * 0.75) + $3 for the first 2 scoops
        return (numberOfScoops - 2) * 0.75 + 3;
    }
}

//This function prints the total charge
void
printTotalCharge(int numberOfCones, int noOfScoops[])
{
    cout << "=======================" << endl;
    cout << "Total Charge is: $"
         << calculateTotalCharge(numberOfCones, noOfScoops) << endl;
    cout << "=======================" << endl;
}
//This function prints the exit message and then exits the program
int
exitProgram(int exiter)
{
    cout
            << "Press Control-C or Press any key(other than enter) and hit enter to exit "
            << endl;
    cin >> exiter;
    return 0;
}

// This functions validates the ice cream scoop flavor
bool
validateFlavor(string flavor)
{
    if (flavor.length() > 1)
    {
        cerr << "Flavor inputted was more than 1 character in length, " << endl;
        //cout << "Please try again, goodbye" << endl;
        return false;
    }

    return true;
}

// This functions prints the welcome message
void
printWelcome(int maxCones)
{
    cout << "=======================================================" << endl;
    cout << "Welcome, this program simulates an ice cream vendor!" << endl; // prints welcome message
    cout << "=======================================================" << endl;
    cout << "1 scoop            ->  $2.00" << endl;
    cout << "2 scoops           ->  $3.00" << endl;
    cout << "each scoop after 2 ->  $0.75" << endl;
    cout << "" << endl;
    cout << "Enter the number of cones you wish to purchase, (" << maxCones
         << " max) : " << endl;
}
