//
// Created by nikita on 11/18/22.
//

#ifndef ROBOT_BUFFER_H
#define ROBOT_BUFFER_H

#include "stdio.h"
using namespace std;

struct Coordinate {
    int x;
    int y;
};

class Buffer {
    Coordinate* xy;
    int len;
    int start;
    int end;
public:
    Buffer(int _len = 3) : len(_len) {
        xy = new Coordinate[len];
        start = 0;
        end = next(start);
//        cout << start << end << endl;
    }
    int next(int i) {
        return (i + 1) % len;
    }
    bool isEmpty() {
        return next(start) == end;
    }
    bool isFull() {
        return next(end) == start;
    }
    void push(int _x, int _y) {
//        cout << "start_end " << start << " " << end << endl;
        if (isFull()) {
            start = next(start);
        };
        end = next(end);
        xy[end].x = _x;
        xy[end].y = _y;
//        cout << "start_end " << start << " " << end << endl;
        cout << "Move to: " << xy[end].x << ":" << xy[end].y << endl;
    }
    Coordinate pop() {
        if (isEmpty()) throw -1;
        end = (end + len - 1) % len;
        Coordinate XY_old;
        XY_old.x = xy[end].x;
        XY_old.y = xy[end].y;
//        cout << "start_end " << start << " " << end << endl;
        cout << "Move to: " << xy[end].x << ":" << xy[end].y << endl;
        return XY_old;
    }
    ~Buffer() {
        delete[] xy;
    }
};

class Robot {
    Coordinate xy;
    Buffer queue;
public:
    Robot() {
        xy.x = 0;
        xy.y = 0;
        queue.push(xy.x, xy.y);
    }
    void moveFront() {
        xy.y += 1;
        queue.push(xy.x, xy.y);
    }
    void moveRight() {
        xy.x += 1;
        queue.push(xy.x, xy.y);
    }
    void moveLeft() {
        xy.x -=1;
        queue.push(xy.x, xy.y);
    }
    void moveBack() {
        try {
            xy = queue.pop();
        } catch (int err) {
            if (err == -1) cout << "Queue is empty" << endl;
        }
    }
};

#endif //ROBOT_BUFFER_H
