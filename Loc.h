#ifndef BILETE_LOC_H
#define BILETE_LOC_H


#include "Sala.h"
#include <iostream>

using namespace std;

class Loc {
private:
    int id;
    const int numar;
    Sala sala;
public:
    // constructur cu parametri
    Loc(int id, int numar, Sala sala);

    // operatori >> si <<
    friend istream &operator>>(istream &in, Loc &f);

    friend ostream &operator<<(ostream &out, const Loc &f);

    // []
    int operator[](int index);

    // +/-/*/\/
//    TODO

    // ++ sau -- cu cele doua forme
    Loc operator++();

    Loc operator++(int);

    // cast catre un tip explicit sau implicit
    explicit operator char *() const;
    // !

    // </>/...
    bool operator<(const Loc &f);

    bool operator<=(const Loc &f);

    // ==
    bool operator==(const Loc &f);

    // gettere si settere (toti setter-ii vor contine validari)


};


#endif //BILETE_LOC_H
