#include "IObservable.h"

//реализация методов

//Подписка

void IObservable::Sub(IObserver * observer) //принимает указатель на подписчика
{
    list.append(observer); // подписываем его (добавляем в список наблюдптелей)
}

//Оповещение

void IObservable::Notify(IInfo * info) // принимает Info для определения изменения файла
{
    for (auto elem : list) // проходимся по всем наблюдателям
    {
        if (elem != nullptr) // если наблюдатель существует
            elem->update(info);  // то выполняется метод обновления информации о файле
    }
}

//Отписка

void IObservable::unSub(IObserver *observer) //принимает указатель на подписчика
{
    if (list.contains(observer)) // если есть такой подписчик
        list.removeOne(observer); // то удаляем одного наблюдателя из списка подписчиков
}
