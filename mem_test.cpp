#include "std_lib_facilities.h"

int main(){
	int i = 0;
	while(true){
		double* dpler = new double[10000];
		cout << "loop " << i << endl;
		cout << dpler[i]<< endl;
		i++;
	}
}
