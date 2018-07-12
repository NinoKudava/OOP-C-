#include "std_lib_facilities.h"
using namespace std;

int main(){
	cout << "Please enter left number then operator and then right value \n";
	int lval = 0;
	int rval;
	char op;
	int res;

	cin>> lval;
	if(!cin) { 
		error("What you entered is not a number");
	}
	for(char op : cin>>op){
		if(op!='x')
			cin>>rval;
			if(!cin){
				error("What you typed is not a number")
			}
			switch(op){
				case '+':
					res = lval + rval;
					break;
				case '-':
					res = rval - lval;
					break;
				case '*':
					res = rval*lval;
					break;
			}

	}
	cout << res <<endl;
	return 0;
}