#include "std_lib_facilities.h"
#include "token.h"


int main()
{
    vector<Token> tokens;
    Token_stream ts;

    for(Token t = ts.get(); t.kind != quit; t = ts.get()) {
    	tokens.push_back(t);
	}

	for(Token tok : tokens) {
        if(tok.kind == number)
		    cout << "A number token with val = " << tok.val << '\n';
        else if(tok.kind == invalid)
		    cout << "We received an invalid token of value "
                << char(tok.val) << '\n';
        else if(tok.kind == name)
		    cout << "A variable token with name " << tok.name << '\n';
        else
		    cout << "A token of kind " << tok.kind << '\n';
	}
    return 0;
}
