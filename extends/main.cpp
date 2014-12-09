#define NDEBUG
#include <iostream>
#include <Head.h>
#include "Date.h"
#include "assert.h"

using namespace std;
//定义类型名
typedef unsigned int UNINT;
//定义结构体，公用体，枚举类型的公用名
typedef struct Node
{
    int a;
    int b;
};
//定义数组
//int a[10]
typedef int INT_ARRAY_10[10] ;
typedef int INT_ARRAY_20[20] ;
//定义指针
typedef char * STRING;
typedef int (*myfun) (int a,int b);
int Max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    myfun FUN;
    FUN = Max;
    cout << FUN(1,2) <<endl;

    STRING a = "i love C++";
    cout << a << endl;

    UNINT A;
    A = 10;
    cout << A << endl;

    INT_ARRAY_10 B;
    for(int i=0;i<10;i++){
        B[i] = i;
    }

    for(int i=0;i<10;i++){
       cout << B[i] << endl;
    }

    char *p1,*p2;
    p1 = "I am p1";
    p2 = "I am p2";

    char* p3,p4;
    p3 = "I am p3";
    p4 = 'c';

    STRING p5,p6;
    p5 = "I am p5";
    p6 = "I am p6";


    return 0;
}
