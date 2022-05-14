#include "FileMonitor.h"
#include <QDebug>

void FileMonitor::update(const Info & info)
{
    qDebug() << "File changed" << info.String();
}

QString Info::String() const
{
    return exist ?
            QString("size: ") + QString::number(size) + "/n" + QString("existing: ") + QString("True")
          : QString("size: ") + QString::number(size) + "/n" + QString("existing: ") + QString("False");
}

