#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H
#include "FileState.h"

class FileObserver {
public:
    virtual ~FileObserver() {}
    virtual void onFileChanged (const FileState& state) = 0;
};

#endif // FILEOBSERVER_H
