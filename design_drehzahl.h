#ifndef DESIGN_DREHZAHL_H
#define DESIGN_DREHZAHL_H

#include <QListView>
#include <QPainter>

class Design_Drehzahl : public QListView
{
public:
    Design_Drehzahl(QWidget* = nullptr);
    void paintEvent(QPaintEvent*);
};

#endif // DESIGN_DREHZAHL_H
