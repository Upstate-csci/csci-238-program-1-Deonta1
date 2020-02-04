/********
 Author:
 Program: Money class - program assignment #1
 Due Date:
 Purpose:
 ********/
#include "money.h"


// convert current currency values to a string
string Money::toString() {
    return "";
}

// format amount as a local currency and return
string Money::toCurrency(double amount) {

    stringstream ss;
    ss.imbue(locale(""));

    ss << "$" << left << setfill('0') << setw(4) << amount;

    return ss.str();

}

// convert currency to float
// read currency values from stdin and compute value
// return results
string Money::processChange() {
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents;
    total = (hundreds * 100) + (tens * 10) + (fives * 5) + (ones * 1) + (quarters * 0.25) + (dimes * 0.10) + (nickels * 0.05) + (cents * 0.01);
    return to_string(hundreds) + " hundreds " + to_string(tens)
           + " tens " + to_string(fives) + " fives " + to_string(ones)
           + " ones " + to_string(quarters) + " quarters " + to_string(dimes)
           + " dimes " + to_string(nickels) + " nickels " + to_string(cents)
           + " pennies = " + toCurrency(total);
}

// read from stdin and process float command
// convert float to change
// return results
string Money::processFloat() {
    float amount;
    cin >> amount;
    int amountInt = (int) (amount*100);

    std::ostringstream streamObj;
    streamObj << fixed << std::setprecision(2);
    streamObj << amount;
    std::string strObj = streamObj.str();

    hundreds = amountInt / 10000;
    tens = (amountInt % 10000) / 1000;
    fives = ((amountInt % 10000) % 1000) / 500;
    ones = (((amountInt % 10000) % 1000) % 500) / 100;
    quarters = ((((amountInt % 10000) % 1000) % 500) % 100) / 25;
    dimes = (((((amountInt % 10000) % 1000) % 500) % 100) % 25) / 10;
    nickels = ((((((amountInt % 10000) % 1000) % 500) % 100) % 25) % 10) / 5;
    cents = (((((((amountInt % 10000) % 1000) % 500) % 100) % 25) % 10) % 5) / 1;

    return toCurrency(amount) + " = " + to_string(hundreds) + " hundreds " + to_string(tens) + " tens "
           + to_string(fives) + " fives " + to_string(ones) + " ones " + to_string(quarters) + " quarters "
           +to_string(dimes) + " dimes " + to_string(nickels) + " nickels " + to_string(cents) + " pennies ";
}

// read from stdin and process check command
// convert float to dollar words & cents
// return results
string Money::processCheck() {
    return "";
}

// read from stdin and process change-float command
// read float of customer payment
// read float of transaction cost
// calculate difference and compute change values
// return the results
string Money::processChangeFloat() {
    return "";
}

// read from stdin and process change-change command
// read change of customer payment
// read float of transaction cost
// calculate difference and compute change values
// output the results
string Money::processChangeChange() {

    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents >> price;
    total = (hundreds * 100) + (tens * 10) + (fives * 5) + (ones * 1) + (quarters * 0.25) + (dimes * 0.10) + (nickels * 0.05) + (cents * 0.01) + (price * 1);

    total1 = (100 - price);
    int total1Int = (int) (total1*100);


    /*float total1 ;
    cout << total1;
    int total1Int = (int) (total1*100);

    std::ostringstream streamObj;
    streamObj << fixed << std::setprecision(2);
    streamObj << total1;
    std::string strObj = streamObj.str();*/

    hundreds1 = (total1Int / 10000);
    tens1 = (total1Int % 10000) / 1000;
    fives1 = ((total1Int % 10000) % 1000) / 500;
    ones1 = (((total1Int % 10000) % 1000) % 500) / 100;
    quarters1 = ((((total1Int % 10000) % 1000) % 500) % 100) / 25;
    dimes1 = (((((total1Int % 10000) % 1000) % 500) % 100) % 25) / 10;
    nickels1 = ((((((total1Int % 10000) % 1000) % 500) % 100) % 25) % 10) / 5;
    cents1 = (((((((total1Int % 10000) % 1000) % 500) % 100) % 25) % 10) % 5) / 1;


    return "change back on " + to_string(hundreds) + " hundreds " + to_string(tens)
                  + " tens " + to_string(fives) + " fives " + to_string(ones)
                  + " ones " + to_string(quarters) + " quarters " + to_string(dimes)
                  + " dimes " + to_string(nickels) + " nickels " + to_string(cents)
                  + " pennies for purchase of " + toCurrency(price) + " is " + toCurrency(total1) + " which is "
                  + to_string(hundreds1) + " hundreds " + to_string(tens1) + " tens "
                     + to_string(fives1) + " fives " + to_string(ones1) + " ones " + to_string(quarters1) + " quarters "
                     +to_string(dimes1) + " dimes " + to_string(nickels1) + " nickels " + to_string(cents1) + " pennies ";
}
