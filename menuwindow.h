#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGui>
#include "niveauwindow.h"
#include "classementwindow.h"
#include "aproposwindow.h"

class MenuWindow : public QWidget
{
    Q_OBJECT
private:
    QPushButton* sonBoutonJouer;
    QPushButton* sonBoutonClassement;
    QPushButton* sonBoutonQuitter;
    QPushButton* sonBoutonApropos;
    QVBoxLayout* sonMenuBox;

public:
    MenuWindow();
    ~MenuWindow();

public slots:
        void lancerPartie();
        void afficherClassement();
        void afficherApropos();
};

#endif // WIDGET_H
