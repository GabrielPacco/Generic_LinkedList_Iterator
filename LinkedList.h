#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"
#include "Iterator.h"
using namespace std;

template <typename T>
class LinkedList
{
private:
    int size;
    Node<T>* head;
    Node<T>* tail;
public:

    LinkedList();
    LinkedList(int, Node<T>*);

    void add_front(T);
    void add_back(T);
    void insertpos(T, int);
	void popFront();          
	void popBack(); 
    void remove(int);
    void print();


    ~LinkedList();

    // copy constructor
	LinkedList(LinkedList<T>& source);
	// copy move constructor
	LinkedList(LinkedList<T>&& source);
	// operador de asignación sobrecargado en copia
	LinkedList<T>& operator=( LinkedList<T>& source);
	// operador de movimiento de asignación sobrecargado en movimiento
	LinkedList<T>& operator=(LinkedList<T>&& source);

    //retorna el tamaño
    int count();

	// devuelve true si la lista está vacía
	bool empty() const;

    Iterator<T> begin();
    Iterator<T> end();
};


template <typename T>
LinkedList<T>::LinkedList():head (nullptr){
    tail = nullptr;
    size = 0;
}

template <typename T>
LinkedList<T>::LinkedList(int size_, Node<T>* head_){
    this->head = head_;
    this->size = size_;
}

template<typename T>
void LinkedList<T>::add_front(T value){
    Node<T>* new_node = new Node<T>(value);
    new_node->setNext(head);
    head=new_node;
    size++;
}

template <typename T>
void LinkedList<T>::add_back(T value){
    Node<T>* new_node = new Node<T>(value);
    Node<T>* aux=head;
    if(head==nullptr){
        head=new_node;
    }else{
        while(aux->getNext()!=nullptr){
            aux=aux->getNext();
        }
        aux->setNext(new_node);
    }
    size++;
}

template<typename T>
void LinkedList<T>::insertpos(T value,int pos){
    if(pos<size+1){
        Node<T> *newNode= new Node<T>(value);
        Node<T> *tmp =head;
        for (int i=0;i<=pos-2;i++){
            tmp=tmp->getNext();
        }
        newNode -> setNext(tmp->getNext() ); 
        tmp->setNext(newNode);
    }
    else{
        cout<<"Invalid Position\n";
    }
    size++;
}
// Elimina el nodo actual 'head' y luego hace que el nodo 'head' apunte al
// siguiente nodo de la lista. 
template <typename T>
void LinkedList<T>::popFront()
{
	if (empty()){
		cout<<"La lista esta vacia"<<endl;
	}
	Node<T>* actual = head;
	head = head->getNext();
	delete actual;
    size--;
}
template<typename T>
void LinkedList<T>::popBack()
{
    Node<T>* aux = head;
    Node<T>* copy = nullptr;
    while(aux->getNext() !=nullptr){
        copy=aux;
        aux=aux->getNext();
    }
    delete aux;
    copy->setNext(nullptr);
    size--;
}

template <typename T>
void LinkedList<T>::remove(int pos){
    Node<T> *aux = head;
    Node<T> *aux2;
    int i=1;
    if(aux != nullptr){
        if(pos == 1){
            head = aux->getNext();
        }
        else{
            while (i < pos && aux->getNext() != nullptr){
                aux2 = aux;
                aux = aux->getNext();
                i++;
            }
            aux2->setNext(aux->getNext());
        }
        delete aux;
    }
    size--;
}
// Recorre la lista e imprime cada elemento del nodo.
template <typename T>
void LinkedList<T>::print()
{
	Node<T>* tmp = head;
	while (tmp != nullptr)
	{
		cout << tmp->getValue() << endl;
		tmp = tmp->getNext();
	}
}

// destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
	Node <T>*aux=nullptr;
    while (head!=nullptr){
        aux=head;
        head=head->getNext();
        delete aux;
    }
}

//copy constructor
template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>& source)
{
	this->head=nullptr;
    this->size=0;
    Node<T>* aux = source.head;
    while(aux!=nullptr){
        this->add_back(aux->getValue());
        aux=aux->getNext();
        this->size++;
    }
}

//Move constructor
template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>&& source)
{
	this->~LinkedList();
	head = source.head;
}

// El Operador de Asignación sobrecargado
template <typename T>
LinkedList<T>& LinkedList<T>::operator=( LinkedList<T>& source)
{
	this->head=nullptr;
    this->size=0;
    Node<T>* aux = source.head;
    while(aux!=nullptr){
        this->add_back(aux->getValue());
        aux=aux->getNext();
        this->size++;
    }
}

// El Operador de Asignación de Movimiento sobrecargado
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& source)
{
	if (this == &source)
		return *this;

	this->~LinkedList();
	head = source.head;

	return *this;
}

// Devuelve true si la lista está vacía.
template <typename T>
bool LinkedList<T>::empty() const
{
	return head == nullptr;
}

// Se recorre la lista para contar cada elemento y luego se devuelve
// la cantidad.
template <typename T>
int LinkedList<T>::count()
{
	Node<T>* temp = head;
	int count = 0;
	while (temp != nullptr)
	{
		temp = temp->getNext();
		count++;
	}
	return count;
}

//Iterators
template <typename T>
Iterator<T> LinkedList<T>::begin()
{
    return Iterator<T>(head);
}
template <typename T>
Iterator<T> LinkedList<T>::end()
{
    return Iterator<T>(tail);
}
#endif