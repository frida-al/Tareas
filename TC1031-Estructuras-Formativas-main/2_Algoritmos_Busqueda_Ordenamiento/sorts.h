/*
* funciones.h
*
* Frida Arcadia Luna
* 04 de septiembre de 2024
*/

#ifndef SORTS_H
#define SORTS_H

#include <vector>

template <class T>
class Sorts{

    private: 
    void swap(std::vector<T> &vec, int i, int  j){
        T aux = vec[i];
	    vec[i] = vec[j];
	    vec[j] = aux;
    }

	void mergeSplit(std::vector<T> &vec, std::vector<T> &tmp, int low, int high) {
		int mid;

		if ( (high - low) < 1 ) {
			return;
		}
		mid = (high + low) / 2;
		mergeSplit(vec, tmp, low, mid);
		mergeSplit(vec, tmp, mid + 1, high);
		mergeArray(vec, tmp, low, mid, high);
		copyArray(vec, tmp, low, high);
	}
	
	void mergeArray(std::vector<T> &vec, std::vector<T> &tmp, int low, int mid, int high) {
		int i, j, k;

		i = low;
		j = mid + 1;
		k = low;

		while (i <= mid &&j <= high) {
			if (vec[i] < vec[j]) {
				tmp[k] = vec[i];
				i++;
			} else {
				tmp[k] = vec[j];
				j++;
			}
			k++;
		}
		if (i > mid) {
			for (; j <= high; j++) {
				tmp[k++] = vec[j];
			}
		} else {
			for (; i <= mid; i++) {
				tmp[k++] = vec[i];
			}
		}
	}
	void copyArray(std::vector<T> &vec, std::vector<T> &tmp, int low, int high) {
		for (int i = low; i <= high; i++) {
			vec[i] = tmp[i];
		}
	}

	int bs_aux(std::vector<T> &vec, int low, int high, int val) {
		while (low< high){
			int mid = (high + low) / 2;
			if (val == vec[mid]){
				return mid;
			}
			else if (vec[mid] < val){
				return bs_aux(vec, mid+1, high, val);
			}
			else if (vec[mid] > val){
				return bs_aux(vec, low, mid-1, val);
			}
		return low;
		}
		return -1;
	}

    public:
    void ordenaSeleccion(std::vector<T> &vec){
        for(int i = 0; i < vec.size(); i++){
			int min= vec.size()-1;
			for(int j = i; j < vec.size(); j++){
				if(vec[j]< vec[min]){
					min=j;
				}
			}
			if(min != i){
				swap(vec, i, min);
			}
		}
    }
    void ordenaBurbuja(std::vector<T> &vec){
        for(int i = vec.size() -1;i > 0; i-- ){
			for(int j = 0; j < i; j++){
				if(vec[j] > vec[j+1]){
					swap(vec, j, j+1);
				}
			}
		}
    }
	void ordenaMerge(std::vector<T> &vec){
	std::vector<T> tmp(vec.size());
	mergeSplit(vec, tmp, 0, vec.size() - 1);
	}

	
	
    int busqSecuencial(std::vector<T> &vec, int val){
		for (int i = 0; i <= vec.size(); i++){
			if (vec[i] == val){
				return i;
			}
		}
		return -1;
	}

    int busqBinaria(std::vector<T> &vec, int val){
		int size = vec.size();
		int low = 0;
		int high = size-1;
		bs_aux(vec, low, high, val);
	}
};

#endif