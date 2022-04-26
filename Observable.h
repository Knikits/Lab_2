#ifndef OBSERVABLE_H
#define OBSERVABLE_H

//тут класс который будет регистрировать изменения в классе Observer

class Observable {
private:
    int m_count;
protected:
    Observable() : m_count(0) {}
public:
    virtual ~Observable() {}
    void registerObserver () {}
    void unregisterObserver () {}
};

#endif // OBSERVABLE_H
