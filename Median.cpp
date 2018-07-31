#include "std_lib_facilities.h"

int main()
{
	cout << "Enter recent temperatures and we will calculate their average: \n";

	vector<double> temps;

	for(double temp; cin>>temp;)
		temps.push_back(temp);
	sort(temps);
	double total = 0.0;
	for(double temp: temps)
		total += temp;


	double median = 0.0;
	if(temps.size()%2==0){
	    median = (temps[temps.size()/2 -1] + temps[temps.size()/2 ])/2;
	    }
	 else{
	     median = temps[temps.size()/2 ];
	 }
    cout << "Your median temperature for the last " << temps.size() << " days was " << median << endl;
	double mean = total/temps.size();
	cout << "You mean temperature for the last " << temps.size() << "days was" << mean << '\n';
	return 0;

}
