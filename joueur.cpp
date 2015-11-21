#include "joueur.h"

Joueur::Joueur()
{

}

Joueur::Joueur(std::string unNom, Niveau unNiveau):sonNom(unNom), sonNiveau(unNiveau)
{

}

Joueur::~Joueur()
{

}
std::string Joueur::getSonNom()
{
    return sonNom;
}

Niveau Joueur::getSonNiveau()
{
    return sonNiveau;
}

double Joueur::getSonScore()
{
    return sonScore;
}

int Joueur::getSonClassement()
{
    return sonClassement;
}

void Joueur::setSonNom(std::string unNom)
{
    sonNom = unNom;
}
