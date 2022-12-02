//
// Created by nikita on 11/30/22.
//

#ifndef PARSER_EXEPTIONS_H
#define PARSER_EXEPTIONS_H

#include "Lexema.h"

enum ExType {
    AllGood,
    Brackets,
    Operations,
    Arguments
};

string lexToString(queue<Lexema> lex, int errPosition, string mes) {
    int shift = 0;
    string fun = "";
    int i = 0;
    while (!lex.empty()) {
        fun += lex.front().getStr();
        if (i < errPosition) shift += lex.front().getStr().length();
        lex.pop(); i++;
    }

    string message = "\n" + mes + "\n";
    message += "\t" + fun + "\n" + "\t";
    for (i = 0; i < shift; i++) {
        message += " ";
    }
    message += "^--------";

    return message;
};

class InitException {
public:
    virtual ExType getExType() = 0;
    virtual int getErrPosition() = 0;
    virtual void show(queue<Lexema> lex) = 0;
};

class BrException: public InitException{
    string str;
    int ind;
public:
    BrException(string _str = "Brackets", int _ind = -1) : str(_str), ind(_ind) {};
    ExType getExType() override {return Brackets;}
    int getErrPosition() override {return ind;}
    void show(queue<Lexema> lex) override {
        cout << lexToString(lex, getErrPosition(), "No match for this bracket:") << endl;
    }
};

class OpException: public InitException{
    string str;
    int ind;
public:
    OpException(string _str = "Operation", int _ind = -1) : str(_str), ind(_ind) {};
    ExType getExType() override {return Operations;}
    int getErrPosition() override {return ind;}
    void show(queue<Lexema> lex) override {
        cout << lexToString(lex, getErrPosition(), "Number expected:") << endl;
    }
};

class ArgException: public InitException{
    string str;
    int ind;
public:
    ArgException(string _str = "Argument", int _ind = -1) : str(_str), ind(_ind) {};
    ExType getExType() override {return Arguments;}
    int getErrPosition() override {return ind;}
    void show(queue<Lexema> lex) override {
        cout << lexToString(lex, getErrPosition(), "Missing argument:") << endl;
    }
};

#endif //PARSER_EXEPTIONS_H
