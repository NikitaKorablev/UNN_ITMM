//
// Created by nikita on 11/25/22.
//

#ifndef PARSER_CALCULATE_H
#define PARSER_CALCULATE_H

#include "Suntax.h"

double calc(queue<Lexema> synt) {
    stack<double> numbers;
    int len = synt.size();
    double a, b;
    for (int i = 0; i < len; i++) {
        if (synt.front().getType() == Value) {
            numbers.push(stod(synt.front().getStr()));
        } else if (synt.front().getType() == Operation) {
            b = numbers.top(); numbers.pop();
            a = numbers.top(); numbers.pop();
            cout << a << " " << b << endl;
            switch (synt.front().getStr()[0]) {
                case '+': {
                    numbers.push(a + b);
                    break;
                }
                case '-': {
                    numbers.push(a - b);
                    break;
                }
                case '*': {
                    numbers.push(a * b);
                    break;
                }
                case '/': {
                    numbers.push(a/b);
                    break;
                }
                default: break;
            }
        }
        synt.pop();
    }
    double res = numbers.top();
    numbers.pop();
    return res;
}

class Calculate {
    string st;
    queue<Lexema> lexic;
    queue<Lexema> synt;
    double res;
public:
    Calculate(string _st) : st(_st) {
        lexic = lex(st);
        synt = sunt(lexic);
        res = calc(synt);
    };
    queue<Lexema> getLex() {return lexic; }
    queue<Lexema> getSynt() {return synt; }
    double getRes() {return res; }
};

#endif //PARSER_CALCULATE_H
