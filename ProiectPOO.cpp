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
			cout << endl << "Dimensiuni suprafete cultivate: [" << dimSuprafeteCultivate[0];
			for (int i = 1; i < nrSuprafete - 1; i++) {
				cout << ", " << dimSuprafeteCultivate[i];
			}

			if (nrSuprafete > 1) {
				cout << dimSuprafeteCultivate[nrSuprafete - 1] << "]" << endl;
			}
			else {
				cout << "]" << endl;
			}
			
			
		}
		else {
			cout << endl << "Specia nu a fost cultivata" << endl;
		}
		

	}

	static void comparareSiAfisareProductie(VitaDeVie& v1, VitaDeVie& v2) {
		if (v1.nrSuprafete == 0 || v2.nrSuprafete == 0) {
			cout << endl << "Speciile nu pot fi comparate - date insuficiente";
			return;
		}

		double supTotala1 = 0;
		for (int i = 0; i < v1.nrSuprafete; i++) {
			supTotala1 += v2.dimSuprafeteCultivate[i];
		}
		double supTotala2 = 0;
		for (int i = 0; i < v1.nrSuprafete; i++) {
			supTotala2 += v2.dimSuprafeteCultivate[i];
		}

		double indice1 = v1.productieAnuala / supTotala1;
		double indice2 = v2.productieAnuala / supTotala2;

		if (indice1 > indice2) {
			cout << endl << "Specia " << v1.specie << " produce mai mult decat specia " << v2.specie << ", cu un indice de productivitate de "
				<< indice1 << " fata de " << indice2 << " pentru specia " << v2.specie << ".";
		}

		if (indice2 > indice1) {
			cout << endl << "Specia " << v2.specie << " produce mai mult decat specia " << v1.specie << ", cu un indice de productivitate de "
				<< indice2 << " fata de " << indice1 << " pentru specia " << v1.specie << ".";
		}

		if (indice1 == indice2) {
			cout << endl << "Speciile " << v1.specie << " si " << v2.specie << " au productivitati egale, cu indicele de productivitate egal cu " << indice1 << ".";
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
		
		double* rezultat = new double[--(this->nrSuprafete)];
		int k = 0;
		for (int i = 0; i < this->nrSuprafete + 1; i++) {
			if (i != index) {
				rezultat[k++] = this->dimSuprafeteCultivate[i];
			}
		}
		
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
	char* soi;
	string marca;
	int anProductie;
	const float tarie;

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
	Vin() :tarie(validareTarie(0)) {
		this->soi = validareSoi(nullptr);
		this->marca = validareMarca("");
		this->anProductie = validareAnProductie(3000);
	}

	Vin(const char* soi, string marca, int anProductie) :tarie(validareTarie(0)) {
		this->soi = validareSoi(soi);
		this->marca = validareMarca(marca);
		this->anProductie = validareAnProductie(anProductie);
	}

	Vin(const char* soi, string marca, int anProductie, float tarie) :tarie(validareTarie(tarie)) {
		this->soi = validareSoi(soi);
		this->marca = validareMarca(marca);
		this->anProductie = validareAnProductie(anProductie);
	}

	Vin(const Vin& vin) :tarie(validareTarie(vin.tarie)) {
		this->soi = validareSoi(vin.soi);
		this->marca = validareMarca(vin.marca);
		this->anProductie = validareAnProductie(vin.anProductie);
	}

	Vin& operator=(const Vin& vin) {
		if (this->soi != nullptr) delete[] this->soi;
		this->soi = validareSoi(vin.soi);
		this->marca = validareMarca(vin.marca);
		this->anProductie = validareAnProductie(vin.anProductie);

		return *this;
	}

	~Vin() {
		delete[] this->soi;
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

	friend ostream& operator<<(ostream& out, const Vin& vin) {
		out << endl << "Soi: " << vin.soi << endl << "Marca: " << vin.marca << endl << "An productie: "
			<< vin.anProductie << endl << "Tarie: " << vin.tarie << endl;
		return out;
	}

	bool operator==(const Vin& vin) {
		if (string(this->soi) != string(vin.soi)) return false;
		if (this->marca != vin.marca) return false;
		if (this->anProductie != vin.anProductie) return false;
		if (this->tarie != vin.tarie) return false;

		return true;
	}

};


class Crama {
private:
	const int id;
	char* denumire;
	const int capacitateMaxima;
	int nrVinuri;
	Vin** vinuri;
	int* cantitatiVin;
	static int nrCrame;

	static char* validareDenumire(const char* denumire) {
		char* rezultat;
		if (denumire == nullptr || strlen(denumire) == 0) {
			rezultat = new char[strlen("Nespecificat") + 1];
			strcpy_s(rezultat, strlen("Nespecificat") + 1, "Nespecificat");
		}
		else {
			rezultat = new char[strlen(denumire) + 1];
			strcpy_s(rezultat, strlen(denumire) + 1, denumire);
		}

		return rezultat;
	}

	static int validareCapacitate(int cap) {
		if (cap < 0) return 0;
		return cap;
	}

	static int validareNrVinuri(int nrVinuri) {
		if (nrVinuri < 0) throw "Numar Vinuri nu poate fi mai mic decat 0";

		return nrVinuri;
	}

	static int* validareCantVin(int n, int* cantitati) {
		int* rezultat = new int[n];
		for (int i = 0; i < n; i++) {
			if (cantitati[i] < 0) rezultat[i] = 0;
			else rezultat[i] = cantitati[i];
		}

		return rezultat;
	}

	int vinExista(const Vin& vin) {
		for (int i = 0; i < this->nrVinuri; i++) {
			if (*(this->vinuri[i]) == vin) return i;
		}

		return -1;
	}

public:

	Crama() :id(++nrCrame), capacitateMaxima(validareCapacitate(0)) {
		this->denumire = validareDenumire(nullptr);
		this->nrVinuri = 0;
		this->vinuri = nullptr;
		this->cantitatiVin = nullptr;
	}

	Crama(const char* denumire, int capacitateMaxima) :id(++nrCrame), capacitateMaxima(validareCapacitate(capacitateMaxima)) {
		this->denumire = validareDenumire(denumire);
		this->nrVinuri = 0;
		this->vinuri = nullptr;
		this->cantitatiVin = nullptr;
	}

	Crama(const char* denumire, int capacitateMaxima, int nrVinuri, Vin** vinuri, int* cantitatiVin) :id(++nrCrame), capacitateMaxima(validareCapacitate(capacitateMaxima)) {
		this->denumire = validareDenumire(denumire);
		this->nrVinuri = validareNrVinuri(nrVinuri);
		if (nrVinuri > 0) {
			this->cantitatiVin = validareCantVin(this->nrVinuri, cantitatiVin);
			if (this->cantitateTotala() > this->capacitateMaxima) {
				delete[] this->cantitatiVin;
				throw ("Crama nu poate depozita mai mult vin decat capacitatea maxima");
			}
				
			this->vinuri = new Vin*[this->nrVinuri];
			for (int i = 0; i < this->nrVinuri; i++) {
				this->vinuri[i] = new Vin(*(vinuri[i]));
			}
		}
		else
		{
			this->cantitatiVin = nullptr;
			this->vinuri = nullptr;
		}
		
	}

	~Crama() {
		if (this->denumire != nullptr) delete[] this->denumire;
		if (this->vinuri != nullptr) {
			for (int i = 0; i < this->nrVinuri; i++) {
				if (this->vinuri[i] != nullptr) delete this->vinuri[i];
			}
			delete[] this->vinuri;
		}
		
		if (this->cantitatiVin != nullptr) delete[] this->cantitatiVin;
	}
	

	int getId() {
		return id;
	}

	char* getDenumire() {
		if (this->denumire == nullptr) return nullptr;
		char* copie = new char[strlen(this->denumire) + 1];
		
		strcpy_s(copie, strlen(this->denumire) + 1, this->denumire);
		
		return copie;
	}

	void setDenumire(const char* denumire) {
		if (this->denumire != nullptr) delete[] this->denumire;
		this->denumire = validareDenumire(denumire);
	}

	int getCapacitateMaxima() {
		return this->capacitateMaxima;
	}

	int getNrVinuri() {
		return this->nrVinuri;
	}

	Vin** getVinuri() {
		if (this->nrVinuri == 0 || this->vinuri == nullptr) return nullptr;
		Vin** copie = new Vin*[this->nrVinuri];
		for (int i = 0; i < this->nrVinuri; i++) {
			copie[i] = new Vin(*(this->vinuri[i]));
		}

		return copie;
	}

	int* getCanTitatiVin() {
		int* copie = new int[this->nrVinuri];
		for (int i = 0; i < this->nrVinuri; i++) {
			copie[i] = this->cantitatiVin[i];
		}
	}

	bool operator+(const Vin& vin) {
		if (this->cantitateTotala() == this->capacitateMaxima) return false;
		int index = this->vinExista(vin);
		if (index >= 0) {
			this->cantitatiVin[index]++;
			return true;
		}

		Vin** rezVin = new Vin * [this->nrVinuri + 1];
		int* rezCant = new int[this->nrVinuri + 1];

		for (int i = 0; i < this->nrVinuri; i++) {
			rezVin[i] = this->vinuri[i];
			rezCant[i] = this->cantitatiVin[i];
		}

		delete[] this->vinuri;
		delete[] this->cantitatiVin;

		this->nrVinuri++;
		rezVin[this->nrVinuri - 1] = new Vin(vin);
		rezCant[this->nrVinuri - 1] = 1;

		this->vinuri = rezVin;
		this->cantitatiVin = rezCant;

		return true;
	}

	friend ostream& operator<<(ostream& out, const Crama& crama) {
		out << endl << "Id: " << crama.id << endl << "Denumire: " << crama.denumire << endl << "Capacitate Maxima: " << crama.capacitateMaxima
			<< endl << "Tipuri vin: " << crama.nrVinuri;
		if (crama.nrVinuri > 0) {
			out << endl << "Vinuri si cantitati: " << endl << "..........................." <<
				endl << crama.cantitatiVin[0] << " X " << *(crama.vinuri[0]);
			for (int i = 1; i < crama.nrVinuri; i++) {
				out << endl << crama.cantitatiVin[i] << " X " << *(crama.vinuri[i]);
			}

			
			out << "..........................." << endl;
		}

		return out;
	}

	int operator[](const Vin& vin) {
		int index = vinExista(vin);

		if (index == -1) return index;

		return this->cantitatiVin[index];
	}

	Vin* operator[](const int index) {
		if (index < 0 || index >= this->nrVinuri) return nullptr;
		return this->vinuri[index];
	}

	void operator()(const Vin& vin, const int cantitate) {
		if (this->capacitateMaxima < this->cantitateTotala() + cantitate) throw "Cantitatea de vin nu poate fi adaugata: Capacitate maxima depasita";
		int index = vinExista(vin);
		if (index == -1) {
			if (cantitate < 0) return throw "Cantitatea nu poate fi scoasa: Vinul nu exista";
			*this + vin;
			this->cantitatiVin[this->nrVinuri - 1] = cantitate;
		}
		else {
			if (this->cantitatiVin[index] + cantitate < 0) throw "Cantiatea nu poate fi scoasa: Cantitate insuficienta de vin in crama";
			this->cantitatiVin[index] += cantitate;
		}

	}

	int cantitateTotala() {
		int sum = 0;
		for (int i = 0; i < this->nrVinuri; i++) {
			sum += this->cantitatiVin[i];
		}

		return sum;
	}

};

int VitaDeVie::nrViteDeVie = 0;
int Crama::nrCrame = 0;

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

	VitaDeVie::comparareSiAfisareProductie(*vita3, *vita4);

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

	Vin vin1;
	Vin vin2("Soi1", "Marca1", 2018);
	Vin vin3("Soi2", "Marca2", 2022, 12);

	cout << vin1 << vin2 << vin3;

	Crama crama1;
	Crama crama2("Crama1", 20);
	Crama* crama3 = nullptr;

	Vin** vinuri = new Vin*[3] {&vin1, & vin2, & vin3};
	int* cantitati = new int[3] {5, 6, 7};
	try {
		crama3 = new Crama("Crama2", 20, 3, vinuri, cantitati);
	}
	catch (const string e) {
		cout << endl << e;
	}

	delete[] vinuri;
	delete[] cantitati;

	cout << crama1 << crama2 << *crama3;

	Vin vin4("Soi3", "Marca3", 1998, 12);

	cout << endl << (*crama3 + vin3 ? "Vin adaugat" : "Capacitate maxima atinsa");
	cout << endl << (*crama3 + vin4 ? "Vin adaugat" : "Capacitate maxima atinsa");
	cout << endl << (*crama3 + vin4 ? "Vin adaugat" : "Capacitate maxima atinsa");
	cout << *crama3;

	if (crama3 != nullptr) delete crama3;

	Crama crama4("Crama3", 100);
	try {
		crama4(vin2, 30);
		crama4(vin3, 40);
		crama4(vin4, 25);
	}
	catch (const char* e) {
		cout << endl << e;
	}

	try {
		crama4(vin2, 30);
		crama4(vin3, 40);
		crama4(vin4, 25);
	}
	catch (const char* e) {
		cout << endl << e;
	}

	cout << endl << crama4;

	try {
		crama4(vin3, 50);
	}
	catch (const char* e) {
		cout << endl << e;
	}

	try {
		crama4(vin4, -30);
	}
	catch (const char* e) {
		cout << endl << e;
	}

	try {
		crama4(vin3, -5);
	}
	catch (const char* e) {
		cout << endl << e;
	}

	try {
		crama4(vin1, -10);
	}
	catch (const char* e) {
		cout << endl << e;
	}

	cout << endl << crama4;
}