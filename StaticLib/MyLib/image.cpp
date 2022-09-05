//
// Created by nikita on 9/2/22.
//

#include <iostream>
#include "image.h"

using namespace std;

Image &Image::operator=(const Image &tmp) {
    if (this == &tmp) return *this;
    for (int i = 0; i < h; i++) {
        delete []img[i];
    }
    delete []img;

    h = tmp.h;
    w = tmp.w;
    img = new unsigned char * [h];
    for (int i = 0; i < h; i++) {
        img[i] = new unsigned char [w];
        for (int j = 0; j < w; j++) {
            img[i][j] = tmp.img[i][j];
        }
    }
    return *this;
}

unsigned char& Image::getPixel(int _w, int _h) {
    if (_w < 0 || _h < 0 || _w >= w || _h >= h) throw 1;
    return img[_h][_w];
}

void Image::show() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << (int)img[i][j] << " ";
        }
        cout << endl;
    }
}
