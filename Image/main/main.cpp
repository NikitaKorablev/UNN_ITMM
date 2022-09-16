#include <iostream>
#include "IMethod.h"
#include "image.h"

using namespace std;

void fill(Image& img, IMethod* m) {
    int h = img.getH();
    int w = img.getW();

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            img.getPixel(i, j) = m->getValue(i, j);
        }
    }
}

template <class T>
void fill_template(Image& img, T* m) {
    int h = img.getH();
    int w = img.getW();

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            img.getPixel(i, j) = m->getValue(i, j);
        }
    }
}

int main() {
//    Image img(3, 5);
//    Image imgCopy(img);
//
//    img.show();
//
//    try {
//        img.getPixel(1, 3) = 10;
//    }
//    catch (...) {
//        cout << "Error of size" << endl << endl;
//    }
//
//    img.increase();
//    img.show();

//    ImageInit_v1 im;
//    im.readF("image1.txt");
//    im.show();
//
//    im.increase();
//    im.show();
//
//    im.writeF("image2.txt");

// ------------------------------------------------------

    Image img(3, 3);

    fill(img,new  White());
    img.show();

    fill(img, new BlackWhite());
    img.show();

    fill_template(img, new White());
    img.show();

    fill_template(img, new BlackWhite());
    img.show();

    return 0;
}
