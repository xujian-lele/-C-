#include <iostream>
#include "Date.h"


Date::Date()
{
    year = 2012;
    month = 12;
    day = 30;
    //ctor
}

Date::Date(int year,int month,int day)
{
    year = year;
    month = month;
    day = day;
}

void Date::showDay(int day)
{
    cout << day << endl;
}

Date::~Date()
{
    //dtor
}
