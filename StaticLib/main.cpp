#include <iostream>
#include "image.h"

using namespace std;

int main() {
    Image img(3, 5);
    Image imgCopy(img);

    img.show();

    try {
        img.getPixel(1, 2) = 3;
        cout << img.getPixel(1, 2) << endl;
    }
    catch (...) {
        cout << "Error of size" << endl;
    }

    img.show();

    return 0;
}
