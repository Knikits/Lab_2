#ifndef IOBSERVABLE_H
#define IOBSERVABLE_H
#include "IObserver.h"
#include <QList>

//IObservable - класс родитель класса File
// абстракция для наблюдаемых классов

class IObservable
{
private:
    QList<IObserver*> list; // список наблюдателей
public:
    virtual ~IObservable() {} // виртуальный деструктор для очистки памяти
    virtual void Sub(IObserver*); // подписка наблюдателей
    virtual void Notify(IInfo*); // оповещение наблюд. об изменениях
    virtual void unSub(IObserver*); // отписка от наблюдения
};

#endif // IOBSERVABLE_H
