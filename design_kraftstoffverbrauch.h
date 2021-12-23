#ifndef DESIGN_KRAFTSTOFFVERBRAUCH_H
#define DESIGN_KRAFTSTOFFVERBRAUCH_H

#include <QListView>
#include <QPainter>

class Design_Kraftstoffverbrauch : public QListView
{
public:
    Design_Kraftstoffverbrauch(QWidget* = nullptr);
    void paintEvent(QPaintEvent*);
};

#endif // DESIGN_KRAFTSTOFFVERBRAUCH_H
