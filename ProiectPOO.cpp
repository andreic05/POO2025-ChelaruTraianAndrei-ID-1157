#include<iostream>

using namespace std;

class VitaDeVie {
private:
	static char* validareSpecie(const char* specie) {
		char* rezultat = nullptr;
		if (specie != nullptr) {
			if (strlen(specie) > 0) {
				rezultat = new char[strlen(specie) + 1];
				strcpy_s(rezultat, strlen(specie) + 1, specie);
			}
			
		}

		if (rezultat == nullptr) {
			int lenSp = strlen("Specia nu a fost specificata") + 1;
			strcpy_s(rezultat, lenSp, "Specia nu a fost specificata");
		}

		return rezultat;
	}

	static int validareVarsta(int varsta) {
		if (varsta < 0) return 0;
		return varsta;
	}

	static int validareProdAnuala(int prod) {
		if (prod < 0) return 0;
		return prod;
	}

	static int validareNrSup(int sup) {
		if (sup < 0) return 0;
		return sup;
	}

	static double* validareDim(int nr, double* dim) {
		double* rezultat = new double[nr];
		for (int i = 0;i < nr;i++) {
			rezultat[i] = dim[i] < 0 ? 0 : dim[i];
		}

		delete[] dim;
		return rezultat;
	}


public:
	const int id;
	char* specie;
	int varsta;
	double productieAnuala;
	int nrSuprafete;
	double* dimSuprafetePlantate;
	
	static int nrViteDeVie;

	VitaDeVie() :id(++nrViteDeVie) {
		int lenSp = strlen("Specia nu a fost specificata") + 1;
		this->specie = new char[lenSp];
		strcpy_s(this->specie, lenSp, "Specia nu a fost specificata");
		this->varsta = 0;
		this->productieAnuala = 0;
		this->nrSuprafete = 0;
		this->dimSuprafetePlantate = nullptr;
		
	}

	VitaDeVie(const char* specie, int varsta) :id(++nrViteDeVie) {
		this->specie = validareSpecie(specie);
		this->varsta = validareVarsta(varsta);
		this->productieAnuala = 0;
		this->nrSuprafete = 0;
		this->dimSuprafetePlantate = nullptr;
		
	}

	VitaDeVie(const char* specie, int varsta, double productieAnuala, int nrSuprafete, double* dimSuprafetePlantate ) :id(++nrViteDeVie) {
		this->specie = validareSpecie(specie);
		this->varsta = validareVarsta(varsta);
		this->productieAnuala = validareProdAnuala(productieAnuala);
		this->nrSuprafete = validareNrSup(nrSuprafete);
		if (this->nrSuprafete == 0) dimSuprafetePlantate = nullptr;
		else this->dimSuprafetePlantate = validareDim(nrSuprafete, dimSuprafetePlantate);
	}

	~VitaDeVie() {
		if (this->specie != nullptr) delete[] this->specie;
		if (this->dimSuprafetePlantate != nullptr) delete[] this->dimSuprafetePlantate;
	}

	void afisare() {
		cout << endl << "Vita de Vie";
		cout << endl << "Id: " << id;
		cout << endl << "Specie: " << specie;
		cout << endl << "Varsta: " << varsta << " ani";
		cout << endl << "Productie Anuala: " << productieAnuala << " litrii";
		cout << endl << "Numar suprafete cultivate: " << nrSuprafete;
		if (nrSuprafete > 0) {
			cout << endl << "Dimensiuni suprafete cultivate: [";
			for (int i = 0; i < nrSuprafete - 1; i++) {
				cout << dimSuprafetePlantate[i] << ", ";
			}

			cout << dimSuprafetePlantate[nrSuprafete - 1] << "]" << endl;
		}
		else {
			cout << endl << "Specia nu a fost cultivata" << endl;
		}
		

	}

	static void comparareSiAfisareProductie(VitaDeVie* v1, VitaDeVie* v2) {
		if (v1->nrSuprafete == 0 || v2->nrSuprafete == 0) {
			cout << endl << "Speciile nu pot fi comparate - date insuficiente";
			return;
		}

		double supTotala1 = 0;
		for (int i = 0; i < v1->nrSuprafete; i++) {
			supTotala1 += v2->dimSuprafetePlantate[i];
		}
		double supTotala2 = 0;
		for (int i = 0; i < v1->nrSuprafete; i++) {
			supTotala2 += v2->dimSuprafetePlantate[i];
		}

		double indice1 = v1->productieAnuala / supTotala1;
		double indice2 = v2->productieAnuala / supTotala2;

		if (indice1 > indice2) {
			cout << endl << "Specia " << v1->specie << " produce mai mult decat specia " << v2->specie << ", cu un indice de productivitate de "
				<< indice1 << " fata de " << indice2 << " pentru specia " << v2->specie << ".";
		}

		if (indice2 > indice1) {
			cout << endl << "Specia " << v2->specie << " produce mai mult decat specia " << v1->specie << ", cu un indice de productivitate de "
				<< indice2 << " fata de " << indice1 << " pentru specia " << v1->specie << ".";
		}

		if (indice1 == indice2) {
			cout << endl << "Speciile " << v1->specie << " si " << v2->specie << " au productivitati egale, cu indicele de productivitate egal cu " << indice1 << ".";
		}

		cout << endl;

	}

};

class Vin {
public:
	const int id;
	char* soi;
	string marca;
	int anProductie;
	double tarie;
	static double taxaAcciza;
	static int nrVinuri;
};

int VitaDeVie::nrViteDeVie = 0;

class Crama {
public:
	const int id;
	char* denumire;
	const int capacitateMaxima;
	Vin* vinuri;
	int* nrVin;
	static int nrCrame;
};

void main() {
	VitaDeVie* vita1 = new VitaDeVie();
	VitaDeVie* vita2 = new VitaDeVie("Nume", 10);
	VitaDeVie* vita3 = new VitaDeVie("Specie1", 10, 500, 3, new double[3] {100, 200, 300});
	vita1->afisare();
	vita2->afisare();
	vita3->afisare();

	VitaDeVie* vita4 = new VitaDeVie("Specie2", 5, 600, 4, new double[4] {50, 200, 20, 60});
	vita4->afisare();

	VitaDeVie::comparareSiAfisareProductie(vita3, vita4);

	delete vita1;
	delete vita2;
	delete vita3;
	delete vita4;
}