#include "IObservable.h"

void IObservable::Sub(IObserver * observer)
{
    list.append(observer);
}

void IObservable::Notify(IInfo * info)
{
    for(auto elem : list)
    {
        if (elem != nullptr)
            elem->update(info);
    }
}

void IObservable::unSub(IObserver *observer)
{
    if (list.contains(observer))
        list.removeOne(observer);
}
