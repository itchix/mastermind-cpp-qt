#ifndef PARTIEWINDOW_H
#define PARTIEWINDOW_H

#include <QWidget>
#include <QtGui>
#include "niveau.h"
#include "joueur.h"
#include "partie.h"

class PartieWindow : public QWidget
{
    Q_OBJECT
private:
    QPushButton * sonBoutonMenu;
    Joueur* sonJoueur;
    QLineEdit * sonNom;
    QLCDNumber * sonChrono;
    QTime * sonTimeValue;
    QPushButton * sonBoutonBleu;
    QPushButton * sonBoutonRouge;
    QPushButton * sonBoutonVert;
    QPushButton * sonBoutonOrange;
    QPushButton * sonBoutonMarron;
    QPushButton * sonBoutonViolet;
    QPushButton * sonBoutonBleuCiel;
    QPushButton * sonBoutonJaune;
    QPushButton * sonBoutonVerif;
    QPushButton * sonBoutonAnnuler;
    QTableWidget * sonTableauInsert;
    QTableWidget * sonTableauResFinal;
    QTableWidget * sonTableauCompare;
    Couleur saCouleurPion;
    Partie * saPartie;
    std::map<int,Couleur> * saMapRes;
    int sonIndexColonne;
    int sonIndexLigne;
    int sonIndexColonneCompare;
    int sonIndexLigneCompare;
public:
    PartieWindow(Joueur*,QWidget *parent = 0);
    ~PartieWindow();
    
signals:
    
public slots:
    void retourMenu();
    void chronometre();
    void ajoutTableau();
    void compareTableau();
    void recupPionResultat();
    void deleteLigne();
};

#endif // PARTIEWINDOW_H
