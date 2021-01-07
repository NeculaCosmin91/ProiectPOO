#include <cstring>
#include "Bilet.h"

Bilet::Bilet(const Film &film, const Loc &loc) : film(film), loc(loc) {}

ostream &operator<<(ostream &out, const Bilet &b) {
    out << "Biletul are urmatoarele rezervari:" << endl;

    out << "Filmul este" << endl;
    out << b.film;

    out << "Locul este" << endl;
    out << b.loc;

    return out;
}

istream &operator>>(istream &in, Bilet &b) {
    cout << "Introduceti filmul" << endl;
    in >> b.film;

    cout << "Introduceti locul" << endl;
    in >> b.loc;

    return in;
}

int Bilet::operator[](int index) {
    return 0; // TODO change?
}

Bilet Bilet::operator++() {
    // TODO change this?
    return *this;
}

Bilet Bilet::operator++(int) {
    Bilet old = *this;
    // TODO change?
    return old;
}

Bilet Bilet::operator!() {
    return *this; // TODO change?
}

bool Bilet::operator<=(int minutes) {
    return this->film.getMinutes() < minutes;
}

bool Bilet::operator==(const Bilet &b) {
    return this->film == b.film &&
           this->loc == b.loc;
}

// TODO nu il vede?
Bilet::operator char *() {
    char *s = new char[1000];
    strcpy_s(s, 1000, "");
 
    strcat_s(s, 1000, (char *) this->film);
    strcat_s(s, 1000, (char *) this->loc);
    return s;
}
