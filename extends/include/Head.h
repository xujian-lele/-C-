#ifndef HEAD_H
#define HEAD_H
#include "Eye.h"
#include "Nose.h"

class Head
{
    public:
        Head();
        virtual ~Head();
        void look();
        void smell();
    protected:
    private:
        Eye eye;
        Nose nose;
};

#endif // HEAD_H
