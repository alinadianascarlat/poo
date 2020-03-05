#include<iostream>
#include<conio.h>

using namespace std;

class Punct {
private:
	int x;
	int y;
public:
	Punct(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}

	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
	void afisare() {
		cout << "punctul este: " << x << y << endl;
	}
	void citire() {
		cout << " x = ";
		cin >> x;
		cout << " y = ";
		cin >> y;
	}
};

float distanta(Punct p1, Punct p2) {
	return sqrt(((p1.getx() - p2.getx()) * (p1.getx() - p2.getx()) + ((p1.gety() - p2.gety()) * (p1.gety() - p2.gety()))));
}

void main() {
	Punct p1, p2;
	
	p1.citire();
	p1.afisare();

	p2.citire();
	p2.afisare();

	float d = distanta(p1, p2);
	cout << "distanta: " << d;
}
