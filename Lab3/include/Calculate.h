//
// Created by nikita on 11/25/22.
//

#ifndef PARSER_CALCULATE_H
#define PARSER_CALCULATE_H

#include "Suntax.h"
#include "Exeptions.h"

void lexCheckErr(queue<Lexema> lex) {
    int floater = 0;
    Stack<Lexema> brackets;
    Lexema prevLex, currentLex;

    while (!lex.empty()) {
        if (lex.front().getStr() == "(") brackets.push(lex.front());
        currentLex = lex.front();
        if (currentLex.getStr() == "(") floater++;
        else if (currentLex.getStr() == ")") floater--;

        if (floater < 0) throw new BrException("Extra )", currentLex.getPosition());
        if (lex.front().getStr() == ")") brackets.pop();
        if (priority(prevLex.getStr()) > 0 &&
        priority(currentLex.getStr()) > 0 &&
        prevLex.getType() == Operation &&
        currentLex.getType() == Operation) {
            throw new OpException("Operation conflict", currentLex.getPosition());
        }

        prevLex = currentLex;
        lex.pop();
    }
    if (floater > 0) throw new BrException("Unclosed (", brackets.pop().getPosition());
}

double calc(queue<Lexema> synt) {
    Stack<double> numbers;
    int len = synt.size();
    double a, b;
    for (int i = 0; i < len; i++) {
        if (synt.front().getType() == Value) {
            numbers.push(stod(synt.front().getStr()));
        } else if (synt.front().getType() == Operation) {
            if (numbers.size() < 2) throw new ArgException("Missing Argument", synt.front().getPosition());
            b = numbers.pop();
            a = numbers.pop();
//            cout << a << " " << b << endl;
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
    string str;
    queue<Lexema> lexic;
    queue<Lexema> synt;
    double res;
    ExType exception;
public:
    Calculate(string _str) : str(_str), exception(AllGood) {
        try {
            lexic = lex(str); lexCheckErr(lexic);
            synt = sunt(lexic);
            res = calc(synt);
        } catch (InitException* ex) {
            exception = ex->getExType();
            ex->show(lexic);
        }
    };
    queue<Lexema> getLex() {
        if (exception == AllGood) return lexic;
        throw "Error in lexical analysis!";
    }
    queue<Lexema> getSynt() {
        if (exception == AllGood) return synt;
        throw "Parsing error!";
    }
    double getRes() {
        if (exception == AllGood) return res;
        throw "Calculation error!";
    }
    void fullShow() {
        if (exception == AllGood) {
            print(getLex());
            cout << endl;
            print(getSynt());
            cout << getRes() << endl;
        }
    }
    void show() {
        if (exception == AllGood) {
            cout << getRes() << endl;
        }
    }
};

#endif //PARSER_CALCULATE_H
