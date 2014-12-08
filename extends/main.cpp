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
void f(int x)
{
    //the value is passed by value
    x = 100;
    cout << "The inputed num of inner function is:" << x << endl;
}

int main()
{
    int a = 10;
    f(a);
    cout << "The inputed num of outer function f is:" << a << endl;
    return 0;
}
