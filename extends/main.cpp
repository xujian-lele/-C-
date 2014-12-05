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
    a(){};
    a(int n){
        this->value = n;
    }
    int value;
};
//值传递
void swap1(int x, int y){
    int temp;
    temp = x;
    x = y;
    y = temp;
    cout << x <<"  "<< y <<endl;
}
//地址传递
void swap2(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    cout << *x <<"  "<< *y <<endl;
}
//引用传递
void swap3(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
    cout << x << "  " << y << endl;
}

int main()
{

    int a = 6;
    int* v1 = &a;
    int b = 8;
    int *v2 = NULL;
    v2 = &b;
    //*v2 = 8;
    cout << v1 << " " << v2 << endl;
    cout << *v1 << " " << *v2 << endl;
    //swap1(*v1, *v2);
    //swap2(v1,v2);
    //swap2(&v1, &v2);
    swap3(*v1, *v2);
    cout << v1 << " " << v2 << endl;
    cout << *v1 << " " << *v2 << endl;
    int bb = 0123;
    cout << bb << endl;
    int cc = 0x123;
    cout << cc << endl;
    int dd = 123;
    cout << dd << endl;
    string input;
    getline(cin,input);
    cout << "U had input:" << endl;
    cout << input << endl;
    return 0;
}
