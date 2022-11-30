//
// Created by nikita on 11/15/22.
//

#ifndef LAB3_LEXEMA_H
#define LAB3_LEXEMA_H

#include "string"
#include "iostream"
#include <queue>
//#include <stack>
#include "SQ.h"

using namespace std;

enum TypeElement {
    Operation,
    Value,
    Undefined
};

class Lexema {
    string str;
    TypeElement type;
public:
    Lexema() : str(""), type(Undefined) {};
    Lexema(string _str, TypeElement _type) : str(_str), type(_type) {};
    string getStr() {return str;};
    TypeElement getType() {return type;};
    friend ostream& operator << (ostream& out, Lexema& p) {
        out << "{" << p.str << ", ";
        if (p.type == Operation) {
            out << "operation";
        }
        else if (p.type == Value) {
            out << "value";
        };
        out << "}";
        return out;
    }
};

queue <Lexema> lex(string input) {
    queue<Lexema>res;
    input += ' ';
    int i = 0;
    string tmp = "";
    string op = "+-*/()";
    string sep = " \n\t";
    int state = 0;
    for (i = 0; i < input.size(); i++) {
        char c = input[i];
        switch (state)
        {
            case 0: // find digit
                if (c >= '0' && c <= '9') {
                    tmp = c;
                    state = 1;
                    break;
                }
                if (op.find(c) != -1) {
                    tmp = c;
                    res.push(Lexema(tmp, Operation));
                    state = 0;
                    break;
                }
                if (sep.find(c) != string::npos){
                    tmp = "";
                    break;
                }
                break;
            case 1: //find operation
                if (c >= '0' && c <= '9') {
                    tmp += c;
                    state = 1;
                    break;
                }
                if (op.find(c) != -1) {
                    res.push(Lexema(tmp, Value));
                    tmp = c;
                    res.push(Lexema(tmp, Operation));
                    state = 0;
                    break;
                }
                if (sep.find(c) != -1) {
                    res.push(Lexema(tmp, Value));
                    state = 0;
                    break;
                }
                break;
        }
    }
    return res;
}

void print(queue <Lexema> t) {
    while (!t.empty()) {
        cout << t.front() << endl;
        t.pop();
    }
}

#endif //LAB3_LEXEMA_H
