#ifndef FILE_H
#define FILE_H
#include "IObservable.h"
#include "FileMonitor.h"
#include <QList>

class File : public IObservable
{
private:
    Info* predInfo;
    QString filename;
public:
    File (std::string);
    void checkFile();
};

#endif // FILE_H
