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
    return exist ?
            QString("size: ") + QString::number(size) + "/n" + QString("existing: ") + QString("True")
          : QString("size: ") + QString::number(size) + "/n" + QString("existing: ") + QString("False");
}

void FileMonitor::update(const IInfo & info)
{
    qDebug() << "File changed" << info.String();
}
