#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Film
{
private:
	const int id;
	char* producator;
	int an;
	static string nume;

	Film(int id, char* producator, int an, string nume) :id(1)
	{
		if (producator != nullptr)
		{
			this->producator = new char[strlen(producator) + 1];
			strcpy_s(this->producator, strlen(producator) + 1, producator);
		}
		else
		{
			this -> producator = nullptr;
		}
		this->an = an;
		this->nume = nume;
	}

	Film(const Film& f) :id(f.id)
	{
		if (producator != nullptr)
		{
			this->producator = new char[strlen(f.producator) + 1];
			strcpy_s(this->producator, strlen(f.producator) + 1, f.producator);
		}
		else
		{
			this->producator = nullptr;
		}
		an = f.an;
		nume = f.nume;

	}

};

class Bilet
{
	const int nrBilete;
	int pret;
};

class Sala
{
	const int nrLocuri;
	char* numeSala;
	int randuri;
	
};

class RezervareOnline
{

};

class SalaVIP
{

};

int main()
{

};