#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
    public:
        int year;
        int month;
        int day;
        Date();
        Date(int,int,int);
        int Year();
        int getMonth();
        void showDay(int);
        virtual ~Date();

    protected:
    private:

};

#endif // DATE_H
