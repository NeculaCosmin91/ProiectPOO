
#include <iostream>
#include <string>

#include "Client.h"

using namespace std;

Client::Client(int id, string nume) : id(id), nume(nume) {

}

istream &operator>>(istream &in, Client &f) {
    cout << "Introduceti Clientul:" << endl;

    cout << "Id: ";
    in >> f.id;

    cout << "Nume: ";
    in.get(); // de folosit inainte de a citi un rand
    getline(in, f.nume);

    return in;
}

ostream &operator<<(ostream &out, const Client &f) {
    cout << "Clientul" << endl;

    cout << "Id: " << f.id << endl;
    cout << "Nume: " << f.nume;

    return out;
}

int Client::operator[](int index) {
    return 0;
    // TODO change?
}

Client Client::operator++() {
    // TODO change?
    return *this;
}

Client Client::operator++(int) {
    // TODO change?
    return *this;
}

Client::operator char *() const {
    return nullptr; // TODO change
}

Client Client::operator!() {
    return *this;
}

bool Client::operator<(const Client &f) {
    return this->nume < f.nume; // comparare de string-uri, pentru a putea sorta clinetii dupa nume
}

bool Client::operator<=(const Client &f) {
    return this->nume <= f.nume; // comparare de string-uri, pentru a putea sorta clinetii dupa nume
}

bool Client::operator==(const Client &f) {
    return this->nume == f.nume && this->id == f.id;
}

// gettere si settere (toti setter-ii vor contine validari)

