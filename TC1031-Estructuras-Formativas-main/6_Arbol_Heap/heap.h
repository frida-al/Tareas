/*
* heap.h
*
* Frida Arcadia Luna
* 28 de octubre de 2024
*/
#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <sstream>
#include <iostream>

template <class T>
class Heap {
private:
	T *data;
	unsigned int sizeVariable;
	unsigned int count;

	unsigned int parent(unsigned int pos) const {
        return (pos - 1) / 2;
    }
	unsigned int left(unsigned int pos) const {
        return ((2 * pos) + 1);
    }
	unsigned int right(unsigned int pos) const  {
        return ((2 * pos) + 2);
    }
	void heapify(unsigned int pos){
        unsigned int le = left(pos);
        unsigned int ri = right(pos);
        unsigned int min = pos;
        if (le <= count && data[le] < data[min]) {
            min = le;
        }
        if (ri <= count && data[ri] < data[min]) {
            min = ri;
        }
        if (min != pos) {
            swap(pos, min);
            heapify(min);
        }
    }
	void swap(unsigned int i, unsigned int j) {
        T aux = data[i];
        data[i] = data[j];
        data[j] = aux;
    }

public:
	Heap(unsigned int sze) {
        sizeVariable = sze;
        data = new T [sizeVariable];
        if (data == 0){
            std::cout << "Error";
        }
        count = 0;
    }

	~Heap() {
        delete [] data;
        data = 0;
        sizeVariable = 0;
        count = 0;
    }

	bool empty() const {
        return (count == 0);
    }
	bool full() const {
        return (count == sizeVariable);
    }
    void push(T val)  {
        unsigned int pos;
        if (full()) {
            std::cout << "Error";
        }

        pos = count;
        count++;
        while (pos > 0 && val < data[parent(pos)]) {
            data[pos] = data[parent(pos)];
            pos = parent(pos);
        }
        data[pos] = val;
    }
	void pop()  {
        if (empty()) {
            std::cout << "Error";
        }
        T aux = data[0];
        data[0] = data[--count];
        heapify(0);
    }
    int size(){
        return count;
    }
    int top(){
        return data[0];
    };
	std::string toString() const {
        std::stringstream aux;
        aux << "[";	for (unsigned int i = 0; i < count; i++) {
            if (i != 0) {
                aux << " ";
            } aux << data[i];
        } aux << "]";
        return aux.str();
    }
};

#endif