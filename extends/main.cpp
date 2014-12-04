#include <iostream>
#include <Head.h>
#include "Date.h"


using namespace std;

class A{
public:
    virtual void fun()= 0;
};

class B : public A
{
    public:
    virtual void fun(){
        cout << "This is B::fun()" << endl;
    }
};

class C : public A
{
public:
        virtual void fun(){
        cout << "This is C::fun()" << endl;
    }
};


void Test(A *a)
{
    a->fun();
}

int main()
{
    B b;
    C c;
    Test(&b);
    Test(&c);
    return 0;
}
