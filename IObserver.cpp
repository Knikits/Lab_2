#include "IObserver.h"

bool Info::operator==(const Info & info)
{
    return !(this->operator!=(info));
}

bool Info::operator!=(const Info& info)
{
    return !((info.exist & exist) && (size == info.size));
}

void Info::operator=(const Info& info)
{
    this->size = info.size;
    this->exist = info.exist;
}
