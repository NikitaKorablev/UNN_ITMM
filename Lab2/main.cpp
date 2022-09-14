#include <iostream>
#include "image.h"

using namespace std;

int main() {
    Image img(3, 5);
    Image imgCopy(img);

    img.show();

    try {
        img.getPixel(1, 3) = 10;
    }
    catch (...) {
        cout << "Error of size" << endl << endl;
    }

    img.increase();
    img.show();

    return 0;
}
