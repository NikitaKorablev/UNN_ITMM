#include <iostream>
#include "image.h"

using namespace std;

int main() {
    Image img(3, 3);
    Image imgCopy(img);

    img.show();

    try {
        img.getPixel(5, 2) = 10;
        img.show();
    }
    catch (...) {
        cout << "Error of size" << endl;
    }

    img.increase();
    img.show();

    return 0;
}
