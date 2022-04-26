#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <set>
#include <vector>

//тут класс который будет регистрировать изменения в классе Observer
template<class Observer>
class Observable {
private:
    struct ObserverRequest {
        void (Observable < Observer >::*operation) (Observer*);
        Observer* observer;
    };
    int m_count;
protected:
    Observable() : m_count(0) {}
public:
    virtual ~Observable() {}
    void registerObserver () {}
    void unregisterObserver () {}
};

#endif // OBSERVABLE_H
