#ifndef IOBSERVER_H
#define IOBSERVER_H
#include <QString>

//IInfo - класс (интерфейс), хранящий в себе абстрактную информацию

class IInfo
{
public:
    virtual QString String() const = 0; // переводит данные в QString
    virtual ~IInfo(){} // деструктор
};

//IObserver - класс (интерфейс) для класса наблюдателей

class IObserver
{
public:
    virtual void update(IInfo*) = 0; // обновление информации
    virtual ~IObserver() {} // деструктор
};

#endif // IOBSERVER_H
