#ifndef SOMMET_H
#define SOMMET_H
#include <iostream>

class Sommet
{
    public:
        Sommet( int num, int nb);
        ~Sommet();

        int Getnum() { return m_num; }
        void Setnum(int val) { m_num = val; }
        int Getnb() { return m_nb; }
        void Setnb(int val) { m_nb = val; }

    private:
        int m_num;
        int m_nb;
};

#endif // SOMMET_H
