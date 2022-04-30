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

#endif // IOBSERVER_H
