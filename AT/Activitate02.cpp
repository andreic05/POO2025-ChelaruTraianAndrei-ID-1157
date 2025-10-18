#include <iostream>
#include <string>

using namespace std;

enum Combustibil {BENZINA=1, DIESEL = 2, ELECTRIC = 3 };

class Motocicleta {
public:
	char* marca = nullptr;
	string model = "Necunoscut";
	int nrKm = 0;
	Combustibil combustibil = Combustibil(1);

	void afisare() {
		if (marca == nullptr) {
			cout << endl << "Marca nu este definita";
			return;
		}

		string combStr;
		switch (this->combustibil) {
		case 1: combStr = "Benzina";
			break;
		case 2: combStr = "Diesel";
			break;
		case 3: combStr = "Electric";
			break;
		}

		cout << "Motocicleta [Marca: " << this->marca << ", Model: " << model << ", Nr. Kilometri: " << nrKm << ", Combustibil: " << combStr;
	}
};


void main() {
	Motocicleta* moto1 = new Motocicleta();
	moto1->marca = new char[strlen("BMW") + 1];
	strcpy_s(moto1->marca, strlen("BMW") + 1, "BMW");
	moto1->model = "S150";
	moto1->nrKm = 5000;
	moto1->afisare();
}