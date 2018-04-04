#ifndef SOMMET_H
#define SOMMET_H
#include <iostream>

class Sommet
{
    public:
        Sommet();
        ~Sommet();

        int Getdegre() { return m_degre; }
        void Setdegre(int val) { m_degre = val; }
        std::string Getnom() { return m_nom; }
        void Setnom(std::string val) { m_nom = val; }

    private:
        int m_degre;
        std::string m_nom;
};

#endif // SOMMET_H
