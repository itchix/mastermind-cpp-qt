#include "niveauwindow.h"

NiveauWindow::NiveauWindow(QWidget *parent) : QDialog(parent)
{
    sonBoutonMenu = new QPushButton("Retour", this);
    sonBoutonValider = new QPushButton("Valider", this);
    sonNiveauFacile = new QRadioButton("Facile (4 couleurs)", this);
    sonNiveauFacile->setChecked(true);
    sonNiveauMoyen = new QRadioButton("Moyen (6 couleurs)", this);
    sonNiveauDifficile = new QRadioButton("Difficile (8 couleurs)", this);
    sonNomAjout = new QLineEdit(this);
    QLabel *leTextNom = new QLabel("Ajouter un nom :",this);

    leTextNom->setGeometry(20,25,85,30);
    sonNomAjout->setGeometry(110,25,130,30);
    sonNiveauFacile->setGeometry(75,75,150,30);
    sonNiveauMoyen->setGeometry(75,100,150,30);
    sonNiveauDifficile->setGeometry(75,125,150,30);
    sonBoutonMenu->setGeometry(25,175,100,50);
    sonBoutonValider->setGeometry(125,175,100,50);

    sonBoutonMenu->setCursor(Qt::PointingHandCursor);
    sonBoutonValider->setCursor(Qt::PointingHandCursor);
    sonBoutonValider->setDefault(true);

    setWindowTitle("Master-Mind : Choix niveau");
    setGeometry(500,250,250,250);
    setFixedSize(QSize(250,250));

    QWidget::connect(sonBoutonMenu, SIGNAL(clicked()), this, SLOT(retourMenu()));
    QWidget::connect(sonBoutonValider, SIGNAL(clicked()), this, SLOT(lancerPartie()));

}

NiveauWindow::~NiveauWindow()
{

}

void NiveauWindow::retourMenu()
{
    parentWidget()->show();
    this->close();
}

void NiveauWindow::lancerPartie(/*Mettre parametre du choix niveau et nom*/)
{
    if(sonNomAjout->text().isEmpty())
    {
        QMessageBox::critical(this, "Attention", "Ajouter un nom");
        return;
    }

    if((sonNomAjout->text().contains(':',Qt::CaseSensitive)) || (sonNomAjout->text().contains(' ',Qt::CaseSensitive)))
    {
        QMessageBox::critical(this, "Attention", "Ne pas mettre d'espace et/ou de ':'");
        return;
    }



    if (sonNiveauFacile->isChecked())
    {
        sonJoueur = new Joueur(sonNomAjout->text().toStdString(),Facile);
    }
    if (sonNiveauMoyen->isChecked())
    {
        sonJoueur = new Joueur(sonNomAjout->text().toStdString(),Moyen);
    }
    if (sonNiveauDifficile->isChecked())
    {
        sonJoueur = new Joueur(sonNomAjout->text().toStdString(),Difficile);
    }

    PartieWindow * laFenetrePartie = new PartieWindow(sonJoueur,this);
    laFenetrePartie->setWindowFlags(Qt::Window);
    laFenetrePartie->setWindowModality(Qt::WindowModal);
    laFenetrePartie->show();
    parentWidget()->hide();
    this->hide();

}
