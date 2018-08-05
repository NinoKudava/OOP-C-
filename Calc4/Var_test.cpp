#include "std_lib_facilities.h"
#include "vars.h"

int main(){

    set_value("abc",10.0);
    set_value("acb",11.0);
    set_value("bac", 12.2);
    set_value("cba",5.0);


double d;
d = get_value("abc");
cout << "abc = " << d << endl;

d = get_value("acb");
cout << "acb = " << d << endl;

d = get_value("bac");
cout << "bac = " << d << endl;

d = get_value("cba");
cout << "cba = " << d << endl;

}
