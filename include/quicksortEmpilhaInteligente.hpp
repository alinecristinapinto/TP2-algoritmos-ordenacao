#ifndef QUICKSORTEMPILHAINTELIGENTE_H
#define QUICKSORTEMPILHAINTELIGENTE_H

#include <iostream>
#include "pilha.hpp"
#include "registro.hpp"
#include "desempenho.hpp"

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
     * @param desempenho Struct que armazena dados de desempenho do codigo
    */
    static void ordenarCrescente(Registro registros[], int tamanho, Desempenho *desempenho);

private:
    /**
     * @brief Particiona o vetor de registros de forma crescente
     * 
     * @param registros Vetor de registros
     * @param indiceInicial Indice inicial do vetor
     * @param indiceFinal Indice final do vetor
     * @param indiceEsquerda Indice da esquerda do pivo
     * @param indiceDireita Indice da direita do pivo
     * @param desempenho Struct que armazena dados de desempenho do codigo
    */
    static void particionar(Registro registros[], int indiceInicial, int indiceFinal, int *indiceEsquerda, int *indiceDireita, Desempenho *desempenho);
};

#endif
