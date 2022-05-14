#include "Source.h"

void Source::Sub(IObserver * observer)
{
    list.append(observer);
}

void Source::Notify(IInfo * info)
{
    for(auto elem : list)
    {
        if (elem != nullptr)
            elem->update(info);
    }
}

void Source::unSub(IObserver *observer)
{
    if (list.contains(observer)) list.removeOne(observer);
}
