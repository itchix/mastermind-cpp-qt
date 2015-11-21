#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include "niveau.h"

class Joueur
{
private:
    std::string sonNom;
    double sonScore;
    int sonClassement;
    Niveau sonNiveau;

public:
    Joueur();
    Joueur(std::string, Niveau);
    ~Joueur();
    std::string getSonNom();
    double getSonScore();
    Niveau getSonNiveau();
    int getSonClassement();
    void setSonNom(std::string);

};

#endif // JOUEUR_H
