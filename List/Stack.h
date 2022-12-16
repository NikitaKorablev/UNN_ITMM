//
// Created by nikita on 12/2/22.
//

#ifndef LIST_STACK_H
#define LIST_STACK_H
#include "list.h"

class Stack{
    int memSize;
    List mem;
public:
    Stack() : mem(List()) {
        memSize = 0;
    };
    int size() const { return memSize; }
    bool isEmpty() const { return memSize == 0; }
    bool isFool() const { return memSize != 0; }
    void push(const int& val) {
        memSize++;
        mem.add_first(val);
    };
    int pop() {
        memSize--;
        int tmp = mem.getTop();
        mem.del_first();
        return tmp;
    }
    int top() { return mem.getTop(); }

//    friend ostream& operator<<(ostream& os, Stack& l) {
//        os << l.mem.getTop() << " ";
//        return os;
//    }
};

#endif //LIST_STACK_H
