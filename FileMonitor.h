#ifndef FILEMONITOR_H
#define FILEMONITOR_H
#include <iostream>
#include "Observable.h"
#include "FileObserver.h"

// класс источник
class FileMonitor : public Observable< FileObserver > {
private:
    std::string m_fileName;
    FileState m_prevFileState;
    static FileState getFileState (const std::string& fileName);
public:
    FileMonitor(const char* fileName);
    void checkFile();
};

#endif // FILEMONITOR_H
