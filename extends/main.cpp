#include<iostream>
using namespace std;

class Base
{
public:
    virtual void f(float x)
    {
        cout<<"Base::f(float)"<< x <<endl;
    }
    void g(float x)
    {
        cout<<"Base::g(float)"<< x <<endl;
    }
    void h(float x)
    {
        cout<<"Base::h(float)"<< x <<endl;
    }
};
class Derived : public Base
{
public:
    virtual void f(float x)
    {
        cout<<"Derived::f(float)"<< x <<endl;   //¶àÌ¬¡¢¸²¸Ç
    }
    void g(int x)
    {
        cout<<"Derived::g(int)"<< x <<endl;     //Òþ²Ø
    }
    void h(float x)
    {
        cout<<"Derived::h(float)"<< x <<endl;   //Òþ²Ø
    }
};
int main(void)
{
    Derived d;
    Base *pb = &d;
    Derived *pd = &d;
    // Good : behavior depends solely on type of the object
    pb->f(3.14f);   // Derived::f(float) 3.14
    pd->f(3.14f);   // Derived::f(float) 3.14

    // Bad : behavior depends on type of the pointer
    pb->g(3.14f);   // Base::g(float)  3.14
    pd->g(3.14f);   // Derived::g(int) 3

    // Bad : behavior depends on type of the pointer
    pb->h(3.14f);   // Base::h(float) 3.14
    pd->h(3.14f);   // Derived::h(float) 3.14

    Base e;
    Base *p = &e;
    Derived *q = (Derived *)&e;
    //Good :
    p->f(0.000001f);    //Base::f(float) 0.00000001
    q->f(0.000001f);    //Base::f(float) 0.00000001

    p->g(0.000001f);    //Base::f(float) 0.00000001
    q->g(0.000001f);    //Derived::f(float) 0.00000001

    p->h(0.000001f);    //Base::h(float) 0.000001f
    q->h(0.000001f);    //Base::h(float) 0.000001f
    return 0;
}
