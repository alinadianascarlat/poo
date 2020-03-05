#include<iostream>
#include<conio.h>

using namespace std;

class Punct {
private:
	int x;
	int y;
public:
	Punct(int x = 0, int y = 0);
	this->x = x;
	this->y = y;
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
	void afisare() {
		cout << " punctul este:" << x << y;

	}
	void citire(int x, int y) {
		cout << " x = ";
		cin >> x;
		cout << " y = ";
		cin >> y;

	}
};

void distanta(int p1, int p2) {
	return sqrt(((p1.getx() - p2.getx()) * (p1.getx() - p2.getx()) - ((p1.gety() - p2.gety()) * (p1.gety() - p2.gety()));
}
void main() {
	Punct p1, p2;
	p1.citeste;
	p2.citeste;
	float d = distanta(p1, p2);
	cout << "distanta :" << d;
}







