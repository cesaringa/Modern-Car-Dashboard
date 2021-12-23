#include "fahrenpkw.h"

FahrenPKW::FahrenPKW()
{

}

FahrenPKW::FahrenPKW(bool s, int g, int d, float k, int gk, QString sS)
    : motor(s),
      geschwindigkeit(g),
      drehzahl(d),
      kraftstoffverbrauch(k),
      gesamtkilometerzahl(gk),
      status(sS)
{

}

///   GESCHWINDIGKEIT MIT TIMER
///
//void FahrenPKW::setGeschw(int i)
//{
//    geschwindigkeit = i;
//}

bool FahrenPKW::getMotor()
{
    return motor;
}

void FahrenPKW::setMotor(bool s)
{
    motor = s;
}

int FahrenPKW::getGeschw()
{
    return geschwindigkeit;
}

int FahrenPKW::geschwErhoehen(QString g)
{
    if (g == "N")
    {
        geschwindigkeit = 0;
    } else if (g == "R")
    {
        geschwindigkeit = 10;
    }

    switch (g.toInt()) {
    case 1:
        geschwindigkeit = _DEFAUTGESCHW_1_;
        break;
    case 2:
        geschwindigkeit = _DEFAUTGESCHW_2_;
        break;
    case 3:
        geschwindigkeit = _DEFAUTGESCHW_3_;
        break;
    case 4:
        geschwindigkeit = _DEFAUTGESCHW_4_;
        break;
    case 5:
        geschwindigkeit = _DEFAUTGESCHW_5_;
        break;
    default:
        geschwindigkeit = 0;
        break;
    }

    return geschwindigkeit;
}

int FahrenPKW::geschwReduzieren()
{
    geschwindigkeit -= 10;
    return geschwindigkeit;
}

int FahrenPKW::getDefautGeschwMitGang(QString gang)
{
    int defautgeschw = 0;
    switch (gang.toInt()) {
    case 1:
        defautgeschw = _DEFAUTGESCHW_1_;
        break;
    case 2:
        defautgeschw = _DEFAUTGESCHW_2_;
        break;
    case 3:
        defautgeschw = _DEFAUTGESCHW_3_;
        break;
    case 4:
        defautgeschw = _DEFAUTGESCHW_4_;
        break;
    case 5:
        defautgeschw = _DEFAUTGESCHW_5_;
        break;
    default:
        defautgeschw = _DEFAUTGESCHW_DEFAULT_;
    }

    return defautgeschw;
}

int FahrenPKW::getDrehzahl()
{
    return drehzahl;
}

void FahrenPKW::drehzahlAendern(QString g)
{
    switch (g.toInt()) {
    case 1:
        drehzahl = _DREHZAHL_1_;
        break;
    case 2:
        drehzahl = _DREHZAHL_2_;
        break;
    case 3:
        drehzahl = _DREHZAHL_3_;
        break;
    case 4:
        drehzahl = _DREHZAHL_4_;
        break;
    case 5:
        drehzahl = _DREHZAHL_5_;
        break;
    default:
        drehzahl = _DREHZAHL_DEFAULT_;
    }
}

float FahrenPKW::getKraftS()
{
    return kraftstoffverbrauch;
}

int FahrenPKW::kraftstoffVerbrauch()
{
    kraftstoffverbrauch += 10;
    return kraftstoffverbrauch;
}

int FahrenPKW::getGesamtK()
{
    return gesamtkilometerzahl;
}

int FahrenPKW::gesamtKilometerZahl()
{
    gesamtkilometerzahl += 1;
    return gesamtkilometerzahl;
}

QString FahrenPKW::getStatus()
{
    return status;
}

void FahrenPKW::getStatus(QString s)
{
    status = s;
}

void FahrenPKW::bildRueckfahrZeigen()
{

}

