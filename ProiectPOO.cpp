#include<iostream>

using namespace std;

class VitaDeVie {
private:
	const int id;
	char* specie;
	int varsta;
	double productieAnuala;
	int nrSuprafete;
	double* dimSuprafeteCultivate;

	static int nrViteDeVie;

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

		return rezultat;
	}


public:
	VitaDeVie() :id(++nrViteDeVie) {
		int lenSp = strlen("Specia nu a fost specificata") + 1;
		this->specie = new char[lenSp];
		strcpy_s(this->specie, lenSp, "Specia nu a fost specificata");
		this->varsta = 0;
		this->productieAnuala = 0;
		this->nrSuprafete = 0;
		this->dimSuprafeteCultivate = nullptr;
		
	}

	VitaDeVie(const char* specie, int varsta) :id(++nrViteDeVie) {
		this->specie = validareSpecie(specie);
		this->varsta = validareVarsta(varsta);
		this->productieAnuala = 0;
		this->nrSuprafete = 0;
		this->dimSuprafeteCultivate = nullptr;
		
	}

	VitaDeVie(const char* specie, int varsta, double productieAnuala, int nrSuprafete, double* dimSuprafeteCultivate ) :id(++nrViteDeVie) {
		this->specie = validareSpecie(specie);
		this->varsta = validareVarsta(varsta);
		this->productieAnuala = validareProdAnuala(productieAnuala);
		this->nrSuprafete = validareNrSup(nrSuprafete);
		if (this->nrSuprafete == 0) dimSuprafeteCultivate = nullptr;
		else this->dimSuprafeteCultivate = validareDim(nrSuprafete, dimSuprafeteCultivate);
	}

	~VitaDeVie() {
		if (this->specie != nullptr) delete[] this->specie;
		if (this->dimSuprafeteCultivate != nullptr) delete[] this->dimSuprafeteCultivate;
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
				cout << dimSuprafeteCultivate[i] << ", ";
			}

			cout << dimSuprafeteCultivate[nrSuprafete - 1] << "]" << endl;
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
			supTotala1 += v2->dimSuprafeteCultivate[i];
		}
		double supTotala2 = 0;
		for (int i = 0; i < v1->nrSuprafete; i++) {
			supTotala2 += v2->dimSuprafeteCultivate[i];
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

	int getId() {
		return this->id;
	}

	char* getSpecie() {
		if (this->specie == nullptr) return nullptr;
		
		char* copieSpecie = new char[strlen(this->specie) + 1];
		strcpy_s(copieSpecie, strlen(this->specie) + 1, this->specie);

		return copieSpecie;
	}

	void setSpecie(const char* specie) {
		if (this->specie != nullptr) delete[] this->specie;

		this->specie = validareSpecie(specie);
	}

	int getVarsta() {
		return this->varsta;
	}

	void setVarsta(int varsta) {
		this->varsta = validareVarsta(varsta);
	}

	double getProductieAnuala() {
		return this->productieAnuala;
	}

	void setProductieAnuala(double prodAn) {
		this->productieAnuala = validareProdAnuala(prodAn);
	}

	int getNrSuprafete() {
		return this->nrSuprafete;
	}

	double* getDimSuprafeteCultivate() {
		if (this->nrSuprafete == 0 || this->dimSuprafeteCultivate == nullptr) return nullptr;

		double* copieDimSup = new double[this->nrSuprafete];
		for (int i = 0; i < this->nrSuprafete; i++) {
			copieDimSup[i] = this->dimSuprafeteCultivate[i];
		}

		return copieDimSup;
	}

	void adaugaDimSuprafeteCultivate(double dim) {
		if (this->dimSuprafeteCultivate == nullptr) {
			this->dimSuprafeteCultivate = new double[++this->nrSuprafete];
			this->dimSuprafeteCultivate[this->nrSuprafete - 1] = dim;
		}
		else {
			double* rezultat = new double[++this->nrSuprafete];
			for (int i = 0; i < this->nrSuprafete - 1; i++) {
				rezultat[i] = this->dimSuprafeteCultivate[i];
			}

			rezultat[this->nrSuprafete - 1] = dim;
			delete[] this->dimSuprafeteCultivate;
			this->dimSuprafeteCultivate = rezultat;
		}
	}

	bool stergeDimSupCultPrinIndex(int index) {
		if (index < 0 || index >= this->nrSuprafete) return false;

		if (this->nrSuprafete == 1) {
			this->nrSuprafete = 0;
			delete[] this->dimSuprafeteCultivate;
			this->dimSuprafeteCultivate = nullptr;
			return true;
		}
		
		double* rezultat = new double[this->nrSuprafete - 1];
		for (int i = 0; i < index; i++) {
			rezultat[i] = this->dimSuprafeteCultivate[i];
		}
		for (int i = index; i < this->nrSuprafete - 1; i++) {
			rezultat[i] = this->dimSuprafeteCultivate[i + 1];
		}
		this->nrSuprafete--;
		delete[] this->dimSuprafeteCultivate;
		this->dimSuprafeteCultivate = rezultat;

		return true;
	}

	void stergeToateSuprafetele() {
		if (this->dimSuprafeteCultivate != nullptr) delete[] this->dimSuprafeteCultivate;
		this->dimSuprafeteCultivate = nullptr;
		this->nrSuprafete = 0;
	}

	static int getNrViteDeVie() {
		return nrViteDeVie;
	}

};

