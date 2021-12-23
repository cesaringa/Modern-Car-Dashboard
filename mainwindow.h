#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "bremse.h"
#include "fahrenpkw.h"
#include "gang.h"
#include "gaspedal.h"
#include "design_drehzahl.h"
#include "design_geschwindigkeit.h"
#include "design_kraftstoffverbrauch.h"
#include <QTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    FahrenPKW *fahrenp;
    Bremse *bremsep;
    Gang *gangp;
    Gaspedal *gaspedalp;

public:

    void timer();

    MainWindow(QWidget *parent = nullptr);
    //Tasten: S, (P?); N, 1 - 5, R; G; B
    void keyPressEvent(QKeyEvent*);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
