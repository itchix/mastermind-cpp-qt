#ifndef NIVEAUWINDOW_H
#define NIVEAUWINDOW_H

#include <QWidget>
#include <QtGui>
#include "partiewindow.h"
#include "joueur.h"

class NiveauWindow : public QDialog
{
    Q_OBJECT

private:
    QPushButton * sonBoutonMenu;
    QPushButton * sonBoutonValider;
    QRadioButton * sonNiveauFacile;
    QRadioButton * sonNiveauMoyen;
    QRadioButton * sonNiveauDifficile;
    QLineEdit * sonNomAjout;
    Joueur * sonJoueur;

public:
    NiveauWindow(QWidget *parent = 0);
    ~NiveauWindow();
    
signals:
    
public slots:
    void retourMenu();
    void lancerPartie();
};

#endif // NIVEAUWINDOW_H
