#ifndef FILE_H
#define FILE_H
#include "Source.h"
#include "FileMonitor.h"
#include <QList>

class File : public Source
{
private:
    Info* predInfo;
    QString filename;
public:
    File (std::string);
    void checkFile();
};

#endif // FILE_H
