/********
 Author:
 Program: Money class - program assignment #1
 Due Date:
 Purpose:
 ********/
#ifndef MONEY_H
#define MONEY_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <locale>

using namespace std;
class Money
{
private:
    double total, price, total1;
    int hundreds, tens, fives, ones, quarters, dimes, nickels, cents, hundreds1, tens1, fives1, ones1, quarters1, dimes1, nickels1, cents1  ;
public:
    string toString();
    string toCurrency(double amount);
    string processChange();
    string processFloat();
    string processCheck();
    string processChangeFloat();
    string processChangeChange();
};

// format amount as a local currency and return


#endif
