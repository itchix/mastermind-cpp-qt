#include "aproposwindow.h"

AproposWindow::AproposWindow(QWidget *parent) : QDialog(parent)
{
    sonBoutonMenu = new QPushButton("Retour");
    sonTexte = new QLabel("Bienvenue dans le célèbre jeu du Mastermind\nCe jeu a été développé Par Félix Marchenay & Scriven Scot\nCe jeu a été conçue au département Informatique de l'IUT de La Rochelle\nBeta testeur : M.Migault, J.Vanbuis, M.Reneaume...\n Merci à tous!!!");
    sonTexte->setAlignment(Qt::AlignCenter);


    sonVBox = new QVBoxLayout(this);
    sonVBox->addWidget(sonTexte);
    sonVBox->addWidget(sonBoutonMenu);
    setLayout(sonVBox);

    setWindowTitle("Master-Mind : A propos");
    setGeometry(425,290,400,200);
    setFixedSize(QSize(400,200));

    QWidget::connect(sonBoutonMenu, SIGNAL(clicked()), this, SLOT(retourMenu()));
}

AproposWindow::~AproposWindow()
{

}

void AproposWindow::retourMenu()
{
    parentWidget()->show();
    this->close();
}
