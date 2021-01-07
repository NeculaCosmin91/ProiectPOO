#ifndef BILET_H
#define BILET_H

#include <ostream>
#include "Film.h"
#include "Loc.h"
#include "Sala.h"

class Bilet {
private:
    static int bileteProcesate;
    Film film;
    Loc loc; // contine si sala
public:

    // constructur cu parametri
    Bilet(const Film &f, const Loc &l);

    // operatori >> si <<
    friend ostream &operator<<(ostream &os, const Bilet &bilet);
    friend istream& operator>>(istream &in, Bilet& b);
    // []
    int operator[](int index);
    // +/-/*/\/
    // TODO
    // ++ sau -- cu cele doua forme
    Bilet operator++();
    Bilet operator++(int);
    // cast catre un tip explicit sau implicit
    explicit operator char*();
    // !
    Bilet operator!();
    // </>/...
    bool operator<=(int minutes);
    // ==
    bool operator==(const Bilet& b);
    // set vor contine validari
};

//int Bilet::bileteProcesate = 0;

#endif //BILET_H
