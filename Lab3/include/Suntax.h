//
// Created by nikita on 11/18/22.
//

#ifndef PARSER_SUNTAX_H
#define PARSER_SUNTAX_H

#include "Lexema.h"
using namespace std;

string mapPriotity[3] = {"()", "+-", "*/"};
int priority(string op) {
    for (int i = 0; i < 3; i++) {
        if (mapPriotity[i].find(op) != -1) return i;
    }
    return -1;
}

queue<Lexema> sunt(queue <Lexema> qLex) {
    Stack<Lexema> stack;
    queue<Lexema> polc;

    cout << endl;
    int i = -1;
    while (!qLex.empty()) {
        i++;
        if (qLex.front().getType() == Value) {
            polc.push(Lexema(qLex.front().getStr(), Value, i));
        }
        else if (qLex.front().getType() == Operation) {
            while (!stack.isEmpty()) {
//                cout << stack.top().getStr() << " " << priority(stack.top().getStr()) << " ";
//                cout << qLex.front().getStr() << " " << priority(qLex.front().getStr()) << endl;
                if (priority(stack.top().getStr()) >= priority(qLex.front().getStr()) && qLex.front().getStr() != "(") {
                    if (stack.top().getStr() != "(") polc.push(Lexema(stack.top()));
                    stack.pop();
                } else break;
            }
            if (qLex.front().getStr() != ")") stack.push(qLex.front());
        } else throw -1;
        qLex.pop();
    }
    while (!stack.isEmpty()) {
        if (stack.top().getStr() != "(" && stack.top().getStr() != ")") polc.push(Lexema(stack.top()));
        stack.pop();
    }
    return polc;
}
#endif //PARSER_SUNTAX_H

