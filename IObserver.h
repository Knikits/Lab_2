#ifndef IOBSERVER_H
#define IOBSERVER_H

class IInfo
{
public:
    virtual bool operator==(const IInfo&) = 0;
    virtual bool operator!=(const IInfo&) = 0;
    virtual void operator=(const IInfo&) = 0;
};

class Info : public IInfo //надо перенести в другой файл (монитор)
{
public:
    bool exist;
    int size;
    bool operator==(const Info&);
    bool operator!=(const Info&);
    void operator=(const Info&);
};

class IObserver
{
public:
    virtual ~IObserver() {}
    virtual void update(const IInfo&) = 0;
};

#endif // IOBSERVER_H
