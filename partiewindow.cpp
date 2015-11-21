#include "partiewindow.h"

PartieWindow::PartieWindow(Joueur* unJoueur,QWidget *parent) :
    sonJoueur(unJoueur),QWidget(parent)
{
    sonIndexColonne = 0;
    sonIndexLigne = 0;
    sonIndexColonneCompare = 0;
    sonIndexLigneCompare = 0;
    saPartie = new Partie(sonJoueur->getSonNiveau(),sonJoueur);
    saMapRes = new std::map<int,Couleur>;
    saPartie->initPartie();

    std::map<int,Couleur>::iterator leIt;
    int laPosCouleur(0);

    for(leIt = (saPartie->initPartie())->begin(); leIt != (saPartie->initPartie())->end(); leIt++)
    {
        saMapRes->insert(std::make_pair(laPosCouleur, leIt->second));
        laPosCouleur++;
    }

    QString leQNom = QString::fromStdString(sonJoueur->getSonNom());
    sonBoutonMenu = new QPushButton("Menu", this);
    sonBoutonMenu->setGeometry(10,10,100,40);
    sonNom = new QLineEdit(leQNom, this);
    sonNom->setGeometry(450,10,120,40);
    sonNom->setReadOnly(true);
    sonNom->setAlignment(Qt::AlignCenter);
    sonNom->setFont(QFont("Times", 18, QFont::Black));

    sonBoutonVerif = new QPushButton("Vérifier",this);
    sonBoutonVerif->setGeometry(10,100,100,40);
    sonBoutonVerif->hide();

    sonBoutonAnnuler = new QPushButton("Annuler ligne", this);
    sonBoutonAnnuler->setGeometry(10,160,100,40);

    /////////////Chronometre///////////////
    QTimer *unChrono = new QTimer(this);
    sonTimeValue = new QTime(0,0);
    sonChrono = new QLCDNumber(this);
    sonChrono->setGeometry(450,620,120,50);
    sonChrono->setPalette(Qt::black);
    unChrono->start(1000); // en ms
    ///////////////////////////////////////

    /////////////Pion//////////////////////
    sonBoutonBleu = new QPushButton(this);
    sonBoutonBleu->setIcon(QIcon("data/bleuf.png"));
    sonBoutonBleu->setIconSize(QSize(40,40));
    sonBoutonBleu->setStyleSheet("border:none");
    sonBoutonBleu->setGeometry(200,10,40,40);
    sonBoutonBleu->setCursor(Qt::PointingHandCursor);

    sonBoutonRouge = new QPushButton(this);
    sonBoutonRouge->setIcon(QIcon("data/rouge.png"));
    sonBoutonRouge->setIconSize(QSize(40,40));
    sonBoutonRouge->setStyleSheet("border:none");
    sonBoutonRouge->setGeometry(240,10,40,40);
    sonBoutonRouge->setCursor(Qt::PointingHandCursor);

    sonBoutonVert = new QPushButton(this);
    sonBoutonVert->setIcon(QIcon("data/vert1.png"));
    sonBoutonVert->setIconSize(QSize(40,40));
    sonBoutonVert->setStyleSheet("border:none");
    sonBoutonVert->setGeometry(280,10,40,40);
    sonBoutonVert->setCursor(Qt::PointingHandCursor);

    sonBoutonOrange = new QPushButton(this);
    sonBoutonOrange->setIcon(QIcon("data/orange.png"));
    sonBoutonOrange->setIconSize(QSize(40,40));
    sonBoutonOrange->setStyleSheet("border:none");
    sonBoutonOrange->setGeometry(320,10,40,40);
    sonBoutonOrange->setCursor(Qt::PointingHandCursor);

    QWidget::connect(sonBoutonBleu, SIGNAL(clicked()), this, SLOT(ajoutTableau()));
    QWidget::connect(sonBoutonOrange, SIGNAL(clicked()), this, SLOT(ajoutTableau()));
    QWidget::connect(sonBoutonRouge, SIGNAL(clicked()), this, SLOT(ajoutTableau()));
    QWidget::connect(sonBoutonVert, SIGNAL(clicked()), this, SLOT(ajoutTableau()));

    if(sonJoueur->getSonNiveau() == Difficile || sonJoueur->getSonNiveau() == Moyen)
    {
        sonBoutonBleuCiel = new QPushButton(this);
        sonBoutonBleuCiel->setIcon(QIcon("data/bleuc.png"));
        sonBoutonBleuCiel->setIconSize(QSize(40,40));
        sonBoutonBleuCiel->setStyleSheet("border:none");
        sonBoutonBleuCiel->setGeometry(200,50,40,40);
        sonBoutonBleuCiel->setCursor(Qt::PointingHandCursor);

        sonBoutonMarron = new QPushButton(this);
        sonBoutonMarron->setIcon(QIcon("data/noir.png"));
        sonBoutonMarron->setIconSize(QSize(40,40));
        sonBoutonMarron->setStyleSheet("border:none");
        sonBoutonMarron->setGeometry(240,50,40,40);
        sonBoutonMarron->setCursor(Qt::PointingHandCursor);

        QWidget::connect(sonBoutonMarron, SIGNAL(clicked()), this, SLOT(ajoutTableau()));
        QWidget::connect(sonBoutonBleuCiel, SIGNAL(clicked()), this, SLOT(ajoutTableau()));

        if(sonJoueur->getSonNiveau() == Difficile)
        {
            sonBoutonViolet = new QPushButton(this);
            sonBoutonViolet->setIcon(QIcon("data/rose.png"));
            sonBoutonViolet->setIconSize(QSize(40,40));
            sonBoutonViolet->setStyleSheet("border:none");
            sonBoutonViolet->setGeometry(280,50,40,40);
            sonBoutonViolet->setCursor(Qt::PointingHandCursor);

            sonBoutonJaune = new QPushButton(this);
            sonBoutonJaune->setIcon(QIcon("data/jaune.png"));
            sonBoutonJaune->setIconSize(QSize(40,40));
            sonBoutonJaune->setStyleSheet("border:none");
            sonBoutonJaune->setGeometry(320,50,40,40);
            sonBoutonJaune->setCursor(Qt::PointingHandCursor);

            QWidget::connect(sonBoutonViolet, SIGNAL(clicked()), this, SLOT(ajoutTableau()));
            QWidget::connect(sonBoutonJaune, SIGNAL(clicked()), this, SLOT(ajoutTableau()));

        }
    }

    ///////////////////Tableau insertion//////////////////////

    sonTableauInsert = new QTableWidget(10,4,this);
    sonTableauInsert->setEditTriggers(QAbstractItemView::NoEditTriggers);
    sonTableauInsert->setSelectionMode(QAbstractItemView::NoSelection);
    sonTableauInsert->setFocusPolicy(Qt::NoFocus);
    sonTableauInsert->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    sonTableauInsert->setShowGrid(false);
    sonTableauInsert->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    sonTableauInsert->setGeometry(150,100,250,500);
    sonTableauInsert->horizontalHeader()->hide();
    sonTableauInsert->verticalHeader()->hide();
    sonTableauInsert->setIconSize(QSize(50,50));

    //////////////////////////////////////////////////////
    ////////////////Tableau comparaison///////////////////

    sonTableauCompare = new QTableWidget(10,4,this);
    sonTableauCompare->setEditTriggers(QAbstractItemView::NoEditTriggers);
    sonTableauCompare->setSelectionMode(QAbstractItemView::NoSelection);
    sonTableauCompare->setFocusPolicy(Qt::NoFocus);
    sonTableauCompare->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    sonTableauCompare->setShowGrid(false);
    sonTableauCompare->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    sonTableauCompare->setGeometry(450,100,120,500);
    sonTableauCompare->horizontalHeader()->hide();
    sonTableauCompare->verticalHeader()->hide();
    sonTableauCompare->setIconSize(QSize(20,20));

    /////////////////////////////////////////////////////
    ////////////////Tableau résultat///////////////////

    sonTableauResFinal = new QTableWidget(1,4,this);
    sonTableauResFinal->setEditTriggers(QAbstractItemView::NoEditTriggers);
    sonTableauResFinal->setSelectionMode(QAbstractItemView::NoSelection);
    sonTableauResFinal->setFocusPolicy(Qt::NoFocus);
    sonTableauResFinal->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    sonTableauResFinal->setShowGrid(false);
    sonTableauResFinal->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    sonTableauResFinal->setGeometry(150,620,250,50);
    sonTableauResFinal->horizontalHeader()->hide();
    sonTableauResFinal->verticalHeader()->hide();
    sonTableauResFinal->setIconSize(QSize(50,50));

    /////////////////////////////////////////////////////

    setGeometry(300,0,650,700);
    setFixedSize(650,700);

    QWidget::connect(sonBoutonAnnuler, SIGNAL(clicked()), this, SLOT(deleteLigne()));
    QWidget::connect(unChrono, SIGNAL(timeout()), this, SLOT(chronometre()));
    QWidget::connect(sonBoutonMenu, SIGNAL(clicked()), this, SLOT(retourMenu()));
    QWidget::connect(sonBoutonVerif, SIGNAL(clicked()), this, SLOT(compareTableau()));

}

