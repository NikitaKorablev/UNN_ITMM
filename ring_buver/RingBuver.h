//
// Created by nikita on 12/9/22.
//

#ifndef RING_BUVER_RINGBUVER_H
#define RING_BUVER_RINGBUVER_H
using namespace std;

struct Link {
    int val;
    Link *n;
    Link(int _val = 0, Link * _n = nullptr) : val(_val), n(_n) {};
};

class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual int next() = 0;
};

class ListIterator : public Iterator {
    Link* t;
    Link* first;
public:
    ListIterator(Link* first) {
        this->first = first;
        t = first->n;
    }
    bool hasNext() override {
        return t != first;
    }
    int next() override {
        if (t == first) throw -1;
        int val = t->val;
        t = t->n;
        return val;
    }
};

class List {
    Link* first;
    Link* end;
public:
    List() {
        Link* p = new Link;
        p->n = p;
        first = p;
        end = p;
    }
    List(const List& l) {
        first = new Link;
        first->n = first;
        end = first;
        Link* t = l.first->n;
        while (t != l.first) {
            addEnd(t->val);
            t = t->n;
        }
    }
    void addFirst (int a) {
        Link* p = new Link(a, first->n);
        if (first->n == first) end = p;
        first->n = p;
    }
    void addEnd(int a) {
        Link* p = new Link(a, first);
        end->n = p; end = end->n; // вставили элемент в конец и переместили указатель
    }
    void delFirst() {
        if (first->n == first) throw -1;
        if (first->n == end) end = first;
        Link* p = first->n;
        first->n = p->n;
        delete p;
    }
    void delEnd() {
        if (first->n == first) throw -1;
        if (first == end) {
            delFirst();
            return;
        }
        Link* p = end;
        Link* t = first;
        while (t->n != end) t = t->n;
        t->n = first;
        end = t;
        delete p;
    }

    bool isEmpty() { return first->n == first; }
    int get() {
        if (isEmpty()) throw -2;
        return first->n->val;
    }

    void print() {
        Link* t = first->n;
        while(t != first) {
            cout << t->val << " ";
            t = t->n;
        }
    }
    Iterator* iterator() {
        return new ListIterator(first);
    }
};



#endif //RING_BUVER_RINGBUVER_H
