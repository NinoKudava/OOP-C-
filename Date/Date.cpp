

#include "Date.h"

Date::Date(int yy, int mm, int dd)
:y{yy}, m{mm}, d{dd}
{
   if(!is_valid()) throw Invalid{};

}

vector<int> last_day{0,31,28,31,30,31,30,31,31,30,31,30,31};
vector<int> leap_last_day{0,31,29,31,30,31,30,31,31,30,31,30,31};




bool Date::leap_year(){
    if((y%100!=0 && y%4==0) || y%400==0 ) return true;
    return false;
}



Date Date::add_day(int n){
    int d1 = d;
    int m1 = m;
    int y1 = y;

    vector<int> last_day{0,31,28,31,30,31,30,31,31,30,31,30,31};
    vector<int> leap_last_day{0,31,29,31,30,31,30,31,31,30,31,30,31};
    if(leap_year()==false){
        while(n>0){
            int i = d1;
            while(i<=last_day[m1] && i>=d1){

                if(n==0) break;
                if(i==last_day[m1] && m1==12){
                    y1++;
                    m1=1;
                    d1=0;
                    i=d1;

                }else{
                    if(i==last_day[m1]){
                        d1 = 0;
                        m1=m1+1;
                        i=d1;
                    }

                }
                d1++;
                i = d1;
                n--;
            }

        }
    }else{
        while(n>0){
            int i = d1;
            while(i<=leap_last_day[m1] && i>=d1){

                if(n==0) break;
                if(i==leap_last_day[m1] && m1==12){
                    y1++;
                    m1=1;
                    d1=0;
                    i=d1;

                }else{
                    if(i==leap_last_day[m1]){
                        d1 = 0;
                        m1 = m1 +1;
                        i = d1;
                    }
                }
                d1++;
                i = d1;
                n--;
            }

        }
    }
    Date todayNew = Date(y1,m1,d1);
    return todayNew;
}




int Date::month()const{
    return m;
}

int Date::year()const{
    return y;
}

int Date::day()const{
    return d;
}

string Date::month_name() const{
    vector<string> month_names = {" ","January","February","March", "April", "May","June","July", "August", "September", "October", "November", "December"};
    return month_names[m];
}


bool Date::is_valid(){
    if (m<1 || m>12) return false;
    if (d>31 || d<1) return false;
    if (m==4 && d>30) return false;
    if (m==6 && d>30) return false;
    if (m==9 && d>30) return false;
    if (m==11 && d>30) return false;
    if(leap_year()==true && m==2 && d>29) return false;
    if(leap_year()==false && m==2 && d>28) return false;
    return true;
}


ostream& operator<< (ostream& os,const Date& d){

    return os << d.month_name() << " " << d.day() <<", " << d.year() << endl;
}

bool operator== (const Date& d, const Date& d2){
    if(d.day()==d2.day() && d.month()==d2.month() && d.year()==d2.year()) return true;
return false;
}

bool operator!=(const Date& d, const Date& d2){
    if (d.day()!=d2.day() || d.month()!=d2.month() || d.year()!=d2.year()) return true;
return false;
}





