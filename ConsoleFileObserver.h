#ifndef CONSOLEFILEOBSERVER_H
#define CONSOLEFILEOBSERVER_H
#include "FileObserver.h"

// наследник класса FileObserver
class ConsoleFileObserver : public FileObserver {
public:
    ~ConsoleFileObserver();
    void onFileChanged (const FileState& state);
};

#endif // CONSOLEFILEOBSERVER_H
