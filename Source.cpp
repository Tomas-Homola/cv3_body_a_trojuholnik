#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Bod // class pre Bod
{
private:
	float x;
	float y;
	float z;

public:
	Bod(); // prazdny konstruktor
	Bod(float x, float y, float z); // ten druhy konstruktor

	void getData(float x, float y, float z); // funkcia na ziskanie dat
	void printData(); // funkcia na vypisanie dat

	void getX(float x) { this->x = x; } // zmena x suradnice
	void getY(float y) { this->y = y; } // zmena y suradnice
	void getZ(float z) { this->z = z; } // zmena z suradnice

	float X() { return this->x; } // vratenie x suradnice
	float Y() { return this->y; } // vratenie y suradnice
	float Z() { return this->z; } // vratenie z suradnice
};

Bod::Bod() // prazdny konstruktor
{
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}

Bod::Bod(float x, float y, float z) // konstruktor s konkretnymi hodnotami
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Bod::getData(float x, float y, float z) // funkcia na ziskanie dat o bode
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Bod::printData() // funkcia na vypisanie dat o bode
{
	cout << "x = " << this->x << ", y = " << this->y << ", z = " << this->z << endl;
}

class Trojuhlonik // class pre trojuholnik
{
private:
	Bod body[3];

public:
	Trojuhlonik(); // prazdny konstruktor
	Trojuhlonik(Bod bod1, Bod bod2, Bod bod3); // druhy konstruktor

	void getData(Bod bod1, Bod bod2, Bod bod3); // funkcia pre nacitane dat
	void printData(); // funkcia pre vypisanie dat
};

Trojuhlonik::Trojuhlonik() // prazdny konstruktor
{
	this->body[0].getData(0.0, 0.0, 0.0);
	this->body[1].getData(0.0, 0.0, 0.0);
	this->body[2].getData(0.0, 0.0, 0.0);
}

Trojuhlonik::Trojuhlonik(Bod bod1, Bod bod2, Bod bod3) // konstruktor s konkretnymi bodmi
{
	this->body[0] = bod1;
	this->body[1] = bod2;
	this->body[2] = bod3;
}

void Trojuhlonik::getData(Bod bod1, Bod bod2, Bod bod3) // funkcia na priradenie bodov
{
	this->body[0] = bod1;
	this->body[1] = bod2;
	this->body[2] = bod3;
}

void Trojuhlonik::printData() // funkcia pre vypisanie suradnic jednotlivych bodov
{
	cout << "Bod1:" << endl;
	this->body[0].printData();
	cout << "Bod2:" << endl;
	this->body[1].printData();
	cout << "Bod3:" << endl;
	this->body[2].printData();
}

int main()
{
	Bod bod1(1.2, 2.3, 3.4);
	Bod bod2;
	Bod bod3(7, 8, 9);

	bod1.printData();
	bod1.getData(4, 5, 6);
	bod1.printData();
	
	cout << "Bod2:" << endl;
	bod2.printData();

	Trojuhlonik t1;
	cout << "Data pre trojuholnik t1:" << endl;
	t1.printData();
	t1.getData(bod1, bod2, bod3);
	cout << "Nove data pre trojuholnik t1:" << endl;
	t1.printData();

	Trojuhlonik t2(bod1, bod2, bod3);
	cout << "Data pre trojuholnik t2:" << endl;
	t2.printData();






	return(0);
}