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

int& Image::getPixel(int _w, int _h) {
    if (_w < 0 || _h < 0 || _w >= w || _h >= h) throw 1;
    cout << (int)img[_h][_w] << endl;
    return (int&)img[_h][_w];
}

void Image::show() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << (int)img[i][j] << " ";
        }
        cout << endl;
    }
}

void Image::increase() {
    unsigned char** _img = new unsigned char * [h * 2];
    for (int i = 0; i < h; i++) {
        _img[i] = new unsigned char [w * 2];
    }

    cout << "err" << endl;

    for (int i = 0; i < h; i++) {
        _img[i][0] = img[i][0];
        cout << "err2" << endl;
        int j = 1;
        for (; j < w; j++) {
            _img[i][j * 2] = img[i][j];
            _img[i][j * 2 - 1] = (img[i][j - 1] + img[i][j]) / 2;
        }
        _img[i][j * 2 + 1] = img[i][j * 2];

        if (i >= 1) {
            for (j = 0; j < w * 2; j++) {
                _img[i - 1][j] = (_img[i - 2][j] + _img[i][j]) / 2;
            }
        }
    }

    cout << "err" << endl;

    for (int i = 0; i < w * 2; i++) {
        _img[h * 2 - 1][i] = _img[(h - 1) * 2][i];
    }

    for (int i = 0; i < h; i++) {
        delete []img[i];
    }
    delete []img;
    img = _img;
    h *= 2; w *= 2;
}
