//
// Created by matematyk60 on 17.06.17.
//

#include <iostream>

class Animal{
public:
    virtual ~Animal(){};
    virtual void Print() const = 0;
};

class Cat : public Animal{
public:
    ~Cat(){}

    void Print() const override {
        std::cout<<"kot" << std::endl;
    }
};

class Frog : public Animal{
public:
    ~Frog(){}

    void Print() const override {
        std::cout<<"zaba" << std::endl;
    }
};

class Dog : public Animal{
public:
    ~Dog(){}

    void Print() const override {
        std::cout<<"pies" << std::endl;
    }
};

class AnimalList {
    struct Node{
        Animal *value;
        Node* next;
    };
public:
    AnimalList(){
        list = nullptr;
    }
    AnimalList(const AnimalList& al1){
        //brakuje konstruktora kopiujacego
    }

    ~AnimalList(){
        if(list == nullptr){
            return;
        }
        Node* actual = list;
        Node* next = actual->next;
        while(next != nullptr){
            delete actual->value;
            delete actual;
            actual = next;
            next = actual->next;
        }
        delete actual->value;
        delete actual;
        list = nullptr;
    }
    void add(Animal *a){
        if(list == nullptr){
            list = new Node;
            list->value = a;
            list->next = nullptr;
            return;
        }
        Node* n = list;
        while(n->next != nullptr){
            n = n->next;
        }
        n->next = new Node;
        n->next->value = a;
        n->next->next = nullptr;
    }

    void Print(){
        Node* n = list;
        while(n->next != nullptr){
            n->value->Print();
            n = n->next;
        }
        n->value->Print();
    }




private:
    Node *list;
};


int main(){
    AnimalList lista1;
    Animal* a1 = new Dog;
    lista1.add(a1);
    lista1.add(new Cat);
    lista1.add(new Frog);
    lista1.Print();


}




