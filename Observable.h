#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <set>
#include <vector>

using namespace std;

//тут класс который будет регистрировать изменения в классе Observer
template<class Observer>
class Observable {
private:
    struct ObserverRequest {
        void (Observable < Observer >::*operation) (Observer*);
        Observer* observer;
    };
    int m_count;
    set< Observer* > m_observers;
    vector< ObserverRequest > m_requests;
protected:
    Observable() : m_count(0) {}
    template< typename F, typename... Args >
    void notifyObservers( F f, Args... args ) {
        m_count++;
        for( Observer* o : m_observers) {
            ( o->*f ) (args... );
        };
        if (m_count == 0) {
            for( const ObserverRequest& r : m_requests ) {
                ( this->*r.operation )( r.observer );
            };
            m_requests.clean();
        }
    }
public:
    virtual ~Observable() {}
    void registerObserver (Observer* observer);
    void unregisterObserver (Observer* observer);
};

#endif // OBSERVABLE_H
