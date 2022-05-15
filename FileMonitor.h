#ifndef FILEMONITOR_H
#define FILEMONITOR_H
#include "IObserver.h"
#include <QString>

//Info - класс наследник класса IInfo, хранящий информацию о файле

class Info : public IInfo
{
public:
    bool operator==(const Info&); // оператор равно
    bool operator!=(const Info&); // оператор не равно
    void operator=(const Info&); // оператор присвоения
    QString String() const; // перевод полей в QString
    bool exist; // факт существования
    int size; // размер файла
};

//FileMonitor - класс наследник класса IObserver

class FileMonitor : public IObserver
{
public:
    void update(IInfo*); // обновление информации о файле
};

#endif // FILEMONITOR_H
