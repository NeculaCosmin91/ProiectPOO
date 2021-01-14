#include <iostream>
#ifndef BILETE_SalaVIP_H
#define BILETE_SalaVIP_H

using namespace std;

class SalaVIP {
private:
    int idSala;
    int totalScaune;
    int nrScauneLibere;
    int* ScauneLibere; // vector alocat dinamic
public:
    // constructur cu parametri
    SalaVIP(int idSala, int totalScaune);

    SalaVIP(int idSala, int totalLocuri, int nrScauneLibere, const int* ScauneLibere);

    // pt cele care contin valori alocate dinamic, obligatoriu CC, ~ si =

    SalaVIP(const SalaVIP& f);

    ~SalaVIP();

    SalaVIP operator=(const SalaVIP& f);

    // operatori >> si <<
    friend istream& operator>>(istream& in, SalaVIP& f);

    friend ostream& operator<<(ostream& out, const SalaVIP& f);

    // []
    int operator[](int index) {
        return 0;
    }

    // +/-/*/\/
    SalaVIP operator+(int);

    // ++ sau -- cu cele doua forme
    SalaVIP operator++();

    SalaVIP operator++(int);

    // cast catre un tip explicit sau implicit
    explicit operator char* () const;
    // !

    // </>/...
    bool operator<(const SalaVIP& f);

    bool operator<=(const SalaVIP& f);

    // ==
    bool operator==(const SalaVIP& f);

    // gettere si settere (toti setter-ii vor contine validari)

};

#endif 