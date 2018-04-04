#ifndef ARRETE_H
#define ARRETE_H
#include "Sommet.h"


class Arrete
{
    public:
        Arrete();
        ~Arrete();

         int GetPoids() { return m_poids; }
        void SetPoids( int val) { m_poids = val; }

    private:
         int m_poids;
         Sommet m_s1;
         Sommet m_s2;
};

#endif // ARRETE_H
