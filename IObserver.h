#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <QString>

class IInfo
{
public:
    virtual ~IInfo(){}
    virtual QString String() const = 0;
};


class IObserver
{
public:
    virtual ~IObserver() {}
    virtual void update(IInfo*) = 0;
};

#endif // IOBSERVER_H
