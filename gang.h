#ifndef GANG_H
#define GANG_H

#include <QString>

class Gang
{
    // const QString gangstufe[7] {"N", "1", "2", "3", "4", "5", "R"};
    QString gang;

public:
    Gang();
    QString getGang();
    void setGang(QString g);
};

#endif // GANG_H
