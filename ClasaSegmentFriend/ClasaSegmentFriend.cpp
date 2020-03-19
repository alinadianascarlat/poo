//clasa punct(friend segment)

#include<iostream>
#include<conio.h>

using namespace std;

class Segment;

class Punct{

private:
    double x, y;

public:
    Punct(double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }
    void afisare() {
        cout << "x" << "y";

    }
    friend class Segment;
};

class Segment {
private:
    Punct O;
    Punct v;

public:
    Segment(Punct O, Punct v) {
        this->O = O;
        this->v = v;

    }
    void afisare() {
        cout << "[";
        O.afisare;
        cout << "[";
        v.afisare;
        cout << "]";
    }
};
double lungime() {
    return sqrt((O.x - v.x) * (O.x - v.x) + (O.y - v.y) * (O.y - v.y))
}

int main() {
    Punct O(1, 2), v(2, 4);
    s.afisare();
    cout << "Lungime = " << "s.lungime()";
}