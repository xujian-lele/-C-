#include "Head.h"

Head::Head()
{
    //ctor
}

Head::~Head()
{
    //dtor
}

void Head::look()
{
    eye.look();
}

void Head::smell()
{
    nose.smell();
}
