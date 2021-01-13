#ifndef BILETE_VIP_H
#define BILETE_VIP_H


#include "Sala.h"
#include <iostream>

using namespace std;

class VIP {
private:
    int coloana;
    const int rand;
    Sala sala;
public:
    // constructur cu parametri
    VIP(int id, int numar, Sala sala);

    // operatori >> si <<
    friend istream& operator>>(istream& in, VIP& f);

    friend ostream& operator<<(ostream& out, const VIP& f);

    
    int operator[](int index);

    VIP operator++();

    VIP operator++(int);

   
    explicit operator char* () const;
   

  
    bool operator<(const VIP& f);

    bool operator<=(const VIP& f);

    // ==
    bool operator==(const VIP& f);

   


};


#endif //BILETE_LOC_H