#ifndef IOBSERVER_H
#define IOBSERVER_H

class Info
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
    virtual void update(const Info&) = 0;
};

bool Info::operator==(const Info & info)
{
    return !(this->operator!=(info));
}

bool Info::operator!=(const Info& info)
{
    return !((info.exist & exist) && (size == info.size));
}

void Info::operator=(const Info& info)
{
    this->size = info.size;
    this->exist = info.exist;
}

#endif // IOBSERVER_H
