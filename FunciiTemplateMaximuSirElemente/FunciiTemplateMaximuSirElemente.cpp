//Sa se realizeze o functie care sa calculeze maximul dintr un sir de elemente, elementele sunt numere intregi.

#include <iostream>
#include <conio.h>
using namespace std;

template <typename T>
T max(int n, T t[]) {
	T m = t[0];
	for (int i = 1; i < n; i++) {
		if (t[i] > m)
			m = t[i];
	}
	return m;
}
int main() {
	int a[3] = { 2, 1, 9 };
	float b[4] = { 3.0, 1.2, 4.8, 1.9 };
	cout << max<int>(3, a) << endl;
	cout << max<float>(4, b) << endl;
	cout << max(3, a) << endl;
}