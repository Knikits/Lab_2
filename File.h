#ifndef FILE_H
#define FILE_H
#include "IObservable.h"
#include "FileMonitor.h"
#include <QList>

//File - класс наследник класса IObservable, является наблюдаемым объектом

class File : public IObservable
{
private:
    Info* predInfo; // информация о файле
    QString filename; // имя файла
    bool Missingfile;
public:
    File (std::string); // для заполнения имени файла, за которым наблюдаем
    void checkFile(); // проверка файла
};

#endif // FILE_H
