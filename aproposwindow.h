#ifndef APROPOSWINDOW_H
#define APROPOSWINDOW_H

#include <QWidget>
#include <QtGui>


class AproposWindow : public QDialog
{
    Q_OBJECT

private:
    QLabel * sonTexte;
    QPushButton * sonBoutonMenu;
    QVBoxLayout * sonVBox;

public:
    AproposWindow(QWidget *parent = 0);
    ~AproposWindow();

public slots :
    void retourMenu();
};

#endif // APROPOSWINDOW_H
