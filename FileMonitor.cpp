#include "FileMonitor.h"
#include <QDebug>

// реализация операторов

bool Info::operator!=(const Info & info) // оператор не равно
{
    return !((info.exist & exist) && (size == info.size));
}

void Info::operator=(const Info & info) // оператор присвоения
{
    this->size = info.size;
    this->exist = info.exist;
}

// данные о файле записываются в виде строки (QString) в консоль

QString Info::String() const
{
    if (exist == true) // если файл существует
    {
        return QString("File exists, ") + QString("size - ") + QString::number(size);
    }
    else // если не существует
    {
        return QString("File doesn't exist");
    }
}

// данные о том, что файл был изменён

void FileMonitor::update(IInfo* info)
{
    qDebug() << info->String();
}
