#include "std_lib_facilities.h"
#include "Token.h"
#include "Vars.h"
#include "Funcs.h"

double statement(Token_stream& ts);
double term(Token_stream& ts);
double primary(Token_stream& ts);
double expon(Token_stream& ts);
double expression(Token_stream& ts);

double statement(Token_stream& ts){
    Token t = ts.get();
    if(t.kind == name){
        Token var = t;
        t = ts.get();
        if (t.kind == '='){
            double d = expression(ts);
            set_value(var.name,d);
            return d;
        }
        else if(t.kind == print){
            ts.putback(t);
            return get_value(var.name);
        }
        ts.putback(t);
        ts.putback(var);
        return expression(ts);
    }
    ts.putback(t);
    return expression(ts);
}


double expression(Token_stream& ts){
    double left = term(ts);
    Token t = ts.get();

    while (true){
        switch(t.kind){
        case '+':
            left += term(ts);
            t = ts.get();
            break;
        case '-':
            left -= term(ts);
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;

        }
    }
}

double term(Token_stream& ts){
    double left = expon(ts);
    Token t = ts.get();

    while(true){
        switch(t.kind){
        case '*':
            left *= expon(ts);
            t = ts.get();
            break;
        case '/':
            {
            double d = expon(ts);
            if (d==0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;

            }
        case '%':{
            double d = expon(ts);
            if (d==0) error("divide by zero");
            left = fmod(left,d);
            t = ts.get();
            break;
        }
        default:
        ts.putback(t);
        return left;

        }
    }
}
double expon(Token_stream& ts){
    double left = primary(ts);
    Token t = ts.get();
    if (t.kind == power){
        double d = primary(ts);
        return pow(left, d);
    }
    else{
        ts.putback(t);
        return left;
    }
}


double primary(Token_stream& ts){
        Token t = ts.get();
    switch(t.kind){
    case '(':
        {
        double d = expression(ts);
        t = ts.get();
        if (t.kind!= ')') error("')' expected");
            return d;
        }
    case number:
        return t.val;
    case name:
        {
            Token next_t = ts.get();
            if (next_t.kind == '(') {
                double d = expression(ts);
                next_t = ts.get();
                if (next_t.kind != ')') throw runtime_error("')' expected");
                d = exec_funct(t.name,d);
                return d;
            }
            else{
                ts.putback(next_t);
                return get_value(t.name);
            }
        }
    case '-':
        return -(primary(ts));
    case '+':
        return primary(ts);
    default:
        string s(1, t.kind);
        throw runtime_error("Primary expected; got: " +s);
    }
    return 0.0;
}

void clean_up_mess(Token_stream& ts){
    ts.ignore(print);
}


void calculate(Token_stream& ts){
    while (cin){
       try{
        cout << prompt;
        Token t = ts.get();
        //cout << "in calculate(), got token: " << t.kind << " with val of "<< t.val << '\n';
        while (t.kind == print) t = ts.get();
       if (t.kind == quit) return;
       ts.putback(t);
      cout << setprecision(10) <<  result << statement(ts)<< '\n';
    }
    catch(exception& e){
        cerr << e.what() << '\n';
        clean_up_mess(ts);
        }
    }
}
int main(){
    Token_stream ts;
    cout << "Please enter an expression: " << endl;
    try{
        calculate(ts);
        return 0;
    }
    catch(...){
        cerr << "Exception \n";
        return 2;
    }

}
