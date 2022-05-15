#include "FileMonitor.h"
#include <QDebug>

// реализация операторов

bool Info::operator==(const Info & info)
{
    return !(this->operator!=(info));
}

bool Info::operator!=(const Info & info)
{
    return !((info.exist & exist) && (size == info.size));
}

void Info::operator=(const Info & info)
{
    this->size = info.size;
    this->exist = info.exist;
}

// данные о файле записываются в виде строки (QString) в консоль

QString Info::String() const
{
    if (exist == true)
    {
        return QString("size - ") + QString::number(size) + QString(", exist - ") + QString("true");
    }
    else
    {
        return QString("size - ") + QString::number(size) + QString(", exist - ") + QString("false");
    }
}

// данные о том, что файл был изменён

void FileMonitor::update(IInfo* info)
{
    qDebug() << "Info about file:" << info->String();
}
