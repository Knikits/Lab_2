#ifndef SOURCE_H
#define SOURCE_H
#include "IObserver.h"
#include <QList>

class Source
{
private:
    QList<IObserver*> list;
public:
    virtual ~Source() {}
    virtual void Sub(IObserver*);
    virtual void Notify(IInfo*);
    virtual void unSub(IObserver*);
};

#endif // SOURCE_H
