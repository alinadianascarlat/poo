#include<iostream>
#include<conio.h>

using namespace std;

class Data {
private:
	
	int* zi_curenta;
	int* luna_curenta;
	int* an_curent;
	bool* esteAnBisect;
	int* NrZileLuna;
	int* NrZileAn;

public:

	Data(int* zi_curenta, int* luna_curenta, int* an_curent, bool* esteAnBisect, int* NrZileLuna, int* NrZileAn) {
		this->zi_curenta = zi_curenta;
		this->luna_curenta = luna_curenta;
		this->an_curent = an_curent;
		this->esteAnBisect = esteAnBisect;
		this->NrZileAn = NrZileAn;
		this->NrZileLuna = NrZileLuna;
	}
	int get_zi() {
		return zile;
	}
	int get_luna() {
		return luna;
	}
	int get_an() {
		return an;
	}

	void print() {
		cout << "zi_curenta" << zi << endl;
		cout << "luna_curenta" << luna << endl;
		cout << "an_curent" << an << endl;

	}
};

int main() {
	int zi, luna, an;
	cout << "zi_curenta:";
	cout << "luna_curenta:";
	cout << "an_curent:";
	cout << "esteAnBisect:";
	cout << "NrZileAn:";
	cout << "NrZileluna:";
	cin >> zi;
	cin >> luna;
	cin >> an;


}
}