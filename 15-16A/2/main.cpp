//
// Created by matematyk60 on 18.06.17.
//
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using ::std::string;

class Miasto{
public:
    friend class ZbiorMiast;
    Miasto(string nazwa, double x, double y){
        this->nazwa = nazwa;
        this->x = x;
        this->y = y;
    }
    string getNazwa()const{
        return nazwa;
    }
    /*double getX()const {return x;}
    double getY()const {return y;}*/

private:
    std::string nazwa;
    double x;
    double y;
};

class ZbiorMiast{
public:
    bool dodaj(const Miasto& m){
        string name = m.nazwa;
        std::vector<Miasto*>::iterator it = std::find_if(miasta.begin(), miasta.end(), [name](Miasto* tmp)->bool{return tmp->nazwa == name; });
        if(it == miasta.end()){
            miasta.emplace_back(new Miasto(m));
            return true;
        } else{
            (*it)->x = m.x;
            (*it)->y = m.y;
            return false;
        }
    }
    Miasto *znajdz(const char *name){
        auto it = std::find_if(miasta.begin(), miasta.end(), [name](Miasto*tmp)->bool{return tmp->nazwa == name;});
        if(it == miasta.end()){
            return nullptr;
        } else {
            return (*it);
        }
    }
    void dodaj(const ZbiorMiast&z){
        for(auto n : z.miasta){
            this->dodaj(*n);
        }
    }

    void usunSpoza(const ZbiorMiast&z){
        int i = 0;
        std::cout<<miasta.size()<< "\n\n";
        for(std::vector<Miasto*>::iterator n = miasta.begin() ; n != miasta.end() ; ){
            auto it = std::find_if(z.miasta.begin(),z.miasta.end(), [n](Miasto*tmp)->bool{return tmp->nazwa == (*n)->nazwa;});
            if(it == z.miasta.end()){
                delete (*n);
                miasta.erase(n);
            } else{
                n++;
            }
        }
    }

    void Print(){
        for(auto n : miasta){
            std::cout << n->nazwa << " " << n->x << " " << n->y << " | ";
        }
        std::cout << "\n";
    }


private:
    std::vector<Miasto*> miasta;
};

int main(){
    ZbiorMiast z1;
    z1.dodaj(Miasto("Krosno",0,0));
    z1.dodaj(Miasto("Krakow",2,2));
    z1.dodaj(Miasto("Warszawa",3,2));
    z1.Print();
    ZbiorMiast z2;
    z2.dodaj(Miasto("Przemysl",1,1));
    z2.dodaj(Miasto("Stepina",3,4));
    z2.Print();
    z1.dodaj(z2);
    z1.dodaj(Miasto("Stepina",2,2));
    z1.Print();
    z1.usunSpoza(z2);
    z1.Print();


}