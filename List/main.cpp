#include <iostream>
#include "Stack.h"

int main() {
//    Stack st;
//    st.push(5);
//    cout << st << endl;

    List list;
    list.add_first(5);
    list.add_first(7);
    list.add_first(3);
    cout << list << endl;

    cout << list.findMax() << endl;

    cout << list.getTop() << endl;
    cout << list.pop() << endl;
    cout << list << endl;

    list.add_end(10);
    cout << list << endl;

//    list.del_first();
//    cout << list << endl;
    return 0;
}
