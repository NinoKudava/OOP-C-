#include "std_lib_facilities.h"

class vect2{

		int sz;
		double* elem;
	public:
		vect2(int s)
			:sz{s}, elem{new double [s]} {}
		~vect2()
			{delete elem;}

		    double get(int i){ return elem[i];}
		    void set(int i, double d){elem[i]=d;}


    vect2(const vect2& arg)
    // allocate space, then initialize via copy
        :sz{arg.sz}, elem{new double[arg.sz]}
        {
        copy(arg.elem, arg.elem+arg.sz, elem);  // from std lib
    }

    vect2& operator=(const vect2& a)
    // make this vector a copy of a
        {
        double* p = new double[a.sz];
        copy(a.elem, a.elem+a.sz, p);
        delete[] elem;
        elem = p;
        sz = a.sz;
        return *this;  // return self-ref
    }

};

void f(int n){
    vect2 v(3);
    v.set(2,2.2);
    vect2 v2 = v;
    v.set(1,9.9);
    v2.set(0,8.8);
    cout << v.get(0) << ' ' << v2.get(1);
}




int main(){
    while(true)
        f(10);
}
