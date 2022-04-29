#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <set>
#include <vector>

using namespace std;

// тут класс который будет регистрировать изменения в классе Observer
// observable - шаблонный класс
template<class Observer>
class Observable {
private:
    struct ObserverRequest {
        void (Observable < Observer >::*operation) (Observer*); // струтура запросов
        Observer* observer;
    };
    int m_count; //счёткик входа в цикл
    set< Observer* > m_observers; // observer хранит указатели (для прдотвращения создания дубл. связей)
    vector< ObserverRequest > m_requests; // вектор хранения запросов
protected:
    Observable() : m_count(0) {}
    template< typename F, typename... Args > // шаблон с переменным числом параметров
    void notifyObservers( F head, Args... args ) { // функция уведомления наблюдателей
        m_count++;
        for( Observer* o : m_observers) {
            ( o->*head ) (args... ); //проходим по множеству указателей и вызываем для них функцию-член head с args
        };
        m_count--;
        if (m_count == 0) { // если счётчик равен нулю, то
            for( const ObserverRequest& r : m_requests ) { // проходим по всем завпросам
                ( this->*r.operation )( r.observer ); // которые могли посутпить и добавить или убрать наблюдателя
            };
            m_requests.clear(); // очищаем вектор
        }
    }
public:
    virtual ~Observable() {} // виртуальный деструктор (для дальнейшего наследования)
    void registerObserver (Observer* observer); // создание связи с наблюдателем
    void unregisterObserver (Observer* observer); // прекращение связи с наблюдателем
};

template<class Observer>
void Observable<Observer>::registerObserver (Observer* observer) {
    if (m_count != 0) {
        // запрос на добавление наблюдателя
        m_requests.push_back(ObserverRequest {&Observable< Observer >::registerObserver, observer});}
    else if (observer) {
        m_observers.insert(observer);
    }
}

template<class Observer>
void Observable<Observer>::unregisterObserver (Observer* observer) {
    if (m_count != 0) {
        // запрос на удаление наблюдателя
        m_requests.push_back(ObserverRequest {&Observable< Observer >::unregisterObserver, observer});}
    else if (observer) {
        m_observers.erase(observer);
    }
}

#endif // OBSERVABLE_H
