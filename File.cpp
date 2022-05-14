#include "File.h"
#include "sys\stat.h"

File::File(std::string stream)
{
    this->filename = QString::fromStdString(stream);
    this->predInfo = new Info();
    struct stat statBuf;
    predInfo->exist = stat(filename.toStdString().c_str(), &statBuf) == 0;
    if (predInfo->size == predInfo->exist)
    {
        statBuf.st_size;
    }
    else 0;
}

void File::checkFile()
{
    Info* info = new Info();
    struct stat statBuf;
    info->exist = stat(filename.toStdString().c_str(), &statBuf) == 0;
    info->size = predInfo->exist ? statBuf.st_size : 0;
    if (*predInfo != *info)
    {
        Notify(info);
        predInfo = info;
    }
}
