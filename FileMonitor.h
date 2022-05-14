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

class FileMonitor:public IObserver
{
public:
    void update(const Info&);
};

#endif // FILEMONITOR_H
