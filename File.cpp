#include "File.h"
#include "sys\stat.h"

File::File(std::string stream) // принимаем имя файла формата строки
{
    this->filename = QString::fromStdString(stream); // запоминает имя файла в виде QString
    this->predInfo = new Info(); // запоминает исходное состояние
    struct stat statBuf; //специально использую #include "sys\stat.h" для запоминания инфы
    predInfo->exist = stat(filename.toStdString().c_str(), &statBuf) == 0; // далее узнаём характеристики файла
    if (predInfo->exist == 0) // если файл не существует
    {
        predInfo->size = 0; // то размер нулевой
    }
    else predInfo->size = statBuf.st_size; // иначе узнаем размер файла и присваиваем
    Missingfile = 0;
}

void File::checkFile() // вызывается в main
{
    Info* info = new Info();
    struct stat statBuf; // использую #include "sys\stat.h" для запоминания инфы
    info->exist = stat(filename.toStdString().c_str(), &statBuf) == 0; // узнаем характеристики
    if (info->exist == 0) // если файл не существует
    {
        info->size = 0; // то размер нулевой
    }
    else info->size = statBuf.st_size; // иначе узнаем размер файла и присваиваем
    if (info->exist == 1) // если файл существует
    {
        if (*predInfo != *info) // если произошли изменения в файле
        {
            Notify(info); // то оповещаем
            predInfo = info; // новое состояние
            Missingfile = 0;
        }
    }
    else // иначе если не существует
    {
        if ((*predInfo != *info) && (Missingfile == 0)) // если произошли изменения в файле
        {
            Notify(info); // то оповещаем
            predInfo = info; // новое состояние
            Missingfile = 1;
        }
    }
}
