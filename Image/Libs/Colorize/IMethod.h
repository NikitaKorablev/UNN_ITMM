//
// Created by nikita on 9/16/22.
//

#ifndef IMAGE_IMETHOD_H
#define IMAGE_IMETHOD_H

class IMethod {
public:
    virtual int getValue(int _h = 0, int _w = 0) = 0;
};

class White: public IMethod {
public:
    int getValue(int _h, int _w) override {
        return 255;
    }
};

class BlackWhite: public IMethod {
public:
    int getValue(int _h, int _w) override {
        if ((_h + _w) % 2 == 0) return 0;
        else return 255;
    }
};

#endif //IMAGE_IMETHOD_H
