//
// Created by nikita on 12/9/22.
//

#ifndef RING_BUVER_STACKONRINGBUVER_H
#define RING_BUVER_STACKONRINGBUVER_H
#include "RingBuver.h"

class Stack {
    List l;
public:
    Stack() {};
    void push(int a) { l.addFirst(a); }
    int pop() {
        int val = l.get();
        l.delFirst();
        return val;
    }
};

#endif //RING_BUVER_STACKONRINGBUVER_H
