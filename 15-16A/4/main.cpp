//
// Created by matematyk60 on 18.06.17.
//

#include <cstdio>

class A {
    int i;
public:
    A(int _i = 0) : i(_i){
        printf("A%d\n",i);
    }
    ~A(){
        printf("~A%d\n",i);
    }
};

class B : public A{
    int x;
    A a;
public:
    B(int _x ):A(1),x(_x){};
    ~B(){
        printf("~B %d\n",x);
    }
};

B b(5);

int main(){
    A*ptr = new B(3);
    delete ptr;
    return 0;
}

/*A1
A0
A1
A0
~A1
~B 5
~A0
~A1*/