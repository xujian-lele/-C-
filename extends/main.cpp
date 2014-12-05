#define NDEBUG
#include <iostream>
#include <Head.h>
#include "Date.h"
#include "assert.h"

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
    assert(a == NULL);
    a->fun();
}

class a{
public:
    a(int n){
        this->value = n;
    }
    int value;
};

int main()
{
    int *temp = new int;
    *temp = 10;
    assert(delete(temp));

    int *array = new int[10];
    assert(delete[](array));

    Date *date = new Date();
    assert(delete(date));

    a *p = new a(30);
    assert(delete(p));

    B b;
    C c;
    Test(&b);
    Test(&c);
    return 0;
}
