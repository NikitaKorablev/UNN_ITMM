#include <string>
#include <iostream>
#include "Suntax.h"
using namespace std;

int main() {
	string str = "( 123 -10)/ 50 * 30 \n";
	cout << str;
	queue <Lexema> lex_res;
	lex_res = lex(str);
	print(lex_res);
    print(sunt(lex_res));
	return 0;
}