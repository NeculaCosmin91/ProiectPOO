#include "VIP.h"
#include "Sala.h"

VIP::VIP(int coloana, int rand, Sala sala) : rand(rand), sala(sala) {
    this->coloana = coloana;
}

istream& operator>>(istream& in, VIP& f) {
    cout << "Introduceti Locul:" << endl;

    cout << "Id: ";
    in >> f.coloana;

    cout << "Numar: ";
    // pentru initializarea dupa constructor a const int numar:
    int* numar = const_cast<int*>(&f.rand);
    int numarNou;
    in >> numarNou;
    *numar = numarNou;

    cout << "Sala este" << endl;
    in >> f.sala;

    return in;
}

ostream& operator<<(ostream& out, const VIP& f) {
    cout << "Locul:" << endl;

    out << "Id: " << f.coloana << endl;
    out << "Numar: " << f.rand << endl;
    out << "Sala este" << endl;
    cout << f.sala;

    return out;
}

int VIP::operator[](int index) {
    return 0;// TODO change?
}

VIP VIP::operator++() {
    // TODO change?
    return *this;
}

VIP VIP::operator++(int) {
    // TODO change?
    return *this;
}

VIP::operator char* () const {
    return nullptr; // TODO itoa
}

bool VIP::operator<(const VIP& f) {
    return this->rand < f.rand;
}

bool VIP::operator<=(const VIP& f) {
    return this->rand <= f.rand;
}

bool VIP::operator==(const VIP& f) {
    return this->coloana == f.coloana &&
        this->rand == f.rand &&
        this->sala == f.sala;
}