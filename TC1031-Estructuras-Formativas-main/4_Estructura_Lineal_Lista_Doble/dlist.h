/*
* dlist.h
*
* Frida Arcadia Luna
* 23 de septiembre de 2024
*/

#ifndef DLIST_H
#define DLIST_H

#include <string>
#include <sstream>

template <class T> class DList;
template <class T> class ListIterator;

template <class T> 
class Node{

   private:
Node<T>(T val) : value(val), previous(0), next(0) {}
    Node<T>(T val, Node * nxt, Node *prev) : value(val), previous(prev), next(nxt) {}
    Node<T>(const Node <T> &source)  : value(source.value), previous(source.prev), next(source.next) {}
    T	    value;
	Node<T> *next;
    Node<T> *previous;

	friend class DList<T>;
};

template <class T>
class DList {

    private:
    Node<T> *head;
    Node<T> *tail;
	int 	size;
	friend class ListIterator<T>;

    public:
    DList() : head(0), tail(0), size(0) {}
    ~DList() {
	    clear();
        }
    bool empty() const {
	return (head == 0 && tail == 0);
    }
    void clear() {
        Node<T> *p, *q;

        p = head;
        while (p != 0) {
            q = p->next;
            delete p;
            p = q;
        }
        head = 0;
        tail = 0;
        size = 0;
    }

    std::string toStringForward() const {
        std::stringstream aux;
        Node<T> *p;

        p = head;
        aux << "[";
        while (p != 0) {
            aux << p->value;
            if (p->next != 0) {
                aux << ", ";
            }
            p = p->next;
        }
        aux << "]";
        return aux.str();
    }

    std::string toStringBackward() const {
        std::stringstream aux;
        Node<T> *p;

        p = tail;
        aux << "[";
        while (p != 0) {
            aux << p->value;
            if (p->previous != 0) {
                aux << ", ";
            }
            p = p->previous;
        }
        aux << "]";
        return aux.str();
    }

    void insertion(T val){
        Node<T> *newNode, *p;
        newNode = new Node<T>(val);
        if (empty()){
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next= newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        size++;
    }

    T search(T val){
        int cont = 0;
        Node<T> *p = head;
        while (p != nullptr && p->value != val) {
        p = p->next;
        cont++;
        }
        if (p == nullptr) { 
            return -1;
        } 
        else {
            return cont;
        }     
    }

    void update(int index, T val){
        int cont = 0;
        Node<T> *p = head;
        while (cont != index){
            p = p-> next;
            cont++;
            if (cont == index){
                p->value = val;
            }
        }      
    }

    void deleteAt(int index){
    Node<T> *p,*q;
    p=head;
    int cont=0;
    if(index==0){
        p=p->next;
        p->previous=0;
        delete head;
        head=p;
    }
    else if(index==size){
        p=tail;
        q=p->previous;
        q->next=0;
        delete p;
        tail=q;
    }
    else{
        while(cont != index){
            p=p->next;
            cont++;
        }
        q=p->next;
        q->previous=p->previous;
        p->previous->next=q;
        delete p;
    }
    size--;
}
};

#endif