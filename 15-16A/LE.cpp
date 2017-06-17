
#include "LE.h"

LE::LE(int rozm) {
    tablica = new int[rozm];
    rozmiar = rozm;
    licznik = 0;
    next = nullptr;
}

LE::~LE() {
    delete [] tablica;
}

int LE::Rozmiar() const {
    return rozmiar;
}

int LE::Licznik() const {
    return licznik;
}

