#include "FileMonitor.h"
#include <QDebug>

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

QString Info::String() const
{
    if (exist == true)
    {
        return QString("Size: ") + QString::number(size) + QString(" Exist: ") + QString("True");
    }
    else
    {
        return QString("Size: ") + QString::number(size) + QString(" Exist: ") + QString("False");
    }
}

void FileMonitor::update(IInfo* info)
{
    qDebug() << "File changed: " << info->String();
}
