#include <string>
#include <iostream>
#include "Calculate.h"
using namespace std;

int main() {
//	string str = "( 123 -10)/50 * 30 \n";
    string str = "50/( 123 -10) * 30 \n";
	cout << str;

    Calculate calc(str);
    print(calc.getLex());
    cout << endl;
    print(calc.getSynt());
    cout << calc.getRes() << endl;

//    Stack<Lexema> st;
//    Lexema l("123", Value);
//    st.push(l);
//    st.push(l);
//    st.push(l);
	return 0;
}