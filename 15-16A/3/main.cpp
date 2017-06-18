//
// Created by matematyk60 on 18.06.17.
//

#include <cstring>
#include <iostream>

class TextArray {
public:
    TextArray(int size_ = 8){
        max_size = size_;
        tab= new char*[max_size];
        size = 0;
    }

    ~TextArray(){
        for(int i = 0 ; i < size ; i++){
            delete [] *(tab+i);
        }
        delete [] tab;
    }

    TextArray(const TextArray& n){
        max_size = n.max_size;
        tab = new char*[max_size];
        size = n.size;
        for(int i  = 0 ; i < n.size ; i++){
            *(tab+i) = new char[std::strlen(*(n.tab+i))+1];
            std::strcpy(*(tab+i),*(n.tab+i));
        }
    }

    TextArray& operator=(const TextArray& n){
        if(this == &n){
            return *this;
        }
        for(int i = 0 ; i < size ; i++){
            delete [] *(tab+i);
        }
        delete [] tab;
        max_size = n.max_size;
        size = n.size;
        tab = new char*[max_size];
        for(int i  = 0 ; i < n.size ; i++){
            *(tab+i) = new char[std::strlen(*(n.tab+i))+1];
            std::strcpy(*(tab+i),*(n.tab+i));
        }
        return *this;

    }

    void resize(){
        char** new_ = new char*[max_size*2];
        for(int i = 0 ; i < size ; i++){
            *(new_+i) = new char[std::strlen(*(tab+i))+1];
            std::strcpy(*(new_+i),*(tab+i));
        }
        for(int i = 0 ; i < size ; i++){
            delete [] *(tab+i);
        }
        delete [] tab;
        tab = new_;
        max_size = max_size*2;
    }

    bool add(const char*napis) {
        if(size == max_size){
            resize();
        }
        *(tab+size) = new char[std::strlen(napis)+1];
        std::strcpy(*(tab+size),napis);
        size+=1;
        return true;
    }

    const char* get(int n){
        if(n < 0 || n > size){
            throw "InvalidIndex";
        }
        return tab[n-1];
    }

    void Print(){
        for(int i = 0 ; i < size; i++){
            std::printf(*(tab+i));
            std::cout << "\n";
        }
    }
private:
    char** tab;
    int size;
    int max_size;
};

int main(){
    const char *napis = "aba";
    char *napis2 = new char[5];
    //strcpy nie alokuje pamieci
    //strlen zwraca dlugosc stringa bez '\o'
    TextArray ta1;
    ta1.add("bysiu");
    ta1.add("depko");
    ta1.add("djepo");
    ta1.add("djepo");
    ta1.add("djepo");
    ta1.add("djepo");
    ta1.add("djepo");
    ta1.add("djepo");
    ta1.add("Co ten pukocz");


    TextArray ta2(ta1);
    ta2.add("malakser");
    ta1 = ta2;
    ta1.Print();
}
