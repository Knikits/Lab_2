#include <iostream>
#include "ConsoleFileObserver.h"

using namespace std;

ConsoleFileObserver::~ConsoleFileObserver(){}

void ConsoleFileObserver::onFileChanged(const FileState &state) {
    cout << "Does the file exist and is not empty? " << endl;
    cout << "Exists: " << state.exists << endl;
    cout << "Size: " << state.size << endl;
}
