#ifndef IOBSERVER_H
#define IOBSERVER_H

class IInfo
{
public:
    virtual bool operator==(const IInfo&) = 0;
    virtual bool operator!=(const IInfo&) = 0;
    virtual void operator=(const IInfo&) = 0;
};

class IObserver
{
public:
    virtual ~IObserver() {}
    virtual void update(const IInfo&) = 0;
};

#endif // IOBSERVER_H