PartieWindow::~PartieWindow()
{

}

void PartieWindow::chronometre()
{
    sonTimeValue->setHMS(0,sonTimeValue->addSecs(1).minute(),sonTimeValue->addSecs(1).second());
    sonChrono->display(sonTimeValue->toString());
    saPartie->recupererTempsSec();
}

void PartieWindow::retourMenu()
{
    int rep = QMessageBox::question(this,"Quitter/Continuer", "Etes vous sure de vouloir quitter?", QMessageBox::Ok, QMessageBox::Cancel);
    if(rep == QMessageBox::Ok)
    {
        this->close();
        (parentWidget()->parentWidget())->show();
    }
    else if (rep == QMessageBox::Cancel )
    {
       return;
    }
}

void PartieWindow::ajoutTableau()
{
    ///////////////////Condition vérification ligne avant de passer à une autre///////////////////
    if(sonIndexColonne >= 3)
    {
        sonBoutonVerif->show();
    }
    else
    {
        sonBoutonVerif->hide();
    }

    if(sonIndexColonne >= 4)
    {
        QMessageBox::critical(this, "Attention", "Veuillez vérifier avant de continuer");
        return;
    }

    ///////////////////Ajout dans tableau/////////////////
    //////////////////////////////////////////////////////

    if(sender() == sonBoutonBleu)
    {
        sonTableauInsert->setItem(sonIndexLigne, sonIndexColonne, new QTableWidgetItem(QIcon("data/bleuf.png"), ""));
        saPartie->ajoutLignePion(Bleu);
    }

    else if(sender() == sonBoutonRouge)
    {
        sonTableauInsert->setItem(sonIndexLigne, sonIndexColonne, new QTableWidgetItem(QIcon("data/rouge.png"), ""));
        saPartie->ajoutLignePion(Rouge);
    }

    else if(sender() == sonBoutonVert)
    {
        sonTableauInsert->setItem(sonIndexLigne, sonIndexColonne, new QTableWidgetItem(QIcon("data/vert1.png"), ""));
        saPartie->ajoutLignePion(Vert);
    }

    else if(sender() == sonBoutonOrange)
    {
        sonTableauInsert->setItem(sonIndexLigne, sonIndexColonne, new QTableWidgetItem(QIcon("data/orange.png"), ""));
        saPartie->ajoutLignePion(Orange);
    }

    else if(sender() == sonBoutonBleuCiel)
    {
        sonTableauInsert->setItem(sonIndexLigne, sonIndexColonne, new QTableWidgetItem(QIcon("data/bleuc.png"), ""));
        saPartie->ajoutLignePion(BleuCiel);
    }

    else if(sender() == sonBoutonMarron)
    {
        sonTableauInsert->setItem(sonIndexLigne, sonIndexColonne, new QTableWidgetItem(QIcon("data/noir.png"), ""));
        saPartie->ajoutLignePion(Marron);
    }

    else if(sender() == sonBoutonViolet)
    {
        sonTableauInsert->setItem(sonIndexLigne, sonIndexColonne, new QTableWidgetItem(QIcon("data/rose.png"), ""));
        saPartie->ajoutLignePion(Violet);
    }

    else if(sender() == sonBoutonJaune)
    {
        sonTableauInsert->setItem(sonIndexLigne, sonIndexColonne, new QTableWidgetItem(QIcon("data/jaune.png"), ""));
        saPartie->ajoutLignePion(Jaune);
    }

    sonIndexColonne++;

    ///////////////////////////////////////////////////
    ///////////////////////////////////////////////////
}

