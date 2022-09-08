//
// Created by nikita on 9/2/22.
//

#include <iostream>
#include <string.h>
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
    cout << endl;
}

void Image::increase() {
    unsigned char** _img = new unsigned char * [h * 2];
    int _h = h * 2, _w = w * 2;
    for (int i = 0; i < _h; i++) {
        _img[i] = new unsigned char [_w];
    }

    for (int i = 0; i < h; i++) {
        _img[i * 2][0] = img[i][0];
        for (int j = 1; j < w; j++) {
            _img[i * 2][j * 2] = img[i][j];
            _img[i * 2][j * 2 - 1] = (img[i][j - 1] + img[i][j]) / 2;
        }
        _img[i * 2][_w - 1] = img[i][w - 1];

        if (i >= 1) {
            for (int j = 0; j < _w; j++) {
                _img[i * 2 - 1][j] = (_img[i * 2 - 2][j] + _img[i * 2][j]) / 2;
            }
        }
    }

    for (int i = 0; i < _w; i++) {
        _img[_h - 1][i] = _img[_h - 2][i];
    }

    for (int i = 0; i < h; i++) {
        delete []img[i];
    }
    delete []img;
    img = _img;
    h = _h; w = _w;
}
