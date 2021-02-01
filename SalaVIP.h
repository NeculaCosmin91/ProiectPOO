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
   
    SalaVIP(int idSala, int totalScaune);

    SalaVIP(int idSala, int totalLocuri, int nrScauneLibere, const int* ScauneLibere);

    SalaVIP(const SalaVIP& f);

    ~SalaVIP();

    SalaVIP operator=(const SalaVIP& f);

    friend istream& operator>>(istream& in, SalaVIP& f);

    friend ostream& operator<<(ostream& out, const SalaVIP& f);

    // []
    int operator[](int index) {
        return 0;
    }
    SalaVIP operator+(int);

    SalaVIP operator++();

    SalaVIP operator++(int);

    explicit operator char* () const;

    bool operator<(const SalaVIP& f);

    bool operator<=(const SalaVIP& f);

    // ==
    bool operator==(const SalaVIP& f);


};

#endif 