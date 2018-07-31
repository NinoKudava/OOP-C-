#include "std_lib_facilities.h"

struct Reading { // a temperature reading
    int temp1; // hour after midnight [0:23]
    double temp2;// in Fahrenheit
    double temp3;
    char sep1;
    char sep2;
};

int main()
{
    cout << "Please enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ist {iname}; // ist reads from the file named iname
    cout << ist << endl;
    if (!ist) error("can't open input file ",iname);

    string oname;
    cout << "Please enter name of output file: ";
    cin >> oname;
    ofstream ost {oname}; // ost writes to a file named oname
    if (!ost) error("can't open output file ",oname);

    vector<Reading> temps; // store the readings here
    int temp1;
    double temp2;
    double temp3;
    char sep1;
    char sep2;

    while (ist >> temp1 >> sep1 >>  temp2 >> sep2 >> temp3) {

        temps.push_back(Reading{temp1,temp2,temp3});
    }
    for (int i=0; i<temps.size(); ++i){
        ost << ' ' << temps[i].temp1 << ' '
              << temps[i].temp2 << ' ' << temps[i].temp3 << " \n";
    }
}
