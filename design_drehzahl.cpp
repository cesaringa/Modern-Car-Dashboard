#include "design_drehzahl.h"

Design_Drehzahl::Design_Drehzahl(QWidget* parent): QListView(parent)
{

}

void Design_Drehzahl::paintEvent(QPaintEvent *)
{

                QPainter painter(this->viewport());

                painter.fillRect(0, 0, width(), height(), "black");

                static const QPoint zeiger[3] = {
                    QPoint(7, 8),
                    QPoint(-7, 8),
                    QPoint(0, -70)
                };

                QColor zeigerFarbe(255, 0, 0, 127); //red wine
                QColor kreisFarbe ("#222");
                QColor indikatorFarbe_gross("white");

                int side = qMin(width(), height());

                painter.setRenderHint(QPainter::Antialiasing); //Add realism

                painter.translate(width() / 2, height() / 2);
                painter.scale(side / 200.0, side / 200.0);

                ///Design von Kreis
                QPen pen;
                pen.setWidth(8);
                pen.setBrush(kreisFarbe);
                painter.save();
                painter.setPen(pen);
               // painter.setBrush(kreisFarbe);
                //painter.save();
                painter.drawEllipse(-95,-95,190,190);
                painter.restore();

//                /// Design von Zeiger
//                painter.setPen(Qt::NoPen);
//                painter.setBrush(zeigerFarbe);
//                painter.save();

//                int testDrehZahl = 4000;
//                painter.rotate(180+18+36+36*testDrehZahl/1000);
//                painter.drawConvexPolygon(zeiger, 3);
//                painter.restore();

                /// Design von Indikator: grosse Linie
                painter.setPen(indikatorFarbe_gross);
                for (int i = 0; i < 10; ++i) {
                    if(!(i>1&&i<4))
                    painter.drawLine(92, 0, 96, 0);

                    painter.rotate(36.0);
                }
                painter.end();

}
