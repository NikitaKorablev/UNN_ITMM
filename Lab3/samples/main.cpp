#include <string>
#include <iostream>
#include "Calculate.h"
using namespace std;

int main() {
	string str = "( 123 -10/5)/50 * 30 \n";
//    string str = "50/(123 -10) * 30 \n";
//    string str = "15 * 3 + 5 - 15 / 3";
    cout << str;

    Calculate calc(str);
    calc.fullShow();
//    calc.show();
	return 0;
}