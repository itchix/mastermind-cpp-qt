#include "partie.h"

Partie::Partie()
{
}

Partie::Partie(Niveau unNiveau, Joueur* unJoueur):sonNiveau(unNiveau), sonJoueur(unJoueur)
{
    saBoucleMapPion = 0;
    sesLignes = new std::map<int,Couleur>;
    sonResultat = new std::map<int,Couleur>;
    saLigneCompare = new std::map<int,Couleur>;
    sonNombreDeTentative = 0;
    sonScoreTempsSec = 0;
    srand(time(NULL));
}

Partie::~Partie()
{

}

std::map<int,Couleur> * Partie::initPartie()
{
    int sonNombreAleatoire;
    int laPlacePion(0);
    if(sonJoueur->getSonNiveau() == Facile)
    {
        for(int leIt = 0; leIt <= 4 ; leIt++)
        {
            sonNombreAleatoire = rand()%4;
            if(sonNombreAleatoire == 0)
            {
                sonResultat->insert(std::make_pair(laPlacePion,Bleu));
            }
            else if(sonNombreAleatoire == 1)
            {
                sonResultat->insert(std::make_pair(laPlacePion,Rouge));
            }
            else if(sonNombreAleatoire == 2)
            {
                sonResultat->insert(std::make_pair(laPlacePion,Vert));
            }
            else if(sonNombreAleatoire == 3)
            {
                sonResultat->insert(std::make_pair(laPlacePion,Orange));
            }
            laPlacePion++;
        }
    }
    else if(sonJoueur->getSonNiveau() == Moyen)
    {
        for(int leIt = 0; leIt <= 4 ; leIt++)
        {
            sonNombreAleatoire = rand()%6;
            if(sonNombreAleatoire == 0)
            {
                sonResultat->insert(std::make_pair(laPlacePion,Bleu));
            }
            else if(sonNombreAleatoire == 1)
            {
                sonResultat->insert(std::make_pair(laPlacePion,Rouge));
            }
            else if(sonNombreAleatoire == 2)
            {
                sonResultat->insert(std::make_pair(laPlacePion,Vert));
            }
            else if(sonNombreAleatoire == 3)
            {
                sonResultat->insert(std::make_pair(laPlacePion,Orange));
            }
            else if(sonNombreAleatoire == 4)
            {
                sonResultat->insert(std::make_pair(laPlacePion,BleuCiel));
            }
            else if(sonNombreAleatoire == 5)
            {
                sonResultat->insert(std::make_pair(laPlacePion,Marron));
            }
            laPlacePion++;
        }
    }
    else if(sonJoueur->getSonNiveau() == Difficile)
    {
        for(int leIt = 0; leIt <= 4 ; leIt++)
        {
            sonNombreAleatoire = rand()%8;
            if(sonNombreAleatoire == 0)
            {
                sonResultat->insert(std::make_pair(laPlacePion,Bleu));
            }
            else if(sonNombreAleatoire == 1)
            {
                sonResultat->insert(std::make_pair(laPlacePion,Rouge));
            }
            else if(sonNombreAleatoire == 2)
            {
                sonResultat->insert(std::make_pair(laPlacePion,Vert));
            }
            else if(sonNombreAleatoire == 3)
            {
                sonResultat->insert(std::make_pair(laPlacePion,Orange));
            }
            else if(sonNombreAleatoire == 4)
            {
                sonResultat->insert(std::make_pair(laPlacePion,BleuCiel));
            }
            else if(sonNombreAleatoire == 5)
            {
                sonResultat->insert(std::make_pair(laPlacePion,Marron));
            }
            else if(sonNombreAleatoire == 6)
            {
                sonResultat->insert(std::make_pair(laPlacePion,Violet));
            }
            else if(sonNombreAleatoire == 7)
            {
                sonResultat->insert(std::make_pair(laPlacePion,Jaune));
            }
            laPlacePion++;
        }
    }
    return sonResultat;
}

