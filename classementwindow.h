#ifndef CLASSEMENTWINDOW_H
#define CLASSEMENTWINDOW_H

#include <QWidget>
#include <QDialog>
#include <QtGui>
#include <fstream>

class ClassementWindow : public QDialog
{
    Q_OBJECT
public:
    ClassementWindow(QWidget *parent = 0);
    virtual ~ClassementWindow();
    
signals:
    
public slots:
    void retourMenu();

private:
    QTableWidget * sonTableauClassement;
    QPushButton * sonBoutonMenu;
    QVBoxLayout * sonBoxClassement;
    
};

#endif // CLASSEMENTWINDOW_H
