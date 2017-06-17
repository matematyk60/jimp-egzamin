//
// Created by matematyk60 on 17.06.17.
//

#include <iostream>
#include <list>
#include <tgmath.h>
#include <vector>


class Wielomian {
public:
    Wielomian(std::initializer_list<double> wielo){
        for(auto n : wielo){
            wielomian.emplace_back(n);
        }
    }

    Wielomian(std::list<double> wielo){
        for(auto n : wielo){
            wielomian.emplace_back(n);
        }
    }
    double wartosc(double x){
        double answer = 0;
        for(int i = 0 ; i < wielomian.size() ; i++){
            answer += wielomian[i]*pow(x,i);
        }
        return answer;
    }

    void ustawWspolczynnik(int n, double value){
        wielomian[n] = value;
    }

    friend std::ostream& operator<<(std::ostream& output, Wielomian& w1){
        for(int i = 0 ; i < w1.wielomian.size() ; i++){
            output << w1.wielomian.at(i) << "x^" << i ;
            if(i != w1.wielomian.size()-1){
                output << " + ";
            }
        }
        output << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream &input, Wielomian& w1){
        std::list<double> lista;
        while(input.peek() != -1){
            lista.emplace_back(Wielomian::Wspolczynnik(input));
            Wielomian::SkipPlus(input);
        }
        w1 = Wielomian(lista);
        return input;
    }

    static double Wspolczynnik(std::istream& input){
        std::stringstream ss;
        std::string pa = "";
        double a = 0;
        while(input.peek() != 'x'){
            pa += input.get();
        }
        ss << pa;
        ss >> a;
        while(input.peek() != ' ' && input.peek() != -1){
            input.ignore();
        }
        return a;
    }

    static void SkipPlus(std::istream& input){
        while(input.peek() == ' ' || input.peek() == '+'){
            input.ignore();
        }
    }

    Wielomian operator+(Wielomian w2){
        std::list<double> lista;
        double a1, a2;
        std::vector<double>::iterator it = this->wielomian.begin();
        std::vector<double>::iterator it2 = w2.wielomian.begin();
        while(it != this->wielomian.end() || it2 != w2.wielomian.end()){
            if(it != this->wielomian.end()){
                a1 = *it;
            } else{
                a1 = 0;
            }
            if(it2 != w2.wielomian.end()){
                a2 = *it2;
            } else{
                a2 = 0;
            }
            lista.emplace_back(a1+a2);
            if(it != this->wielomian.end()) {
                it++;
            }
            if(it2 != w2.wielomian.end()) {
                it2++;
            }
        }
        return Wielomian(lista);
    }

    Wielomian operator*(Wielomian w2){
        std::vector<Wielomian> wielomiany;
        std::list<double> lista;
        for(int i = 0 ; i < this->wielomian.size() ; i++){
            lista.clear();
            for(int j = 0 ; j < i ; j++){
                lista.emplace_back(0);
            }
            for(int j = 0 ; j < w2.wielomian.size() ; j++){
                lista.emplace_back(this->wielomian[i]*w2.wielomian[j]);
            }
            wielomiany.emplace_back(Wielomian(lista));
        }
        Wielomian answer = *(wielomiany.begin());
        for(auto it = wielomiany.begin()+1 ; it != wielomiany.end() ; it++ ){
            answer = answer+*it;
        }
        return answer;
    }

private:
    std::vector<double> wielomian;

};

int main(){
    std::stringstream ss;

    Wielomian w1{2,0,0,0,0,3};

    Wielomian w2{1,0,2};
    Wielomian w3 = w1*w2;
    std::cout << w3;

}