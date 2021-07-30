#ifndef __NODE__H__
#define __NODE__H__

#include <iostream>

using namespace std;

template <typename T>
class Node;

template <typename T>
class Node
{
private:
    T value;
    Node<T> *next;
public:
    
    Node();
    Node(T);
    
    void setValue(T);
    void setNext(Node *);
    T& getValue();
    Node*getNext();

    ~Node() = default;
};

template <typename T>
Node<T>::Node(){
    value = {};
    this->next = nullptr;
}

template <typename T>
Node<T>::Node(T value_){
    this->value = value_;
    this->next = nullptr;
}

template <typename T>
void Node<T>::setValue(T value){
    this->value = value;
}

template <typename T>
void Node<T>::setNext(Node *next){
    this->next = next;
}

template <typename T>
T& Node<T>::getValue(){
    return value;
}

template <typename T>
Node<T>* Node<T>::getNext(){
    return this->next;
}

#endif