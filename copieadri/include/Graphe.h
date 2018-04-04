#ifndef GRAPHE_H
#define GRAPHE_H
#include <vector>
#include <iostream>
#include "Sommet.h"
#include "Arrete.h"


class Graphe
{
    public:
        Graphe(int ordre,int nbarretes);
        ~Graphe();

        int Getordre() { return m_ordre; }
        void Setordre(int val) { m_ordre = val; }
        int Getnbarretes() {return m_nbarretes;}
        void Setnbarretes (int val) {m_nbarretes=val;}
        std::vector<Sommet> Getsommets() { return m_sommets; }
        void Setsommets(Sommet val) { m_sommets.push_back(val); }
        std::vector<Arrete> Getarretes() { return m_arretes; }
        void Setarretes(Arrete val) { m_arretes.push_back(val); }


    private:
        int m_ordre;
        int m_nbarretes;
        std::vector<Sommet> m_sommets;
        std::vector<Arrete> m_arretes;
};

#endif // GRAPHE_H
