#ifndef PARTIE_H
#define PARTIE_H
#include <iostream>
#include "joueur.h"
#include <vector>
#include <map>
#include "Niveau.h"
#include <fstream>
#include "Couleur.h"
#include <QDebug>
#include "time.h"

class Partie
{
private:
    double sonTimer;
    Niveau sonNiveau;
    Joueur* sonJoueur;
    std::map<int,Couleur> * sesLignes;
    std::map<int,Couleur> * sonResultat;
    std::map<int,Couleur> * saLigneCompare;
    int saBoucleMapPion;
    int sonNombreDeTentative;
    int sonScoreTempsSec;

public:
    Partie();
    Partie(Niveau, Joueur*);
    ~Partie();
    std::map<int,Couleur> *initPartie();
    void triScoresClassement();
    void ajoutLignePion(Couleur);
    void eraseLignePion();
    void eraseLigneCompare();
    std::map<int,Couleur> * comparerResultat();
    void ajoutScoreNom();
    void recupererTempsSec();
};

#endif // PARTIE_H
