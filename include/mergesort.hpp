#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include "registro.hpp"

using namespace std;

/**
 * @brief Classe que implementa o algoritmo de mergesort
 * Baseado no material da disciplina + https://www.geeksforgeeks.org/merge-sort/
*/
class MergeSort {
public:
    /**
     * @brief Ordena o vetor de forma crescente com mergesort recursivo
     * 
     * @param registros Vetor de registros
     * @param tamanho Tamanho do vetor
    */
    static void ordenarCrescente(Registro registros[], int tamanho);

private:
    /**
     * @brief Unifica os dois subvetores criados em ordem crescente vetor[inicio..meio] e vetor[meio+1..final]
     * 
     * @param registros Vetor de registros
     * @param incdiceEsqueda Indice inicial do vetor
     * @param indiceMeio Indice do emio do vetor
     * @param indiceDireita Indice final do vetor
    */
    static void merge(Registro registros[], int const indiceEsquerda, int const indiceMeio, int const indiceDireita);
    
    /**
     * @brief Parte o vetor pela metade e em seguida unifica (merge)
     * 
     * @param registros Vetor de registros
     * @param indiceInicial Indice inicial do vetor
     * @param indiceFinal Indice final do vetor
    */
    static void mergeSort(Registro registros[], int indiceInicio, int indiceFim);
};

#endif
