#include "classementwindow.h"

ClassementWindow::ClassementWindow(QWidget *parent) :
    QDialog(parent)
{
    //////////////////CONFIG TABLEAU///////////////////////////
    ///////////////////////////////////////////////////////////

    QStringList labels;
    labels << tr("Nom") << tr("Score");

    sonTableauClassement= new QTableWidget(20,2);
    sonTableauClassement->setEditTriggers(QAbstractItemView::NoEditTriggers);
    sonTableauClassement->setHorizontalHeaderLabels(labels);
    sonTableauClassement->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    sonTableauClassement->setShowGrid(false);
    sonTableauClassement->verticalHeader()->setResizeMode(QHeaderView::Stretch);

    /////////////////////REMPLIR TABLEAU///////////////////////
    ///////////////////////////////////////////////////////////

    std::ifstream leFluxScores("data/scores.txt");

    double leScore;
    std::string leNom;
    char leCharSupprimer;
    int leI(0);

    while(!leFluxScores.eof())
    {
        leFluxScores >> leScore;
        leFluxScores >> leCharSupprimer;
        leFluxScores >> leNom;
        leFluxScores.ignore();

        QString leQScore = QString::number(leScore);
        QString leQNom = QString(leNom.c_str());

        sonTableauClassement->setItem(leI,0,new QTableWidgetItem(leQNom));
        sonTableauClassement->setItem(leI,1,new QTableWidgetItem(leQScore));
        leI++;
    }

    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////

    sonBoutonMenu = new QPushButton("&Retour Menu");
    sonBoxClassement = new QVBoxLayout();
    sonBoxClassement->addWidget(sonTableauClassement);
    sonBoxClassement->addWidget(sonBoutonMenu);

    this->setLayout(sonBoxClassement);

    setWindowTitle("Master-Mind : Classement");
    setGeometry(350,75,550,590);
    setFixedSize(QSize(550,590));

    QWidget::connect(sonBoutonMenu, SIGNAL(clicked()), this, SLOT(retourMenu()));
}

ClassementWindow::~ClassementWindow()
{

}

void ClassementWindow::retourMenu()
{
    parentWidget()->show();
    this->close();
}
