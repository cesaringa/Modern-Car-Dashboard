#include "design_geschwindigkeit.h"

Design_Geschwindigkeit::Design_Geschwindigkeit(QWidget* parent): QListView(parent)
{

}

void Design_Geschwindigkeit::paintEvent(QPaintEvent *)
{
    //FahrenPkw dFahrenPkw;
    //dgeschwindigkeit = dFahrenPkw.getGeschw();

    //qDebug()<<dFahrenPkw.getGeschw();

                QPainter painter(this->viewport());

                painter.fillRect(0, 0, width(), height(), "black");

                static const QPoint zeiger[3] = {
                    QPoint(7, 8),
                    QPoint(-7, 8),
                    QPoint(0, -70)
                };

                QColor zeigerFarbe(255, 0, 0, 127); //red wine
                QColor indikatorFarbe_klein("gray"); //255, 0, 0, 127
                QColor indikatorFarbe_gross("blue");
                QColor kreisFarbe ("#222");

                int side = qMin(width(), height());

                painter.setRenderHint(QPainter::Antialiasing); //Add realism

                painter.translate(width() / 2, height() / 2);
                painter.scale(side / 200.0, side / 200.0);

                ///Design von Kreis
                QPen pen;
                pen.setWidth(1);
                pen.setBrush(kreisFarbe);
                painter.save();
                painter.setPen(pen);
                painter.drawEllipse(-95,-95,190,190);
                painter.restore();

//                // Design von Zeiger
//                painter.setPen(Qt::NoPen);
//                painter.setBrush(zeigerFarbe);
//                painter.save();

//                // rotate
//                int testvalue = 100;
//                painter.rotate(testvalue+230);
////              painter.rotate(testvalue+230);
//                painter.drawConvexPolygon(zeiger, 3);
//                painter.restore();

//                for (int k = 0; k<testvalue;++k)
//                {
//                    int n = testvalue+k;
//                    painter.rotate(n);
//                    painter.drawConvexPolygon(zeiger, 3);
//                    painter.restore();
//                }

                painter.save();

                /// Design von Indikator: grosse Linie
                painter.setPen(indikatorFarbe_gross);
                for (int i = 0; i < 36; ++i) {
                    if(!(i>4&&i<14))
                    painter.drawLine(88, 0, 96, 0);
                    painter.rotate(10.0);
                }

                /// Design von Indikator: kleine Linie
                painter.restore();
                painter.setPen(indikatorFarbe_klein);

                for (int j = 0; j < 180; ++j) {
                    if(!(j>20&&j<70))
                    {
                    if ((j % 5) != 0)
                    painter.drawLine(92, 0, 96, 0);
                    }
                    painter.rotate(2.0);
                }
                painter.end();
}
