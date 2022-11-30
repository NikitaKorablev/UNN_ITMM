//
// Created by nikita on 11/26/22.
//

#ifndef PARSER_SQ_H
#define PARSER_SQ_H
#include "cstring"
#include "iterator"

template <class T>
class Stack{
    int last;
    int memSize;
    T* mem;
public:
    Stack(int _memSize = 10) : last(-1), memSize(_memSize), mem(new T[memSize]) {};;
    int size() const { return last + 1; }
    bool isEmpty() const { return last == -1; }
    bool isFool() const { return last == 10 - 1; }
    void push(const T& val);
    T pop() { return mem[last--];}
    T top() { return mem[last]; }
    Stack& operator = (const Stack& st);
    ~Stack() {
        delete[] mem;
    }
};

template <class T>
void Stack<T>::push(const T &val) {
    if (memSize == size() + 1) {
        T* tmp = new T[memSize * 2];

        for (int i = 0; i < memSize; i++) {
            tmp[i] = mem[i];
        }

        delete[] mem;
        mem = tmp;
        memSize *= 2;
    }
    mem[++last] = val;
}

template<class T>
Stack<T> &Stack<T>::operator=(const Stack &st) {
    if (this == &st) return *this;

    last = st.last;
    delete[] mem;
    mem = new T [st.size()];
    for (int i = 0; i < memSize; i++) {
        mem[i] = st.mem[i];
    }
    return *this;
}

#endif //PARSER_SQ_H
