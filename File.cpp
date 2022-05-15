#include "File.h"
#include "sys\stat.h"

File::File(std::string stream) // принимаем имя файла формата строки
{
    this->filename = QString::fromStdString(stream); // запоминает имя файла
    this->predInfo = new Info(); // запоминает исходное состояние
    struct stat statBuf; //специально использую #include "sys\stat.h" для запоминания инфы
    predInfo->exist = stat(filename.toStdString().c_str(), &statBuf) == 0; //далее узнаём характеристики файла
    if (predInfo->size == predInfo->exist)
    {
        statBuf.st_size;
    }
    else 0;
}

void File::checkFile() // вызывается в main
{
    Info* info = new Info();
    struct stat statBuf;
    info->exist = stat(filename.toStdString().c_str(), &statBuf) == 0;
    if (info->size == predInfo->exist)
    {
        statBuf.st_size;
    }
    else 0;
    if (*predInfo != *info) // если произошли изменения в файле
    {
        Notify(info); // то оповещвем
        predInfo = info; // новое состояние
    }
}
