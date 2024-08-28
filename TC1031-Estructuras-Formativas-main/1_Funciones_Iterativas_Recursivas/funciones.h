/*
* funciones.h
*
* Frida Arcadia Luna
* 13 de agosto de 2024
*/

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>

class Funciones{

    public:
    /*O(n) en cuanto a complejidad temporal, porque el ciclo se aumenta de 
    * forma lineal. O(1) en cuanto a complejidad espacial, porque no se ocupan
    * arreglos.
    */
    int sumaIterativa(int n){
        int acum=0;
        for (int i = 1; i <= n; i++){
            acum += i;
        }
        return acum;
    }

    /* O(n) en cuanto a complejidad temporal, porque si n es = 8, 
    * la recursión se realiza 8 veces. O(n) en cuanto a complejidad espacial, porque 
    * no se ocupan arreglos.
    */
    int sumaRecursiva(int n){
        if(n<=0){
            return 0;
        }
        else{
            return sumaRecursiva(n-1)+n;
        }

    }

    /* O(1) en cuanto a complejidad temporal, porque no hay ciclos, la instrucción
    * se realiza una vez. O(1) en cuanto a complejidad espacial, porque no se ocupan
    * arreglos.
    */
    int sumaDirecta(int n){
        if(n<=0)
            return 0;
        else{
            int sum = n * (n + 1) / 2;
            return sum;
        }
    }
};






#endif