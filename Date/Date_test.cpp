

#include "Date.h"


int main(){

    char par1;
    char par2;
    char com1;
    char com2;
    int year;
    int month;
    int date;


    Date defaultDate(2000,01,01);
    cout << "The default date is: " << defaultDate;
    cout << endl;
    cout << "Please enter a date in format (YYYY,MM,DD): " << endl;
    cin >> par1 >> year >> com1 >> month >> com2 >> date >> par2;



    Date today(year,month,date);
    cout << "The date you entered is: " << today << endl;


    int addDays;
    cout << "Please enter a number of the days to add to the current date: " << endl;
    cout << "(The number can be any amount of days, months, years in units of days wished)" << endl;
    cin >> addDays;


    today= today.add_day(addDays);
    cout << "The date with the added days is: " << today << endl;

    cout << "Enter date to compare the current date to the entered date: (YYYY,MM,DD) " << endl;
    cin >> par1 >> year >> com1 >> month >> com2 >> date >> par2;
    Date tomorrow(year, month, date);
    cout<< "If days are the same the output will be 1 else it will be 0: " << endl;
    cout << (today!=tomorrow) << endl;

    return 0;
}

