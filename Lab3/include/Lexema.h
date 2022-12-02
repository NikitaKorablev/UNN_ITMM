//
// Created by nikita on 11/15/22.
//

#ifndef LAB3_LEXEMA_H
#define LAB3_LEXEMA_H

#include "string"
#include "iostream"
#include <queue>
#include "SQ.h"

using namespace std;

enum TypeElement {
    Undefined,
    Operation,
    Value
};

class Lexema {
    string str;
    TypeElement type;
    int position;
public:
    Lexema(int _position = -1) : str(""), type(Undefined), position(_position) {};
    Lexema(string _str, TypeElement _type, int _position) : str(_str), type(_type), position(_position) {};
    int getPosition() {return position;}
    string getStr() {return str;}
    TypeElement getType() {return type;}
    friend ostream& operator << (ostream& out, Lexema& p) {
        out << "{" << p.str << ", ";
        if (p.type == Operation) {
            out << "operation";
        }
        else if (p.type == Value) {
            out << "value";
        };
        out << ", " << p.position << "}";
        return out;
    }
};

queue<Lexema> lex(string input) {
    queue<Lexema>res;
    input += ' ';
    int i;
    string tmp = "";
    string op = "+-*/()";
    string sep = " \n\t";
    int state = 0;
    int position = 0;
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
                    res.push(Lexema(tmp, Operation, position++));
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
                    res.push(Lexema(tmp, Value, position++));
                    tmp = c;
                    res.push(Lexema(tmp, Operation, position++));
                    state = 0;
                    break;
                }
                if (sep.find(c) != -1) {
                    res.push(Lexema(tmp, Value, position++));
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

string lexToString(queue<Lexema> lex) {
    string res = "";
    while (!lex.empty()) {
        res += lex.front().getStr();
        lex.pop();
    }
    return res;
}



#endif //LAB3_LEXEMA_H
