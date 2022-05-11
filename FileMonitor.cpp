#include "FileMonitor.h"
#include <QDebug>

void FileMonitor::update(const Info & info)
{
    qDebug() << "File changed" << info;
}
