//
// Created by nikita on 9/2/22.
//

#include <iostream>
#include <typeinfo>
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

char& Image::getPixel(int _h, int _w) {
    if (_w < 0 || _h < 0 || _w >= w || _h >= h) throw 1;
    return (char&)img[_h][_w];
}

int& Image::getH() { return h; };
int& Image::getW() { return w; };

void Image::newParam(int _h, int _w) {
    for (int i = 0; i < h; i++) {
        delete[] img[i];
    }
    delete[] img;

    h = _h; w = _w;
    img = new unsigned char * [h];
    for (int i = 0; i < h; i++) {
        img[i] = new unsigned char [w];
    }
}

void Image::show() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
//            cout << typeid(img[i][j]).name() << " ";
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

void ImageInit_v1::readF(string address) {
    int H, W;
    ifstream file(address, ios::binary);
    if (!file.is_open()) cout << "err" << endl;
    file >> H >> W;
    cout << H << " " << W << endl;

    unsigned char** a = new unsigned char * [H];
    for (int i = 0; i < H; i++) {
        a[i] = new unsigned char [W];
        for (int j = 0; j < W; j++) {
            file >> a[i][j];
        }
    }
    file.close();

    this->newParam(H, W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            this->getPixel(i, j) = a[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        delete[] a[i];
    }
    delete[] a;
}

void ImageInit_v2::writeF(string address) {
    ofstream file(address, ios::binary);
    file << this->getH() << " " << this->getW() << endl;
    for (int i = 0; i < this->getH(); i++) {
        for (int j = 0; j < this->getW(); j++) {
            file << this->getPixel(i, j) << " ";
        }
        file << endl;
    }
    file.close();
}

void ImageInit_v2::readF(string address) {
    int H, W;
    ifstream file(address, ios::binary);
    if (!file.is_open()) cout << "err" << endl;
    file >> H >> W;
    cout << H << " " << W << endl;

    unsigned char** a = new unsigned char * [H];
    for (int i = 0; i < H; i++) {
        a[i] = new unsigned char [W];
        for (int j = 0; j < W; j++) {
            file >> a[i][j];
        }
    }
    file.close();

    this->newParam(H, W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            this->getPixel(i, j) = a[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        delete[] a[i];
    }
    delete[] a;
}

void ImageInit_v1::writeF(string address) {
    ofstream file(address, ios::binary);
    file << this->getH() << " " << this->getW() << endl;
    for (int i = 0; i < this->getH(); i++) {
        for (int j = 0; j < this->getW(); j++) {
            file << this->getPixel(i, j) << " ";
        }
        file << endl;
    }
    file.close();
}