const char invalid = 'i';
const char name = 'a';
const char number = '8';
const char quit = 'q';
const char print = ';';
const char power = '^';
const char mod = '%';


const string prompt = "> ";
const string result = "= ";



class Token {
    public:
        char kind;
        double val;
        string name;
        Token(char ch) :kind{ch}{}
        Token(char ch, double val) :kind{ch}, val{val}{}
        Token(char ch, string n) :kind{ch}, name{n} {}
};

class Token_stream{
    public:
        Token get();
        void putback(Token t);
        void ignore(char c);
        Token popback();
    private:
        vector<Token> buffer;
};
