//
// Created by stefan on 1/6/21.
//

#include "Sala.h"

Sala::Sala(int id, int numarLocuri) {
    this->id = id;
    this->numarLocuri = numarLocuri;

    this->numarLocuriLibere = numarLocuri;
    this->locuriLibere = new int[numarLocuri];
    for (int i = 0; i < numarLocuri; ++i) {
        locuriLibere[i] = i;
    }
}


Sala::Sala(int id, int numarLocuri, int numarLocuriLibere, const int *locuriLibere)
        : Sala(id, numarLocuri) {
    if (numarLocuriLibere > 0) {
        this->numarLocuriLibere = numarLocuriLibere;
        this->locuriLibere = new int[numarLocuriLibere];
        for (int i = 0; i < numarLocuriLibere; i++) {
            this->locuriLibere[i] = locuriLibere[i];
        }
    } else {
        this->numarLocuriLibere = numarLocuriLibere;
        locuriLibere = nullptr;
    }
}

Sala::Sala(const Sala &f) : Sala(f.id, f.numarLocuri, f.numarLocuriLibere, f.locuriLibere) {}

Sala::~Sala() {
    if (this->locuriLibere) {
        delete[]this->locuriLibere;
    }
}

Sala Sala::operator=(const Sala &f) {
    this->id = f.id;

    this->numarLocuri = f.numarLocuri;

    this->numarLocuriLibere = f.numarLocuriLibere;

    if (this->locuriLibere != nullptr) {
        delete[]this->locuriLibere;
    }
    if (f.numarLocuri > 0) {
        if (f.numarLocuriLibere > 0) {
            // le copiem
            this->locuriLibere = new int[f.numarLocuriLibere];
            for (int i = 0; i < f.numarLocuriLibere; i++) {
                this->locuriLibere[i] = locuriLibere[i];
            }
        } else {
            this->numarLocuriLibere = 0;
            this->locuriLibere = nullptr;
        }
    }

    return *this;
}

istream &operator>>(istream &in, Sala &f) {
    cout << "Introduceti datele Salii." << endl;

    cout << "Id: ";
    in >> f.id;

    cout << "Numar Locuri: ";
    in >> f.numarLocuri;

    cout << "Cate locuri libere sunt?";
    cin >> f.numarLocuriLibere;

    if (f.numarLocuriLibere >= f.numarLocuri) {
        // add all of them
        f.locuriLibere = new int[f.numarLocuri];
        for (int i = 0; i < f.numarLocuri; ++i) {
            f.locuriLibere[i] = i;
        }
        cout << "Am adaugat toate cele " << f.numarLocuri << " locuri ca fiind libere" << endl;
    } else {
        f.locuriLibere = new int[f.numarLocuriLibere];
        cout << "Introduceti locurile libere: ";
        for (int i = 0; i < f.numarLocuriLibere; ++i) {
            cin >> f.locuriLibere[i];
        }
    }

    return in;
}

ostream &operator<<(ostream &out, const Sala &f) {
    out << "Sala:" << endl;

    out << "Id: " << f.id << endl;
    out << "Numar locuri: " << f.numarLocuri << endl;
    // afisam locurile libere
    out << "Locurile libere sunt: ";
    for (int i = 0; i < f.numarLocuriLibere; i++) {
        cout << f.locuriLibere[i] << ' ';
    }
    cout << endl;

    return out;
}

Sala Sala::operator++() {
    // adaugam un loc nou (neocupat)
    // TODO test if esteOcupat was allocated
    int *vechi = this->locuriLibere;
    this->numarLocuri++;
    this->numarLocuriLibere++;

    this->locuriLibere = new int[this->numarLocuriLibere];
    for (int i = 0; i < this->numarLocuriLibere - 1; i++) {
        this->locuriLibere[i] = vechi[i];
    }
    this->locuriLibere[this->numarLocuriLibere - 1] = this->numarLocuriLibere - 1;

    return *this;
}

Sala Sala::operator++(int) {
    Sala precedent = *this;

    // adaugam un loc nou (neocupat)
    // TODO test if esteOcupat was allocated
    int *vechi = this->locuriLibere;
    this->numarLocuri++;
    this->numarLocuriLibere++;

    this->locuriLibere = new int[this->numarLocuriLibere];
    for (int i = 0; i < this->numarLocuriLibere - 1; i++) {
        this->locuriLibere[i] = vechi[i];
    }
    this->locuriLibere[this->numarLocuriLibere - 1] = this->numarLocuriLibere - 1;

    // returnam valoarea precedenta a obiectului
    return precedent;
}

Sala Sala::operator+(int locuriExtra) {
    Sala nou = *this;
    // poate sa crestem numarul de locuri?
    return nou;
}

Sala::operator char *() const { // explicit
    return nullptr; // TODO return a char* for the whole object
}

bool Sala::operator<(const Sala &f) {
    return this->numarLocuri < f.numarLocuri;
}

bool Sala::operator<=(const Sala &f) {
    return *this < f || this->numarLocuri <= f.numarLocuri;
}

bool Sala::operator==(const Sala &f) {
    bool suntEgale = this->id == f.id &&
                     this->numarLocuri == f.numarLocuri &&
                     this->numarLocuriLibere == f.numarLocuriLibere;

    if (!suntEgale) {
        return false;
    }
    for (int i = 0; i < numarLocuriLibere; i++) {
        if (this->locuriLibere[i] != f.locuriLibere[i]) {
            return false;
        }
    }

    return true;
}
