#include "design_kraftstoffverbrauch.h"

Design_Kraftstoffverbrauch::Design_Kraftstoffverbrauch(QWidget* parent): QListView(parent)
{

}

void Design_Kraftstoffverbrauch::paintEvent(QPaintEvent *)
{
                QPainter painter(this->viewport());

                painter.fillRect(0, 0, width(), height(), "black");

                static const QPoint zeiger[3] = {
                    QPoint(7, 8),
                    QPoint(-7, 8),
                    QPoint(0, -70)
                };

                QColor indikatorFarbe_gross("white"); //255, 0, 0, 127
                QColor zeigerFarbe(255, 0, 0, 127);

                int side = qMin(width(), height());

                painter.setRenderHint(QPainter::Antialiasing); //Add realism

                painter.translate(width() / 2, height() / 2);
                painter.scale(side / 200.0, side / 200.0);

//                /// Design von Zeiger
//                painter.setPen(Qt::NoPen);
//                painter.setBrush(zeigerFarbe);
//                painter.save();
//                painter.drawConvexPolygon(zeiger, 3);
//                painter.restore();

                /// Design von Indikator: grosse Linie
                painter.setPen(indikatorFarbe_gross);
                for (int i = 0; i < 12; i++) {
                    if((i>6&&i<12))
                    painter.drawLine(88, 0, 96, 0);

                    painter.rotate(30.0);
                }


                painter.end();
}
