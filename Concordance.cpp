#include "std_lib_facilities.h"
int main() {
    cout << "Enter words for concordance: \n";
	vector <string> words;
    string  word;

	for (string word ; cin >> word;)
		words.push_back(word);
	sort(words);

    int index = 0;
    string prev = words[index];
    int count = 0;
    while (index < words.size()){
        if (words[index] == prev){
            count++;
        }
        else{
            cout << prev << ": " << count << endl;
            prev = words[index];
            count = 1;
        }
        index++;
    }
    cout << prev << ": " << count << endl;

    keep_window_open();
    return 0;



}
