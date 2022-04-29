#include "FileMonitor.h"

FileState FileMonitor::getFileState( const std::string& fileName ) {
    FileState fileState;
    struct stat statBuf;
    //exists

    //size
    fileState.size = fileState.exists ? statBuf.st_size : 0;
    return fileState;
}
