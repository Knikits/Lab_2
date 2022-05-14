#ifndef FILEMONITOR_H
#define FILEMONITOR_H
#include "IObserver.h"
#include <QString>

class Info : public IInfo
{
    bool operator==(const Info&);
    bool operator!=(const Info&);
    void operator=(const Info&);
    QString String() const;
    bool exist;
    int size;
};

class FileMonitor:public IObserver
{
public:
    void update(IInfo*);
};

#endif // FILEMONITOR_H
