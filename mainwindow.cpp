#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , fahrenp(new FahrenPKW(false, 0, 0, 12.8, 20975, "Alles gut."))
    , bremsep(new Bremse)
    , gangp(new Gang)
    , gaspedalp(new Gaspedal)
    , ui(new Ui::MainWindow)    
{
    ui->setupUi(this);
   // GESCHWINDIGKEIT MIT TIMER

//    QTimer *timer= new QTimer(this);
//    //connect(timer, &QTimer::timeout, this, &MainWindow::timer);
//    connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::update));
//    timer->start(1000);

}

//void MainWindow::timer()
//{
//    fahrenp->setGeschw(fahrenp->getGeschw() + 1);
//    qDebug()<<fahrenp->getGeschw() + 1;
//}

void MainWindow::keyPressEvent(QKeyEvent* e)
{
    qDebug() << "keyPressEvent()";
    // PKW Status auch stellen
    if (e->key() == Qt::Key_S)
    {
        fahrenp->startInit(bremsep, gangp, gaspedalp);
        //qDebug() << "start = true";
    }
    if (e->key() == Qt::Key_B)
    {
        bremsep->setBremse(true);
    }
    if (e->key() == Qt::Key_G)
    {
        gaspedalp->setGaspedal(true);
    }

    switch (e->key())
    {
    case Qt::Key_N:
        gangp->setGang("N");
        fahrenp->vorfahrenMitGang(gangp->getGang(), bremsep, gaspedalp, ui);
        break;
    case Qt::Key_1:
        gangp->setGang("1");
        // vorfahren
        fahrenp->vorfahrenMitGang(gangp->getGang(), bremsep, gaspedalp, ui);
        break;
    case Qt::Key_2:
        gangp->setGang("2");
        fahrenp->vorfahrenMitGang(gangp->getGang(), bremsep, gaspedalp, ui);
        break;
    case Qt::Key_3:
        gangp->setGang("3");
        fahrenp->vorfahrenMitGang(gangp->getGang(), bremsep, gaspedalp, ui);
        break;
    case Qt::Key_4:
        gangp->setGang("4");
        fahrenp->vorfahrenMitGang(gangp->getGang(), bremsep, gaspedalp, ui);
        break;
    case Qt::Key_5:
        gangp->setGang("5");
        fahrenp->vorfahrenMitGang(gangp->getGang(), bremsep, gaspedalp, ui);
        break;
    case Qt::Key_R:
        gangp->setGang("R");
        // rückfahren
        fahrenp->rueckFahren(gangp->getGang(), bremsep, gaspedalp, ui);
        break;
    default:
        gangp->setGang("1");
        fahrenp->vorfahrenMitGang(gangp->getGang(), bremsep, gaspedalp, ui);
        break;
    }

    //qDebug() << fahrenp->kraftstoffVerbrauch();

    fahrenp->setDisplayPKW(gangp->getGang(), bremsep->getBremse(), gaspedalp->getGaspedale(),
                           fahrenp->geschwErhoehen(gangp->getGang()),
                           fahrenp->kraftstoffVerbrauch(),
                           fahrenp->gesamtKilometerZahl(),
                           "Vorfahren mit Gang " + gangp->getGang(),
                           ui);

}

//void MainWindow::on_dial_valueChanged(int value)
//{
//    ui->lcdNumber_Geschw->display(value);
////    benutzerGeschwindigkeit = value;
//}

MainWindow::~MainWindow()
{
    delete ui;
    delete fahrenp;
    delete bremsep;
    delete gangp;
    delete gaspedalp;
}

