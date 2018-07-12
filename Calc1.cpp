#include "std_lib_facilities.h"
using namespace std;

#include "std_lib_facilities.h"
int main() {
	cout << "Please enter left number then operator and then right value \n";
	int lval = 0;
	int rval;
	char op;
	int res;

	cin>> lval >> op >> rval;
	if (op=='-'){
		res = rval - lval;
	}if(op=='+'){
		res = rval+lval; 
	}
	cout << res <<endl;
	return 0;
}