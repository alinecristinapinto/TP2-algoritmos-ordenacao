#ifndef QUICKSORTNAORECURSIVO_H
#define QUICKSORTNAORECURSIVO_H

#include <iostream>
#include "pilha.hpp"
#include "registro.hpp"
#include "desempenho.hpp"

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
     * @param desempenho Struct que armazena dados de desempenho do codigo
     * @return int Indice do pivo
    */
    static int particionar(Registro registros[], int indiceInicial, int indiceFinal, Desempenho *desempenho);
};

#endif
