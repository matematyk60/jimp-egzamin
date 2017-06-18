//
// Created by matematyk60 on 18.06.17.
//

#include <iostream>

class LE{
public:
    LE(int rozm){
        tablica = new int[rozm];
        rozmiar= rozm;
        licznik = 0;
        next = nullptr;
    }
    ~LE(){
        if(next != nullptr){
            delete next;
        }
        delete [] tablica;
    }

    void addElement(int value){
        if(licznik >= rozmiar){
            next->addElement(value);
        } else{
            tablica[licznik] = value;
            licznik++;
            if(licznik == rozmiar){
                next = new LE(rozmiar);
            }
        }
    }

    int pobierz(int n){
        if(n>rozmiar){
            return next->pobierz(n-rozmiar);
        } else{
            return tablica[n-1];
        }
    }
private:
    int*tablica;
    //tablica na dane
    int rozmiar;
    //rozmiar tablicy
    int licznik;
    //ile zajetych
    LE *next;
};

class ListaTablic{
public:
    ListaTablic(){
        lista = new LE(5);
    }
    ~ListaTablic(){
        delete lista;
    }
    void Dodaj(int value){
        lista->addElement(value);
    }

    int pobierz(int n){
        return lista->pobierz(n);
    }
private:
    LE *lista;
};

int main(){
    ListaTablic l1;
    l1.Dodaj(2);
    l1.Dodaj(2);
    l1.Dodaj(2);
    l1.Dodaj(2);
    l1.Dodaj(2);
    l1.Dodaj(2);
    l1.Dodaj(2);
    l1.Dodaj(9);
    l1.Dodaj(2);
    l1.Dodaj(2);
    l1.Dodaj(2);
    l1.Dodaj(2);
    l1.Dodaj(2);
    l1.Dodaj(2);
    std::cout << l1.pobierz(8);
}