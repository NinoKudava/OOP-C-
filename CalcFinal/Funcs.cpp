#include <cmath>
#include "Funcs.h"
#include <functional>
#include <iostream>
#include <map>
#include <string>


using namespace std;

std::map <const string, std::function<double(double)> >dispTable{
    {"sin", [](double d) { return sin(d); }},
    {"cos", [](double d) { return cos(d); }},
    {"tan", [](double d) { return tan(d); }},
    {"asin", [](double d) { return asin(d); }},
    {"acos", [](double d) { return acos(d); }},
    {"atan", [](double d) { return atan(d); }},
    {"log", [](double d) { return log(d); }},
    {"log2", [](double d) { return log2(d); }},
    {"log10", [](double d) { return log10(d); }},
};

double exec_funct(string fname, double arg)
{
    try{
        return dispTable[fname](arg);
    }
    catch(exception){
        cout << "Error: Undefined function " << fname << '\n';
    }
    return 0.0;
}
