#ifndef IOBSERVER_H
#define IOBSERVER_H
#include <QString>

//IInfo - класс (интерфейс), хранящий в себе абстрактную информацию

class IInfo
{
public:
    virtual ~IInfo(){} // деструктор
    virtual QString String() const = 0; // переводит данные в QString
};

//IObserver - класс (интерфейс) для класса наблюдателей

class IObserver
{
public:
    virtual ~IObserver() {} // деструктор
    virtual void update(IInfo*) = 0; // обновление информации
};

#endif // IOBSERVER_H
