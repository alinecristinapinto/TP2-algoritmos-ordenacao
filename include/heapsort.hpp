#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include "registro.hpp"

using namespace std;

/**
 * @brief Classe que implementa o algoritmo de heapsort
 * Baseado no material da disciplina + https://www.geeksforgeeks.org/heap-sort/
*/
class HeapSort {
public:
    /**
     * @brief Ordena o vetor de forma crescente com quicksort recursivo
     * 
     * @param registros Vetor de registros
     * @param tamanho Tamanho do vetor
    */
    static void ordenarCrescente(Registro registros[], int tamanho);

private:
    /**
     * @brief Empilha um no no heap a partir do indiceAtual como root
     * 
     * @param registros Vetor de registros
     * @param tamanho Tamanho do vetor
     * @param indiceAtual Indice atual do vetor
    */
    static void empilharHeap(Registro registros[], int tamanho, int indiceAtual);
    
    /**
     * @brief Funcao auxiliar para trocar o valor entre os vetores de registro
     * 
     * @param vetor1 Vetor de registros
     * @param vetor2 Vetor de registros
    */
    static void trocar(Registro *vetor1, Registro *vetor2);
};

#endif
