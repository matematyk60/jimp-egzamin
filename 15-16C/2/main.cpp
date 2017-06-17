//
// Created by matematyk60 on 17.06.17.
//
#include <list>
#include <map>
#include <iostream>

using namespace std;

class Slownik{
public:
    void dodaj(const char* term, const char* znaczenie) {
        if (slownik.find(term) != slownik.end()) {
            slownik.find(term)->second.emplace_back(znaczenie);
        } else {
            slownik.insert(std::pair<string, std::list<string>>(term, std::list<string>{znaczenie}));
        };
    }

    list<string> szukaj(const char *term){
        std::map<string,std::list<string>>::iterator it = slownik.find(term);
        if(it != slownik.end()){
            return it->second;
        } else{
            return list<string>();
        }
    }

    void usun(const char *term){
        slownik.erase(term);
    }

    void usun(const char *term, const char *znaczenie){
        std::map<string,std::list<string>>::iterator it = slownik.find(term);
        for( auto it2 = it->second.begin(); it2 != it->second.end() ; it2++){
            if(*it2 == znaczenie){
                it->second.erase(it2);
                break;
            }
        }
        if(it->second.empty()){
            slownik.erase(term);
        }

    }
private:
    std::map<string,std::list<string>> slownik;
};



int main(){
    Slownik s1;
    s1.dodaj("matma", "z bysiewiczem");
    s1.dodaj("matma", "z depem");
    s1.dodaj("matma", "z dominikiem");
    s1.usun("matma", "z dominikiem");
    s1.dodaj("fizyka", "z basia");
    list<string> l1 = s1.szukaj("fizyka");
    for(auto n : l1){
        cout << n;
    }
}