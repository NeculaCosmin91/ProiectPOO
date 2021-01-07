#ifndef BILETE_SALA_H
#define BILETE_SALA_H

#include <iostream>

using namespace std;

class Sala {
private:
    int id;
    int numarLocuri;
    int numarLocuriLibere;
    int *locuriLibere; // vector alocat dinamic
public:
    // constructur cu parametri
    Sala(int id, int numarLocuri);

    Sala(int id, int numarLocuri, int numarLocuriLibere, const int *locuriLibere);

    // pt cele care contin valori alocate dinamic, obligatoriu CC, ~ si =

    Sala(const Sala &f);

    ~Sala();

    Sala operator=(const Sala &f);

    // operatori >> si <<
    friend istream &operator>>(istream &in, Sala &f);

    friend ostream &operator<<(ostream &out, const Sala &f);

    // []
    int operator[](int index) {
        return 0;
    }

    // +/-/*/\/
    Sala operator+(int);

    // ++ sau -- cu cele doua forme
    Sala operator++();

    Sala operator++(int);

    // cast catre un tip explicit sau implicit
    explicit operator char *() const;
    // !

    // </>/...
    bool operator<(const Sala &f);

    bool operator<=(const Sala &f);

    // ==
    bool operator==(const Sala &f);

    // gettere si settere (toti setter-ii vor contine validari)

};

#endif //BILETE_SALA_H
