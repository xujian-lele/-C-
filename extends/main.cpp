#include "iostream"
#include "pthread.h"
#include "vector"
#include "algorithm"

using namespace std;

int main(void)
{
    vector<int> vec;
    vec.reserve(20);
    int i = 0 ;
    while(i <= 10)
    {
        vec.push_back(i);
        i++;
    }

    cout << "vector's size : " << vec.size() << endl;//11
    remove(vec.begin(),vec.end(),0);
    cout << vec.size() << endl;//11,remove前后size没变，那么remove到底是啥意思？

    cout << "vector's size : " << vec.size() << endl;
    cout << "vector's capacity : " << vec.capacity() << endl;
    cout << "vector's max_size : " << vec.max_size() << endl;

    cout << "vector's front : " << vec.front() << endl;
    cout << "vector's back : " << vec.back() << endl;

    vector<int>::iterator itr = vec.begin();
    while(true)
    {
        if(*itr == 1)
        {
           vec.erase(itr);
           break;
        }
        itr++;
    }

    cout << "vector's size : " << vec.size() << endl;
    cout << "vector's front : " << vec.front() << endl;
    swap(vec[0],vec[1]);
    cout << "vector's front : " << vec.front() << endl;
}