void FahrenPKW::setDisplayPKW(QString gang, bool bremse, bool gas,
                              int g, float k, int gk, QString sS, Ui::MainWindow* ui)
{
    geschwindigkeit = g;

    drehzahlAendern(gang);

    status = sS;
    if (kraftstoffverbrauch >= 50)
    {
        ui->label_Warnung->setHidden(false);
        QPixmap pixmap(":/warning.png");
        ui->label_Warnung->setPixmap(pixmap);
        ui->label_Warnung->show();
//        ui->label_Info_Kraftstoff->setText(QString::number(kraftstoffverbrauch));
         ui->label_Info_Kraftstoff->setText("< 50%");
        if (kraftstoffverbrauch >= 100)
        {
        kraftstoffverbrauch = 100;
        ui->label_Info_Kraftstoff->setText("Leer!");
        ui->label_Info->setText("Kraftstoff leer!!!");
        }
    } else
    {
       kraftstoffverbrauch = k;
       ui->label_Info->setText(status);
    }

    gesamtkilometerzahl = gk;


    ui->label->setText(gang);
    ui->lcdNumber_Geschw->display(geschwindigkeit);
    ui->dial_Geschw->setValue(geschwindigkeit);
    ui->dial_Drehzahl->setValue(drehzahl);
    ui->dial_KraftstoffV->setValue(kraftstoffverbrauch);
    ui->lcdNumber_GesamtK->display(gesamtkilometerzahl);
    ui->lcdNumber_Kraftstoff->display(kraftstoffverbrauch);
    ui->lcdNumber_drehzahl->display(drehzahl);

    // 3 Status einstellen
    if (motor)
    {
        QPalette pe;
        pe.setColor(QPalette::WindowText, Qt::red);
        //ui->label_start->setPalette(pe);
    } else if (gas)
    {
        ;
    } else if (bremse)
    {
        ;
    }
}

void FahrenPKW::startInit(Bremse* b, Gang* g, Gaspedal* gas)
{
    motor = true;
    b->setBremse(true);
    g->setGang("1");
    gas->setGaspedal(false);
}

void FahrenPKW::rueckFahren(QString gang, Bremse* bremse, Gaspedal* gas, Ui::MainWindow* ui)
{
    // das Bild von Rueckfahren zeigen
    ui->label_Bild->setHidden(false);
    QPixmap pixmap(":/car@2x.png");
    ui->label_Bild->setPixmap(pixmap);
    ui->label_Bild->show();

    if (motor && !bremse->getBremse() && gas)
    {
        geschwErhoehen(gang);
        drehzahlAendern(gang);
        kraftstoffVerbrauch();
        gesamtKilometerZahl();
    }

    if (bremse->getBremse())
    {
        gas->setGaspedal(false);
        geschwReduzieren();

        if (geschwindigkeit <= 0)
        {
            status = "Bitte reduzieren Sie den Gang von ";
            status += gang + " zu " + QString::number(gang.toInt() - 1);
        }

        if (geschwindigkeit == 0)
        {
            motor = false;
            status = "Parken";
            return;
        } else if (kraftstoffverbrauch == 100)
        {
            status = "Kraftstoff leer!!!";
            return;
        }
    }

    if (kraftstoffverbrauch == 100)
    {
        motor = false;
        status = "Kraftstoff leer!!!";
        return;
    }
}

void FahrenPKW::vorfahrenMitGang(QString gang, Bremse* bremse, Gaspedal* gas, Ui::MainWindow* ui)
{
    ui->label_Bild->setHidden(true);
    // TODO
    // vorhergehende Gang

    if (motor && !bremse->getBremse() && gas)
    {
        geschwErhoehen(gang);
        drehzahlAendern(gang);
        kraftstoffVerbrauch();
        gesamtKilometerZahl();
    }

    if (bremse->getBremse())
    {
        gas->setGaspedal(false);
        geschwReduzieren();

        if (geschwindigkeit <= getDefautGeschwMitGang(gang))
        {
            status = "Bitte reduzieren Sie den Gang von ";
            status += gang + " zu " + QString::number(gang.toInt() - 1);
        }

        if (geschwindigkeit == 0)
        {
            motor = false;
            status = "Parken";;
            return;
        } else if (kraftstoffverbrauch == 100)
        {
            status = "Kraftstoff leer!!!";;
            return;
        }
    }

    if (gang == "5")
    {
        // TODO
        // QTime *time = new QTime();
        // time->currentTime();

        if (gas->getGaspedale() && !bremse->getBremse())
        {
            ;
            if (geschwindigkeit >= _MAXGESCHW_)
            {
                status = "Höchstgeschwindigkeit " + QString::number(_MAXGESCHW_) + " erreicht!";
            }
        }
    }

    if (kraftstoffverbrauch == 100)
    {
        motor = false;
        status = "Kraftstoff leer!!!";
        return;
    }

}






