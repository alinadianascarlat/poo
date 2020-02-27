// DataCalProiect.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class DataCalendaristica {
private:
	int zi;
	int luna;
	int an;

public:
	DataCalendaristica(string d) {
		//cout << d;
		// 22/03/2020

		std::string s = d;
		std::string delimiter = "/";

		size_t pos = 0;
		std::string tokens[3];
		int i = 0;
		while ((pos = s.find(delimiter)) != std::string::npos) {
			tokens[i++] = s.substr(0, pos);
			//std::cout << tokens[i] << std::endl;
			s.erase(0, pos + delimiter.length());
		}
		tokens[2] = s.substr(0, pos);
		//std::cout << s << std::endl;
		cout << tokens[0] << endl;
		cout << tokens[1] << endl;
		cout << tokens[2] << endl;
		this->zi = std::stoi(tokens[0]);
		this->luna = std::stoi(tokens[1]);
		this->an = std::stoi(tokens[2]);
	}

	static bool validare(string data) {

		return true;
	}
};


int main()
{
	string d;

	cout << "Introduceti o data calendaristica in formatul zz/ll/aaaa: ";
	cin >> d;

	new DataCalendaristica(d);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
