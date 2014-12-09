#include<iostream>
#include "stdio.h"
using namespace std;

class A
{
public:
    void foo()
    {
        printf("1\n");
    }
    virtual void fun()
    {
        printf("2\n");
    }
};
class B : public A
{
public:
    void foo()
    {
        printf("3\n");
    }
    void fun()
    {
        printf("4\n");
    }
};
int main(void)
{
    A a;
    B b;
    A *p = &a;
    p->foo();
    p->fun();
    p = &b;
    p->foo();
    p->fun();
    B *pb = &b;
    pb->foo();
    pb->fun();
    B *q = (B *)&a;
    q->foo();
    q->fun();
    return 0;
}