void Partie::triScoresClassement()
{
    std::ifstream leFluxScores("data/scores_tmp.txt");
    std::ofstream leFluxEnregistrement("data/scores.txt");

    std::multimap<double,std::string>* laLigneTxt = new std::multimap<double,std::string>();

    double leScoreTmp;
    std::string leNomTmp;
    char leCharSupprimerTmp;

    while(!leFluxScores.eof())
    {
        leFluxScores >> leScoreTmp;
        leFluxScores >> leCharSupprimerTmp;
        leFluxScores >> leNomTmp;
        leFluxScores.ignore();
        laLigneTxt->insert(std::make_pair(leScoreTmp,leNomTmp));
    }
    leFluxScores.close();

    std::map<double,std::string>::reverse_iterator it;
    for(it = laLigneTxt->rbegin(); it != laLigneTxt->rend(); it++)
    {
        leFluxEnregistrement << '\n' << it->first << ':' << it->second;
    }
    leFluxEnregistrement.close();
}

void Partie::ajoutLignePion(Couleur uneCouleur)
{
    sesLignes->insert(std::make_pair(saBoucleMapPion,uneCouleur));
    saBoucleMapPion++;
}

void Partie::eraseLignePion()
{
    std::map<int,Couleur>::iterator leIt;

    for(leIt = sesLignes->begin(); leIt != sesLignes->end();leIt++)
    {
        sesLignes->erase(leIt);
    }

    saBoucleMapPion = 0;

}

void Partie::eraseLigneCompare()
{
    std::map<int,Couleur>::iterator leIt;

    for(leIt = saLigneCompare->begin(); leIt != saLigneCompare->end();leIt++)
    {
        saLigneCompare->erase(leIt);
    }
}

std::map<int,Couleur> * Partie::comparerResultat()
{
    std::map<int,Couleur>::iterator leItRes;
    std::map<int,Couleur>::iterator leItCompare;

    int laBoucle(0);
    int laVerifPionNoirBlanc (0);

    for(leItCompare = sesLignes->begin(); leItCompare != sesLignes->end(); leItCompare++)
    {
        for(leItRes = sonResultat->begin(); leItRes != sonResultat->end(); leItRes++)
        {
            if(leItRes->first == leItCompare->first && leItRes->second == leItCompare->second)
            {
                saLigneCompare->insert(std::make_pair(laBoucle, Noir));
                laBoucle++;
                break;
            }

            else if(leItRes->first > leItCompare->first && leItCompare->second == leItRes->second)
            {
                saLigneCompare->insert(std::make_pair(laBoucle, Blanc));
                laBoucle++;
                break;

            } ///Probleme*/
        }

        if(laVerifPionNoirBlanc == laBoucle)
        {
            saLigneCompare->insert(std::make_pair(laBoucle, Rien));
            laBoucle++;
        }

        laVerifPionNoirBlanc++;
    }
    sonNombreDeTentative++;

    return saLigneCompare;
}

void Partie::recupererTempsSec()
{
    sonScoreTempsSec++;
}

void Partie::ajoutScoreNom()
{
    std::ofstream leFluxScoresTmp("data/scores_tmp.txt", std::ios::app);

    double leScoreTmp;

    //////////////Calcule du Score/////////////
    if(sonJoueur->getSonNiveau() == Facile)
    {
        leScoreTmp = (1000/(sonNombreDeTentative+sonScoreTempsSec))*40;
    }
    else if(sonJoueur->getSonNiveau() == Moyen)
    {
        leScoreTmp = (1000/(sonNombreDeTentative+sonScoreTempsSec))*60;
    }
    else if(sonJoueur->getSonNiveau() == Difficile)
    {
        leScoreTmp = (1000/(sonNombreDeTentative+sonScoreTempsSec))*80;
    }
    ///////////////////////////////////////////

    leFluxScoresTmp << '\n';
    leFluxScoresTmp << leScoreTmp;
    leFluxScoresTmp << ':';
    leFluxScoresTmp << sonJoueur->getSonNom();

    leFluxScoresTmp.close();
}
