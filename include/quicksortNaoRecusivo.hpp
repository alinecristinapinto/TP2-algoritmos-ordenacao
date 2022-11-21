#ifndef QUICKSORTNAORECURSIVO_H
#define QUICKSORTNAORECURSIVO_H

#include <iostream>
#include "pilha.hpp"
#include "registro.hpp"

using namespace std;

/**
 * @brief Classe que implementa o algoritmo de quicksort nao recursivo
 * Baseado no material da disciplina + https://www.geeksforgeeks.org/iterative-quick-sort/
*/
class QuickSortNaoRecursivo {
public:
    /**
     * @brief Ordena o vetor de forma crescente com quicksort nao recursivo
     * 
     * @param registros Vetor de registros
     * @param tamanho Tamanho do vetor
    */
    static void ordenarCrescente(Registro registros[], int tamanho);

private:
    /**
     * @brief Particiona o vetor de registros de forma crescente
     * 
     * @param registros Vetor de registros
     * @param indiceInicial Indice inicial do vetor
     * @param indiceFinal Indice final do vetor
     * @return int Indice do pivo
    */
    static int particionar(Registro registros[], int indiceInicial, int indiceFinal);
};

#endif
