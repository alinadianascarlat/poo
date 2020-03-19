//clasa punct(friend distanta)

#include <iostream>
#include<conio.h>

using namespace std;

class Punct {
	 
private:
	double x, y;

public:
	Punct(double x = 0, double y = 0) {
		this->x = x;
		this->y = y;

	}

	friend double distanta(Punct p1, Punct p2);

};
double distanta(Punct p1, Punct p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y)(p1.y - p2.y));
}

int main() {
	Punct p1(1, 0), p2(4, 4);
	cout << "distanat=" << distanta(p1, p2);

}
