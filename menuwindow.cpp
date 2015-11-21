#include "menuwindow.h"

MenuWindow::MenuWindow()
{
    sonBoutonJouer = new QPushButton();
    sonBoutonJouer->setCursor(Qt::PointingHandCursor);
    sonBoutonClassement = new QPushButton();
    sonBoutonClassement->setCursor(Qt::PointingHandCursor);
    sonBoutonQuitter = new QPushButton();
    sonBoutonQuitter->setCursor(Qt::PointingHandCursor);

    sonBoutonJouer->setMinimumSize(330,90);
    sonBoutonJouer->setFont(QFont("Times", 26, QFont::Bold));
    sonBoutonJouer->setFlat(true);

    sonBoutonClassement->setMinimumSize(330,70);
    sonBoutonClassement->setFont(QFont("Times", 26, QFont::Bold));
    sonBoutonClassement->setFlat(true);

    sonBoutonQuitter->setMinimumSize(330,70);
    sonBoutonQuitter->setFont(QFont("Times", 26, QFont::Bold));
    sonBoutonQuitter->setFlat(true);

    sonBoutonJouer->setStyleSheet("background-image : url(data/bouton_lancer_partie.png) ; border:none");
    sonBoutonClassement->setStyleSheet("background-image : url(data/bouton_score.png) ; border:none");
    sonBoutonQuitter->setStyleSheet("background-image : url(data/bouton_quitter.png) ; border:none");

    sonMenuBox = new QVBoxLayout();
    sonMenuBox->addWidget(sonBoutonJouer);
    sonMenuBox->addWidget(sonBoutonClassement);
    sonMenuBox->addWidget(sonBoutonQuitter);
    sonMenuBox->setAlignment(Qt::AlignCenter);

    setLayout(sonMenuBox);

    sonBoutonApropos = new QPushButton("A propos",this);
    sonBoutonApropos->setGeometry(20,650,90,40);

    setWindowTitle("Master-Mind");
    setGeometry(300,30,650,700);
    setFixedSize(QSize(650,700));
    setWindowIcon(QIcon("data/icone.png"));

    //////////////FOND D'ECRAN DE FENETRE//////////////
    ///////////////////////////////////////////////////

    QPalette pal = this->palette();
    pal.setBrush( this->backgroundRole(), QBrush( QPixmap( "data/background_menu.png" ) ) );
    this->setPalette( pal );

    ///////////////////////////////////////////////////
    ///////////////////////////////////////////////////


    QWidget::connect(sonBoutonJouer, SIGNAL(clicked()), this, SLOT(lancerPartie()));
    QWidget::connect(sonBoutonApropos, SIGNAL(clicked()), this, SLOT(afficherApropos()));
    QWidget::connect(sonBoutonClassement, SIGNAL(clicked()), this, SLOT(afficherClassement()));
    QWidget::connect(sonBoutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
}

MenuWindow::~MenuWindow()
{

}

void MenuWindow::lancerPartie()
{

    NiveauWindow *laFenetreNiveau = new NiveauWindow(this);
    laFenetreNiveau->setWindowModality(Qt::ApplicationModal);
    laFenetreNiveau->setFocus();
    laFenetreNiveau->show();
}

void MenuWindow::afficherApropos()
{
    AproposWindow * laFenetreApropos = new AproposWindow(this);
    laFenetreApropos->setFocus();
    laFenetreApropos->setWindowModality(Qt::ApplicationModal);
    laFenetreApropos->show();
}

void MenuWindow::afficherClassement()
{
    ClassementWindow * laFenetreClassement = new ClassementWindow(this);
    laFenetreClassement->setFocus();
    laFenetreClassement->setWindowModality(Qt::ApplicationModal);
    laFenetreClassement->show();
}
