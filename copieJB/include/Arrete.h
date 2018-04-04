#ifndef ARRETE_H
#define ARRETE_H
#include "Sommet.h"


class Arrete
{
    public:
        Arrete( int s1, int s2);
        ~Arrete();


    private:
         int m_s1;
         int m_s2;
};

#endif // ARRETE_H
