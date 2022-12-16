//
// Created by atikin on 02.12.22.
//

#ifndef LISTKR_LIST_H
#define LISTKR_LIST_H


#include <iostream>
using namespace std;

struct Link{
    int val;
    Link* next;
    Link(int _val, Link* _next = nullptr): val(_val), next(_next){}
};

class List{
    Link* start;
public:
    List(){ start = nullptr; }
    List(const List& l){
        if(l.start == nullptr) {
            this->start = nullptr;
            return;
        }
        start = new Link(l.start->val);
        Link* tmp1 = l.start->next;
        Link* tmp2 = start;
        while(tmp1 != nullptr){
            tmp2->next = new Link(tmp1->val);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }
    ~List(){
        while(start != nullptr) del_first();
    }
    void add_first(int v){
        Link* a = new Link(v, start);
        start = a;
    }
    void add_end(int v) {
        Link* tmp = this->start;
        while(tmp->next != nullptr) {
            tmp = tmp->next;
        }

        Link* a = new Link(v, tmp->next);
        tmp->next = a;
    }

    void del_first(){
        Link* tmp;
        if(start == nullptr) throw -1;
        tmp = start;
        start = start->next;
        delete tmp;
    }

    int pop() {
        if(start == nullptr) throw -1;
        Link* tmp1 = this->start;
        while(tmp1->next->next != nullptr) {
            tmp1 = tmp1->next;
        }

        int res = tmp1->next->val;
        tmp1->next = nullptr;
        return res;
    }

    int getTop() {
        Link* tmp = this->start;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        return tmp->val;
    }

    int findMax() {
        int max = this->start->val;
        Link* tmp = this->start;
        while (tmp->next != nullptr) {
            if (tmp->val > max) max = tmp->val;
            tmp = tmp->next;
        }
        return max;
    }

    friend ostream& operator<<(ostream& os, List& l) {
        Link* curr;
        curr = l.start;
        while (curr){
            os << curr->val << " ";
            curr = curr->next;
        }
        return os;
    }
};


#endif //LISTKR_LIST_H
