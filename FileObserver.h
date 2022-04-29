#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H
#include "FileState.h"
#include "Observable.h"

class FileObserver {
public:
    virtual ~FileObserver() {} // виртуальный деструктор (для дальнейшего наследования)
    virtual void onFileChanged (const FileState& state) = 0; // вируальная функция
};

#endif // FILEOBSERVER_H
