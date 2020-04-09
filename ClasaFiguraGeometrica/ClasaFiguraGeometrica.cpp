#include<iostream>
using namespace std;

class FiguraGeometrica {
public:
	int perimetru() {
	}

	float aria() {
	}

	void afisare() {
		cout << "Figura geometrica";
	}
};

class Dreptunghi :public FiguraGeometrica {
public:
	Dreptunghi(int lungime, int latime) {
		this->lungime = lungime;
		this->latime = latime;
	}

	int perimetru() {
		return(2*(lungime + latime));
	}
};

class Patrat :public FiguraGeometrica {
public:
	Patrat(int latura) {
		this->latura = latura;
		
	}

	int perimetru() {
		return(4*latura);
	}
};

int main() {
	
	cout << "perimetru =" << t.perimetru() << endl;
	
	cout << "perimetru = " << d.perimetru() << endl;
	return 0;
}