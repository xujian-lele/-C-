#include <iostream>
#include <Head.h>
#include "Date.h"


using namespace std;

int main()
{
    Head head;
    head.look();
    head.smell();
    Date date;
    date.showDay(date.day);
    return 0;
}
