//
// Created by matematyk60 on 17.06.17.
//

#include <cstdio>

class A{
public:
    virtual void f(){
        printf("~A.f \n");
    }
    virtual ~A(){f();}
};

class B : public A {
public:
    void f(){
        printf("~B.f\n");
    }
    ~B(){f();
    printf("sss\n");}
};

B b;

int main() {
    A*a= new B();
    printf("M \n");
    delete a;
    return 0;
}
/*M 
~B.f
sss
~A.f 
~B.f
sss
~A.f */