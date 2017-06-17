//
// Created by matematyk60 on 17.06.17.
//

#include <utility>
#include <map>
#include <vector>
#include <list>
#include <cmath>
#include <iostream>

struct Miasto{
public:
    Miasto(const char *nazwa, double x = 0, double y= 0){
        this->x = x;
        this->y = y;
        this->nazwa = nazwa;
    }
    const char *nazwa;
    double x;
    double y;
};

struct Droga{
    int m1;
    int m2;
    double d;
    Droga(int m1, int m2, double d){
        this->m1 = m1;
        this->m2 = m2;
        this->d = d;
    }
};

class Mapa {
public:
    Mapa(){
        this->nextId=0;
    }

    int DodajMiasto(const char *nazwa, double x, double y){
        int id = nextId;
        miasta.insert(std::pair<int,Miasto>(id,Miasto(nazwa,x,y)));
        nextId++;
        return id;
    }
    bool DodajDroge(int m1, int m2, double dl){
        if(miasta.find(m1)== miasta.end() || miasta.find(m2) == miasta.end()){
            return false;
        }
        drogi.emplace_back(Droga(m1,m2,dl));
        return true;
    }

    void sasiedzi(int m, std::list<int>&sa){
        for(auto &n : drogi){
            if(n.m1 == m){
                sa.emplace_back(n.m2);
            } else if (n.m2 == m){
                sa.emplace_back(n.m1);
            }
        }
    }

    double odleglosc(int m1, int m2){
        Miasto miasto1 = miasta.find(m1)->second;
        Miasto miasto2 = miasta.find(m2)->second;
        return std::sqrt((miasto2.x - miasto1.x)*(miasto2.x - miasto1.x)+(miasto2.y - miasto1.y)*(miasto2.y - miasto1.y));
    }


private:
    std::map<int, Miasto> miasta;
    std::vector<Droga> drogi;
    int nextId;

};


int main(){
    Mapa mapa;
    int miasto1 = mapa.DodajMiasto("Krosno", 0, 0);
    int miasto2 = mapa.DodajMiasto("Krakow", 33, 1);
    std::cout << mapa.DodajDroge(miasto1, miasto2, 33) << std::endl << mapa.odleglosc(miasto1,miasto2);
}