class Vin {
private:
	const int id;
	char* soi;
	string marca;
	int anProductie;
	float tarie;
	static int nrVinuri;

	static char* validareSoi(const char* soi) {
		char* rezultat;
		if (soi == nullptr || strlen(soi) == 0) {
			rezultat = new char[strlen("Nespecificat") + 1];
			strcpy_s(rezultat, strlen("Nespecificat") + 1, "Nespecificat");
		}
		else {
			rezultat = new char[strlen(soi) + 1];
			strcpy_s(rezultat, strlen(soi) + 1, soi);
		}

		return rezultat;
	}

	static string validareMarca(string marca) {
		if (marca.length() == 0) return "Nespecificat";

		return marca;
	}

	static int validareAnProductie(int an) {
		if (an < 1970) return 1970;
		if (an > 2025) return 2025;
		return an;
	}

	static float validareTarie(float tarie) {
		if (tarie < 0) return 0;
		if (tarie > 25) return 25;
		return tarie;
	}

public:
	Vin() :id(++nrVinuri) {
		this->soi = validareSoi(nullptr);
		this->marca = validareMarca("");
		this->anProductie = validareAnProductie(3000);
		this->tarie = validareTarie(0);
	}

	Vin(char* soi, string marca, int anProductie) :id(++nrVinuri) {
		this->soi = validareSoi(soi);
		this->marca = validareMarca(marca);
		this->anProductie = validareAnProductie(anProductie);
		this->tarie = validareTarie(0);
	}

	Vin(char* soi, string marca, int anProductie, float tarie) :id(++nrVinuri) {
		this->soi = validareSoi(soi);
		this->marca = validareMarca(marca);
		this->anProductie = validareAnProductie(anProductie);
		this->tarie = validareTarie(tarie);
	}

	/*
	const int id;
	char* soi;
	string marca;
	int anProductie;
	float tarie;
	static int nrVinuri;
	*/

	int getId() {
		return this->id;
	}

	char* getSoi() {
		if (this->soi == nullptr) return nullptr;

		char* copieSoi = new char[strlen(this->soi) + 1];
		strcpy_s(copieSoi, strlen(this->soi) + 1, this->soi);

		return copieSoi;
	}

	void setSoi(const char* soi) {
		if (this->soi != nullptr) delete[] this->soi;

		this->soi = validareSoi(soi);
	}

	string getMarca() {
		return this->marca;
	}

	void setMarca(string marca) {
		this->marca = validareMarca(marca);
	}

	int getAnProductie() {
		return this->anProductie;
	}

	void setAnProductie(int an) {
		this->anProductie = validareAnProductie(an);
	}

	int getTarie() {
		return this->tarie;
	}

	void setTarie(float tarie) {
		this->tarie = validareAnProductie(tarie);
	}

	static int getNrVinuri() {
		return nrVinuri;
	}

};


class Crama {
public:
	const int id;
	char* denumire;
	const int capacitateMaxima;
	Vin* vinuri;
	int* nrVin;
	static int nrCrame;
};

int VitaDeVie::nrViteDeVie = 0;
int Vin::nrVinuri = 0;

void main() {
	VitaDeVie* vita1 = new VitaDeVie();
	VitaDeVie* vita2 = new VitaDeVie("Nume", 10);
	double* dimSup = new double[3] {100, 200, 300};
	VitaDeVie* vita3 = new VitaDeVie("Specie1", 10, 500, 3, dimSup);
	delete[] dimSup;
	vita1->afisare();
	vita2->afisare();
	vita3->afisare();

	dimSup = new double[4] {50, 200, 20, 60};
	VitaDeVie* vita4 = new VitaDeVie("Specie2", 5, 600, 4, dimSup);
	delete[] dimSup;
	vita4->afisare();

	VitaDeVie::comparareSiAfisareProductie(vita3, vita4);

	cout << endl << "Getteri si Setteri Vita de Vie:";
	char* specie = vita3->getSpecie();
	cout << endl << "Id: " << vita3->getId() << ", Specie: " << specie << ", Varsta: " << vita3->getVarsta() << ", Productie Anuala: " << vita3->getProductieAnuala()
		<< ", Nr Suprafete Cultivate: " << vita3->getNrSuprafete();
	delete[] specie;
	if (vita3->getNrSuprafete() > 0) {
		dimSup = vita3->getDimSuprafeteCultivate();
		cout << ", Dimensiuni Suprafete:";
		for (int i = 0; i < vita3->getNrSuprafete(); i++) {
			cout << " " << dimSup[i];
		}
		delete[] dimSup;
	}
	cout << endl;
	cout << endl << "Total vite de vie: " << VitaDeVie::getNrViteDeVie();
	vita3->setSpecie("Alta Specie");
	vita3->setVarsta(100);
	vita3->setProductieAnuala(1000);
	vita3->adaugaDimSuprafeteCultivate(2000);
	cout << endl << "Modificare specie, varsta, productie anuala si adaugare suprafata:";
	vita3->afisare();
	cout << endl << "Stergere suprafata index 1";
	vita3->stergeDimSupCultPrinIndex(1);
	vita3->afisare();
	cout << endl << "Stergere toate suprafetele";
	vita3->stergeToateSuprafetele();
	vita3->afisare();

	delete vita1;
	delete vita2;
	delete vita3;
	delete vita4;
}