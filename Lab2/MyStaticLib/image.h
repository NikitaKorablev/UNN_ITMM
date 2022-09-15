//
// Created by nikita on 9/2/22.
//

#ifndef STATICLIB_IMAGE_H
#define STATICLIB_IMAGE_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Image {
    unsigned char** img;
    int h;
    int w;
public:
    Image(int _w = 0, int _h = 0) : h(_h), w(_w) {
        img = new unsigned char* [h];
        for (int i = 0; i < h; i++) {
            img[i] = new unsigned char [w];
            for (int j = 0; j < w; j++) {
                img[i][j] = rand() % 100 + 1;
            }
        }
    };

    Image (const Image& tmp) { // конструктор копирования
        h = tmp.h;
        w = tmp.w;
        img = new unsigned char * [h];
        for (int i = 0; i < h; i++) {
            img[i] = new unsigned char [w];
            for (int j = 0; j < w; j++) {
                img[i][j] = tmp.img[i][j];
            }
        }
    }

    Image& operator = (const Image& tmp);
    char& getPixel(int _w, int _h);
    int& getH();
    int& getW();
    void newParam(int _h, int _w);
    void show();
    void increase();

    ~Image() {
        for (int i = 0; i < h; i++) {
            delete []img[i];
        }
        delete []img;
    }
};

class ImageInit_v1: public Image{
public:
    void readF(string address);
    void writeF(string address);
};

#endif //STATICLIB_IMAGE_H
