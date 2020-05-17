#include <iostream>

using namespace std;

class Multime {
	int n;
	int v[100];

public:
	void citeste() {
		cout << "n = ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "v[" << i << "]=";
			cin >> v[i];
		}
	}

	void afisare() {
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}

	Multime operator+(Multime m1) {
		Multime reuniune;

		for (int i = 0; i < n; i++) {
			reuniune.v[i] = this->v[i];
		}

		reuniune.n = this->n;
		for (int i = 0; i < m1.n; i++) {
			bool gasit = 0;
			for (int j = 0; j < reuniune.n; j++) {
				if (m1.v[i] == reuniune.v[j]) {
					gasit = 1;
					break;
				}
			}

			if (!gasit) {
				reuniune.v[reuniune.n] = m1.v[i];
				reuniune.n++;
			}
		}

		return reuniune;
	}

	Multime operator*(Multime m) {
		Multime intersectie;

		intersectie.n = 0;
		for (int i = 0; i < this->n; i++) {
			for (int j = 0; j < m.n; j++) {
				if (this->v[i] == m.v[j]) {
					intersectie.v[intersectie.n] = this->v[i];
					intersectie.n++;
					break;
				}
			}
		}

		return intersectie;
	}
};

int main() {
	Multime a;
	a.citeste();
	a.afisare();

	Multime b;
	b.citeste();
	b.afisare();

	Multime reuniune = a + b;
	cout << "Reuniune: ";
	reuniune.afisare();

	
	Multime intersectie = a * b;
	cout << "Intersectie: ";
	intersectie.afisare();

	//int n, m;
	//int v[20];
	//int v1[30];
	//int reuniune[100];
	//int intersectie[100];

	//cout << "n = ";
	//cin >> n;

	//cout << "m = ";
	//cin >> m;

	//for (int i = 0; i < n; i++) {
	//	cout << "v[" << i << "]=";
	//	cin >> v[i];
	//}
	//for (int j = 0; j < m; j++) {
	//	cout << "v1[" << j << "]=";
	//	cin >> v1[j];
	//}
 //  
	//for (int i = 0; i < n; i++) {
	//	reuniune[i] = v[i];
	//}

	//int nrElementeReuniune = n;
	//for (int i = 0; i < m; i++) {
	//	bool gasit = 0;
	//	for (int j = 0; j < nrElementeReuniune; j++) {
	//		if (v1[i] == reuniune[j]) {
	//			gasit = 1;
	//			break;
	//		}
	//	}

	//	if (!gasit) {
	//		reuniune[nrElementeReuniune] = v1[i];
	//		nrElementeReuniune++;
	//	}
	//}

	//cout << "Reuniune: ";
	//for (int i = 0; i < nrElementeReuniune; i++) {
	//	cout << reuniune[i] << " ";
	//}
	//cout << endl;

	//int nrElementeIntersectie = 0;

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		if (v[i] == v1[j]) {
	//			intersectie[nrElementeIntersectie] = v[i];
	//			nrElementeIntersectie++;
	//			break;
	//		}
	//	}
	//}

	//cout << "Intersectie: ";
	//for (int i = 0; i < nrElementeIntersectie; i++) {
	//	cout << intersectie[i] << " ";
	//}
	//cout << endl;
}