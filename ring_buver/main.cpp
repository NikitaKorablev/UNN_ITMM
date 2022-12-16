#include <iostream>
#include "RingBuver.h"

int main() {
    List l;
    l.addFirst(1);

    Iterator *i = l.iterator();
    while (i->hasNext()) cout << i->next() << " ";
    int s = 0;
    i = l.iterator();
    while (i->hasNext()) s += i->next();
    cout << s;
    return 0;
}
