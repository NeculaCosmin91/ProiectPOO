#include "SalaVIP.h"

SalaVIP::SalaVIP(int idSala, int totalScaune) {
    this->idSala = idSala;
    this->totalScaune = totalScaune;

    this->nrScauneLibere = totalScaune;
    this->ScauneLibere = new int[totalScaune];
    for (int i = 0; i < totalScaune; ++i) {
        ScauneLibere[i] = i;
    }
}


SalaVIP::SalaVIP(int idSala, int totalScaune, int nrScauneLibere, const int* ScauneLibere)
    : SalaVIP(idSala, totalScaune) {
    if (nrScauneLibere > 0) {
        this->nrScauneLibere = nrScauneLibere;
        this->ScauneLibere = new int[nrScauneLibere];
        for (int i = 0; i < nrScauneLibere; i++) {
            this->ScauneLibere[i] = ScauneLibere[i];
        }
    }
    else {
        this->nrScauneLibere = nrScauneLibere;
        ScauneLibere = nullptr;
    }
}

SalaVIP::SalaVIP(const SalaVIP& f) : SalaVIP(f.idSala, f.totalScaune, f.nrScauneLibere, f.ScauneLibere) {}

SalaVIP::~SalaVIP() {
    if (this->ScauneLibere) {
        delete[]this->ScauneLibere;
    }
}

SalaVIP SalaVIP::operator=(const SalaVIP& f) {
    this->idSala = f.idSala;

    this->totalScaune = f.totalScaune;

    this->nrScauneLibere = f.nrScauneLibere;

    if (this->ScauneLibere != nullptr) {
        delete[]this->ScauneLibere;
    }
    if (f.totalScaune > 0) {
        if (f.nrScauneLibere > 0) {
            
            this->ScauneLibere = new int[f.nrScauneLibere];
            for (int i = 0; i < f.nrScauneLibere; i++) {
                this->ScauneLibere[i] = ScauneLibere[i];
            }
        }
        else {
            this->nrScauneLibere = 0;
            this->ScauneLibere = nullptr;
        }
    }

    return *this;
}

istream& operator>>(istream& in, SalaVIP& f) {
    cout << "Introduceti datele Salii." << endl;

    cout << "Sala numarul: ";
    in >> f.idSala;

    cout << "Numar Scaune: ";
    in >> f.totalScaune;

    cout << "Scaune disponibile?";
    cin >> f.nrScauneLibere;

    if (f.nrScauneLibere >= f.totalScaune) {
        
        f.ScauneLibere = new int[f.totalScaune];
        for (int i = 0; i < f.totalScaune; ++i) {
            f.ScauneLibere[i] = i;
        }
        cout << "Am adaugat toate cele " << f.totalScaune << " scaune ca fiind libere" << endl;
    }
    else {
        f.ScauneLibere = new int[f.nrScauneLibere];
        cout << "Introduceti scaunele libere: ";
        for (int i = 0; i < f.nrScauneLibere; ++i) {
            cin >> f.ScauneLibere[i];
        }
    }

    return in;
}

ostream& operator<<(ostream& out, const SalaVIP& f) {
    out << "Sala:" << endl;

    out << "Id: " << f.idSala << endl;
    out << "Numar scaune: " << f.totalScaune << endl;
   
    out << "Scaunele libere sunt: ";
    for (int i = 0; i < f.nrScauneLibere; i++) {
        cout << f.ScauneLibere[i] << ' ';
    }
    cout << endl;

    return out;
}

SalaVIP SalaVIP::operator++() {
    
    int* vechi = this->ScauneLibere;
    this->totalScaune++;
    this->nrScauneLibere++;

    this->ScauneLibere = new int[this->nrScauneLibere];
    for (int i = 0; i < this->nrScauneLibere - 1; i++) {
        this->ScauneLibere[i] = vechi[i];
    }
    this->ScauneLibere[this->nrScauneLibere - 1] = this->nrScauneLibere - 1;

    return *this;
}

SalaVIP SalaVIP::operator++(int) {
    SalaVIP precedent = *this;

    int* vechi = this->ScauneLibere;
    this->totalScaune++;
    this->nrScauneLibere++;

    this->ScauneLibere = new int[this->nrScauneLibere];
    for (int i = 0; i < this->nrScauneLibere - 1; i++) {
        this->ScauneLibere[i] = vechi[i];
    }
    this->ScauneLibere[this->nrScauneLibere - 1] = this->nrScauneLibere - 1;

    return precedent;
}

SalaVIP SalaVIP::operator+(int locuriExtra) {
    SalaVIP nou = *this;
    return nou;
}

SalaVIP::operator char* () const { 
    return nullptr; 
}

bool SalaVIP::operator<(const SalaVIP& f) {
    return this->totalScaune < f.totalScaune;
}

bool SalaVIP::operator<=(const SalaVIP& f) {
    return *this < f || this->totalScaune <= f.totalScaune;
}

bool SalaVIP::operator==(const SalaVIP& f) {
    bool suntEgale = this->idSala == f.idSala &&
        this->totalScaune == f.totalScaune &&
        this->nrScauneLibere == f.nrScauneLibere;

    if (!suntEgale) {
        return false;
    }
    for (int i = 0; i < nrScauneLibere; i++) {
        if (this->ScauneLibere[i] != f.ScauneLibere[i]) {
            return false;
        }
    }

    return true;
}