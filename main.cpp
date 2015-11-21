#include <QtGui/QApplication>
#include "menuwindow.h"
#include "partie.h"

///////////////////////////////////////////////////////////////////////////////////////
/////////////////////Le jeu marche via Qt mais ne marche pas en stand alone////////////
///////////////////////////////////////////////////////////////////////////////////////
/////////////////////Codé et designé par Marchenay.F & Scriven.S///////////////////////
///////////////////////////////////////////////////////////////////////////////////////



////Bug pour affichage ligne resultat/// dans partieWindow.cpp
////Finir l'algo comparaison quand pas a la bonne place/// dans partie.cpp
////Bug lorsque affichage fenetre de la partie, le jeu ne s'affiche pas dans la barre windows///

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MenuWindow w;
    w.show();
    srand(time(NULL));
    
    return a.exec();
}
