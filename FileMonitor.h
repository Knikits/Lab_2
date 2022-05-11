#ifndef FILEMONITOR_H
#define FILEMONITOR_H
#include "IObserver.h"
#include <QString>
#include <QMetaEnum>

class Info : public IInfo
{
public:
    bool exist;
    int size;
    bool operator==(const Info&);
    bool operator!=(const Info&);
    void operator=(const Info&);
    QString String() const;
};

QString Info::String() const
{
    return exist ?
            QString("size: ") + QString::number(size) + "/n" + QString("existing: ") + QString("True")
          : QString("size: ") + QString::number(size) + "/n" + QString("existing: ") + QString("False");
}

class FileMonitor:public IObserver
{
public:
    void update(const Info&);
};

#endif // FILEMONITOR_H
