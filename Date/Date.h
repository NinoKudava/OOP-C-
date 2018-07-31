#include "std_lib_facilities.h"

enum class Month{
jan=1,feb, mar,apr,may,jun,jul,aug,sep,oct,nov,dec
};

class Date{
public:
    class Invalid{};
    Date(int y, int m, int d);
    Date add_day(int n);
    bool leap_year();
    int month() const;
    int year() const;
    int day() const;
    string month_name() const;
private:
    int y,d,m;

    vector<int> last_day;

    bool is_valid();

    vector<string> month_names;
};

ostream& operator << (ostream& os, const Date& d);
bool operator== (const Date& d, const Date& d2);
bool operator!=(const Date& d, const Date& d2);
