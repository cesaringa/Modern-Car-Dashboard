// TODO Beschreibung der Klasse

#ifndef FAHRENPKW_H
#define FAHRENPKW_H

#include <QString>
#include <QTime>
#include <QTimer>

#include "ui_mainwindow.h"
#include "bremse.h"
#include "gang.h"
#include "gaspedal.h"
#include "ui_mainwindow.h"

#define _DEFAUTGESCHW_DEFAULT_ 0
#define _DEFAUTGESCHW_1_ 10
#define _DEFAUTGESCHW_2_ 30
#define _DEFAUTGESCHW_3_ 50
#define _DEFAUTGESCHW_4_ 70
#define _DEFAUTGESCHW_5_ 100
#define _MAXGESCHW_ 220

#define _DREHZAHL_DEFAULT_ 0
#define _DREHZAHL_1_ 2500
#define _DREHZAHL_2_ 2000
#define _DREHZAHL_3_ 2000
#define _DREHZAHL_4_ 3000
#define _DREHZAHL_5_ 3500

class FahrenPKW
{
    bool motor = false;     // Staten oder Parken
    int geschwindigkeit = 0;
    int drehzahl = 0;
    // KraftstoffVerbrauch rechnet mit Prozent (0 - 100)%
    float kraftstoffverbrauch = 0.0;
    int gesamtkilometerzahl = 0;
    QString status = "Alles gut.";

    // TODO QTime vorhergehendzeit;

public:

    void timer();
    FahrenPKW();
    FahrenPKW(bool, int, int, float, int, QString);

    bool getMotor();
    void setMotor(bool);

    int getGeschw();
    void setGeschw(int);
    int geschwErhoehen(QString);
    int geschwReduzieren();
    int getDefautGeschwMitGang(QString);

    int getDrehzahl();
    void drehzahlAendern(QString);

    float getKraftS();
    int kraftstoffVerbrauch();

    int getGesamtK();
    int gesamtKilometerZahl();

    QString getStatus();
    void getStatus(QString);

    void bildRueckfahrZeigen();

    // Status von Dislay PKW einstellen
    // gang, bremse, gas, geschw, kraftstoffV, gesamtK, status, ui
    void setDisplayPKW(QString, bool, bool,
                       int, float, int, QString, Ui::MainWindow*);

    void startInit(Bremse*, Gang*, Gaspedal*);
    // void stop();     // TODO Status von Parken

    void rueckFahren(QString, Bremse*, Gaspedal*, Ui::MainWindow*);
    void vorfahrenMitGang(QString, Bremse*, Gaspedal*, Ui::MainWindow*);
};

#endif // FAHRENPKW_H
