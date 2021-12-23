#ifndef DESIGN_GESCHWINDIGKEIT_H
#define DESIGN_GESCHWINDIGKEIT_H

#include <QListView>
#include <QPainter>


class Design_Geschwindigkeit : public QListView
{
public:
    Design_Geschwindigkeit(QWidget* = nullptr);
    void paintEvent(QPaintEvent*) override;
};

#endif // DESIGN_GESCHWINDIGKEIT_H
