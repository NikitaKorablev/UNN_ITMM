//
// Created by nikita on 11/18/22.
//

#ifndef PARSER_SUNTAX_H
#define PARSER_SUNTAX_H

#include "Lexema.h"
#include "map"
using namespace std;

map <string, int> priority = {
        {"(", 0}, {")", 0},
        {"+", 1}, {"-", 1},
        {"*", 2}, {"/", 2}
};



queue<string> sunt(queue <Lexema> qLex) {
//    cout << priority['*'] << endl;
    stack<string> stack;
    queue<string> polc;

    cout << endl;
    while (!qLex.empty()) {
        if (qLex.front().getType() == Value) {
            polc.push(qLex.front().getStr());
        }
        else if (qLex.front().getType() == Operation) {
            while (!stack.empty()) {
                cout << stack.top() << " " << qLex.front().getStr() << endl;
                if (priority[stack.top()] >= priority[qLex.front().getStr()]) {
                    if (qLex.front().getStr() != "(") polc.push(stack.top());
                    stack.pop();
                } else break;
            }
            if (qLex.front().getStr() != "(") stack.push(qLex.front().getStr());
        } else throw -1;
        qLex.pop();
    }
    return polc;
}

void print(queue<string> t) {
    while (!t.empty()) {
        cout << t.front() << endl;
        t.pop();
    }
}

#endif //PARSER_SUNTAX_H

