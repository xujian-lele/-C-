#define NDEBUG
#include <iostream>
#include <Head.h>
#include "Date.h"
#include "assert.h"

using namespace std;
class Father
{
public:
    string testPublic()
    {
        return "This is testPublic";
    };
    int p1;
protected:
    string testProtected()
    {
        return "This is testProtect";
    };
    int p2;
private:
    string testPrivate()
    {
        return "This is testPrivate";
    }
    int p3;
};

class publicChild : public Father
{
public:
    string test()
    {
        return testPublic()+" in public child's public";
    };
protected:
    string test1()
    {
        return testProtected() + " in public child's protected";
    };
private:
    string test2()
    {
        return " This is in public child's private";
    }

};

int f(int x = 42);
int f(int x)
{
    cout << "The inputed num is:" << x << endl;
    return x;
}
int g(int& a)
{
    cout << "The num is:" << a << endl;
    return a;
}
int m(const int& a)
{
    cout << "The num is:" << a << endl;
    a = 10; // if the object is const type,then the object can not be changed
    return a;
}




int main()
{
    int a = 10;
    g(a);
    f(a);
    return 0;
}