void PartieWindow::recupPionResultat()//BUG!!!! A Regler n'affiche pas bon résultat
{
    int unIndexColonneRes(0);
    std::map<int,Couleur>::iterator leIt;

    for(leIt = saMapRes->begin(); leIt != saMapRes->end(); leIt++)
    {
        if(leIt->first == unIndexColonneRes && leIt->second == Bleu)
        {
            sonTableauResFinal->setItem(0, unIndexColonneRes, new QTableWidgetItem(QIcon("data/bleuf.png"), ""));
        }

        else if(leIt->first == unIndexColonneRes && leIt->second == Rouge)
        {
            sonTableauResFinal->setItem(0, unIndexColonneRes, new QTableWidgetItem(QIcon("data/rouge.png"), ""));
        }

        else if(leIt->first == unIndexColonneRes && leIt->second == Vert)
        {
            sonTableauResFinal->setItem(0, unIndexColonneRes, new QTableWidgetItem(QIcon("data/vert1.png"), ""));
        }

        else if(leIt->first == unIndexColonneRes && leIt->second == Orange)
        {
            sonTableauResFinal->setItem(0, unIndexColonneRes, new QTableWidgetItem(QIcon("data/orange.png"), ""));
        }

        else if(leIt->first == unIndexColonneRes && leIt->second == BleuCiel)
        {
            sonTableauResFinal->setItem(0, unIndexColonneRes, new QTableWidgetItem(QIcon("data/bleuc.png"), ""));
        }

        else if(leIt->first == unIndexColonneRes && leIt->second == Marron)
        {
            sonTableauResFinal->setItem(0, unIndexColonneRes, new QTableWidgetItem(QIcon("data/noir.png"), ""));
        }

        else if(leIt->first == unIndexColonneRes && leIt->second == Violet)
        {
            sonTableauResFinal->setItem(0, unIndexColonneRes, new QTableWidgetItem(QIcon("data/rose.png"), ""));
        }

        else if(leIt->first == unIndexColonneRes && leIt->second == Jaune)
        {
            sonTableauResFinal->setItem(0, unIndexColonneRes, new QTableWidgetItem(QIcon("data/jaune.png"), ""));
        }
        unIndexColonneRes++;
    }

    std::map<int,Couleur>::iterator leIt1;
    for(leIt1 = saMapRes->begin(); leIt1 != saMapRes->end(); leIt1++)
    {
        saMapRes->erase(leIt1);
    }
}

