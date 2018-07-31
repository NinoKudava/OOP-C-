
#include "Date.h"


int main(){

    char par1;
    char par2;
    char com1;
    char com2;
    int year;
    int month;
    int date;



    cout << "Please enter a date in format (YYYY,MM,DD): " << endl;
    cin >> par1 >> year >> com1 >> month >> com2 >> date >> par2;



    Date today(year,month,date);
    //Date tomorrow(1990,1,1);

    today= today.add_day(400);




   cout << today << endl;

   //cout << (today!=tomorrow) << endl;

    return 0;
}

