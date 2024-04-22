#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Olimpia {
	int hely;
	int csszam;
	string sportag;
	string verseny;
};

class Helsinki {
private: int db = 0;
private: Olimpia* versenyszam;
public: Helsinki(char* filename) {
	ifstream be(filename);
	if (be.fail()) { cerr << "HIBA!"; exit(1); }
	string line;
	while (!be.eof())
	{
		getline(be, line);
		db++;
	}
	be.clear();
	be.seekg(0, ios::beg);
	versenyszam = new Olimpia[db];
	int i = 0;
	while (!be.eof()) {
		be >> versenyszam[i].hely >> versenyszam[i].csszam >> versenyszam[i].sportag >> versenyszam[i].verseny;
		i++;
	}
}
	  int kiír() {
		  int vdb = 0;
		  cout.setf(ios::left);
		  cout << setw(10) << "Helyezes:" << setw(10) << "Letszam:" << setw(15) << "Sportag:" << setw(30) << "Versenyszam: " << endl;
		  for (int i = 0; i < db; i++) {
			  cout << setw(10) << versenyszam[i].hely << setw(10) << versenyszam[i].csszam << setw(15) << versenyszam[i].sportag << setw(30)<< versenyszam[i].verseny << endl;
			  if (versenyszam[i].hely < 4) {
				  vdb++;
			  }
		  }
		  cout << "A magyar olimpikonok " << vdb << " pontszerzo helyezest ertek el." << endl;
		  return db;
	  }
	  int elsokszama() {
		  int edb = 0;
		  for (int i = 0; i < db; i++) {
			  if (versenyszam[i].hely == 1) {
				  edb++;
			  }
		  }
		  return edb;
	  }

	  string lgtobbsportag() {
		  string lgtobb;
		  int max = 0;
		  for (int i = 1; i < db; i++) {
			  if (versenyszam[i].csszam > versenyszam[max].csszam) {
				  max = i;
				  lgtobb = versenyszam[i].sportag;
			  }
		  }
		  return lgtobb;
	  }

	  int uszok() {
		  for (int i = 0; i < db; i++) {
			  if ((versenyszam[i].sportag == "uszas") && (versenyszam[i].hely < 4)) {
				  cout << versenyszam[i].verseny << "\t" << versenyszam[i].hely << endl;
			  }
		  }
		  return 0;
	  }
	  ~Helsinki() {
		  delete[] versenyszam;
	  }
}; //breakpoint?

int main()
{
	char filename[] = "helsinki.txt";
	Helsinki helsinki(filename);
	helsinki.kiír();
	cout << "\nElso helyezettek szama: " << helsinki.elsokszama() << endl;
	cout << "\n" << helsinki.lgtobbsportag() << " sportagban ert el a helyezest a legtobb versenyzonk\n";
	cout << "\nErmes uszok:\n" << helsinki.uszok() << endl;
}