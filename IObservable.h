#ifndef IOBSERVABLE_H
#define IOBSERVABLE_H
#include "IObserver.h"
#include <QList>

class IObservable
{
private:
    QList<IObserver*> list;
public:
    virtual ~IObservable() {}
    virtual void Sub(IObserver*);
    virtual void Notify(IInfo*);
    virtual void unSub(IObserver*);
};

#endif // IOBSERVABLE_H
