//
// Created by matematyk60 on 17.06.17.
//

#include <cstdio>

class A {
public:
    virtual void f(){
        printf("A.f \n");
    }
    A() {f();}
    ~A(){
        printf("~A.f \n");
    }
};

class B : public A
{
public:
    A*a;
    void f(){
        printf("B.f \n");
    }
    B(){
        f();
        a = new A();
        throw 0;
    }
};



int main(){
    try{
        A*a = new B;
        delete a;
    } catch (...){
        printf("Exc \n");
    }
    return 0;
}
/*A.f
B.f
A.f
~A.f
Exc */