#ifndef ITETATOR_H
#define ITETATOR_H
#include "LinkedList.h"

template <typename T>
class Iterator
{
private:
    Node<T> *Itr;

public:

    Iterator(Node<T> *ptr) : Itr(ptr) {}
    bool operator==(const Iterator &i);
    bool operator!=(const Iterator &i);
    T operator*();
    Iterator &operator++();
    Iterator operator++(int);

};

template <typename T>
bool Iterator<T>::operator==(const Iterator &i)
{
    return Itr == i.Itr;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator &i)
{
    return Itr != i.Itr;
}

template <typename T>
T Iterator<T>::operator*()
{
    return Itr->getValue();
}


template <typename T>
Iterator<T> &Iterator<T>::operator++()
{
    Itr = Itr->getNext();
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int)
{
    Iterator temp = *this;
    Itr = Itr->getNext();
    return temp;
}

#endif