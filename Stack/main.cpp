#include <iostream>
using namespace std;

class Stack{
    int top;
    int mem[10];
public:
    Stack() : top(-1) {};
    int size() const { return top + 1; }
    bool isEmpty() const { return top == -1; }
    bool isFool() const { return top == 10 - 1; }
    void Push(const int& val) {
        if (top + 1 >= 10) throw "Memory is end";
        mem[++top] = val;
    }
    int Pop() { return mem[top--]; }
};

int main() {
    int a = 3;
    int b = 2;
    int c = 1;

    cout << a << " " << b << " " << c << endl;

    Stack s;
    s.Push(b);
    s.Push(c);
    s.Push(a);

    c = s.Pop();
    b = s.Pop();
    a = s.Pop();

    cout << a << " " << b << " " << c << endl;

    return 0;
}
