#ifndef GRAPHE_H
#define GRAPHE_H
#include <vector>
#include <iostream>
#include "Sommet.h"
#include "Arrete.h"


class Graphe
{
    public:
        Graphe();
        ~Graphe();

        int Getordre() { return m_ordre; }
        void Setordre(int val) { m_ordre = val; }
        std::string Getnom() { return m_nom; }
        void Setnom(std::string val) { m_nom = val; }
        std::vector<Sommet> Getsommets() { return m_sommets; }
        void Setsommets(std::vector<Sommet> val) { m_sommets = val; }
        std::vector<Arrete> Getarretes() { return m_arretes; }
        void Setarretes(std::vector<Arrete> val) { m_arretes = val; }

    protected:

    private:
        int m_ordre;
        std::string m_nom;
        std::vector<Sommet> m_sommets;
        std::vector<Arrete> m_arretes;
};

#endif // GRAPHE_H