void PartieWindow::compareTableau()
{
    sonBoutonVerif->hide();
    int leNombreDePionNoir(0);
    std::map<int,Couleur> * uneMapCompare = new std::map<int,Couleur>;
    uneMapCompare = saPartie->comparerResultat();
    std::map<int,Couleur>::iterator leItParcour;

    for(leItParcour = uneMapCompare->begin(); leItParcour != uneMapCompare->end(); leItParcour++)
    {
        if(leItParcour->second == Noir)
        {
            sonTableauCompare->setItem(sonIndexLigneCompare,sonIndexColonneCompare, new QTableWidgetItem(QIcon("data/pionNoir.png"), ""));
            leNombreDePionNoir++;
        }
        if(leItParcour->second == Blanc)
        {
            sonTableauCompare->setItem(sonIndexLigneCompare, sonIndexColonneCompare, new QTableWidgetItem(QIcon("data/pionBlanc.png"), ""));
        }

        sonIndexColonneCompare++;

        if(sonIndexColonneCompare >= 4)
        {
            sonIndexLigneCompare++;
            sonIndexColonneCompare = 0;
        }
    }

    ///////////////////Si tout juste (à la bonne place)///////////////
    ///////////////////Affichage du resultat final//////////////////////////

    if(leNombreDePionNoir == 4)
    {
        this->recupPionResultat();
        QMessageBox::information(this,"Winner","Vous avez gagné!");
        saPartie->ajoutScoreNom();
        saPartie->triScoresClassement();
        this->close();
        (parentWidget()->parentWidget())->show();
    }

    //////////////////////////////////////////////////////////////////
    ////////////////////Si fin de partie sans réponse juste///////////

    if(sonIndexLigneCompare == 10 && leNombreDePionNoir != 4)
    {
        this->recupPionResultat();
        QMessageBox::information(this,"Looser","Vous avez perdu! Dommage :p");
        this->close();
        (parentWidget()->parentWidget())->show();
    }

    //////////////////////////////////////////////////////////////////
    saPartie->eraseLignePion();
    saPartie->eraseLigneCompare();

    ///////////////////Condition pour saut de ligne//////////////////
    sonIndexLigne++;
    sonIndexColonne = 0;
}

void PartieWindow::deleteLigne()
{
    sonTableauInsert->removeRow(sonIndexLigne);
    sonTableauInsert->insertRow(sonIndexLigne);
    sonIndexColonne = 0;
    saPartie->eraseLignePion();
}
