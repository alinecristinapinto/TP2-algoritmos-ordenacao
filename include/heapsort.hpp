#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include "registro.hpp"
#include "desempenho.hpp"

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
     * @param desempenho Struct que armazena dados de desempenho do codigo
    */
    static void ordenarCrescente(Registro registros[], int tamanho, Desempenho *desempenho);

private:
    /**
     * @brief Empilha um no no heap a partir do indiceAtual como root
     * 
     * @param registros Vetor de registros
     * @param tamanho Tamanho do vetor
     * @param indiceAtual Indice atual do vetor
     * @param desempenho Struct que armazena dados de desempenho do codigo
    */
    static void empilharHeap(Registro registros[], int tamanho, int indiceAtual, Desempenho *desempenho);
    
    /**
     * @brief Funcao auxiliar para trocar o valor entre os vetores de registro
     * 
     * @param vetor1 Vetor de registros
     * @param vetor2 Vetor de registros
     * @param desempenho Struct que armazena dados de desempenho do codigo
    */
    static void trocar(Registro *vetor1, Registro *vetor2, Desempenho *desempenho);
};

#endif
