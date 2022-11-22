#ifndef QUICKSORTEMPILHAINTELIGENTE_H
#define QUICKSORTEMPILHAINTELIGENTE_H

#include <iostream>
#include "pilha.hpp"
#include "registro.hpp"

using namespace std;

/**
 * @brief Classe que implementa o algoritmo de quicksort empilha inteligente 
 * Baseado no material da disciplina 
*/
class QuickSortEmpilhaInteligente {
public:
    /**
     * @brief Ordena o vetor de forma crescente com quicksort empilha inteligente 
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
     * @param indiceEsquerda Indice da esquerda do pivo
     * @param indiceDireita Indice da direita do pivo
    */
    static void particionar(Registro registros[], int indiceInicial, int indiceFinal, int *indiceEsquerda, int *indiceDireita);
};

#endif
